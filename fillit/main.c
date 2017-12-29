/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:56:12 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/27 16:35:39 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		num_tetriminos(char *str)
{
	int		num;
	int		fd;
	int		ret;
	char	buff[21];

	num = 0;
	fd = 1;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		error();
	ret = read(fd, buff, 21);
	while (ret)
	{
		ret = read(fd, buff, 21);
		num++;
	}
	close(fd);
	return (num);
}

char	*file_to_buffer(char *str)
{
	int		ret;
	int		fd;
	char	*buffer;
	int		i;
	char	buf[1];

	i = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		error();
	buffer = (char*)malloc(sizeof(char) * (num_tetriminos(str) * 21));
	if (buffer == NULL)
		return (NULL);
	while ((ret = read(fd, buf, 1)))
	{
		buffer[i] = buf[0];
		i++;
	}
	buffer[i] = '\0';
	if ((close(fd)) == -1)
		error();
	if (!validation(buffer))
		error();
	return (buffer);
}

t_lst	*set_valid_list(char *str)
{
	t_lst	*tmp;
	t_lst	*begin;
	char	c;
	int		i;
	int		k;

	k = 0;
	c = 65;
	i = num_tetriminos_str(str);
	if (!(begin = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	tmp = begin;
	while (i-- > 0)
	{
		tmp->content = ft_strndup(&str[k], 20);
		if (!(valid_ph(tmp->content)))
			error();
		tmp->l = c++;
		k = k + 21;
		if (!(tmp->next = (t_lst *)malloc(sizeof(t_lst))))
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (begin);
}

int		main(int argc, char **argv)
{
	char	*s;
	t_lst	*begin;
	int		board_size;

	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (0);
	}
	s = file_to_buffer(argv[1]);
	begin = set_valid_list(s);
	begin = get_coord(begin);
	board_size = get_board_size(s);
	real_solver(begin, board_size);
	return (0);
}
