/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:56:12 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/27 16:43:49 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

int		ft_sqrt(int nb)
{
	int left;
	int right;
	int mid;

	right = 46340;
	left = 0;
	while (1)
	{
		mid = (left + right) / 2;
		if (mid * mid == nb)
			return (mid);
		if (mid * mid < nb)
			left = mid + 1;
		if (mid * mid > nb)
			right = mid - 1;
		if (left > right)
			return (0);
	}
}

char	*ft_strndup(const char *src, size_t n)
{
	char		*dup;
	size_t		len;

	len = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	ft_strncpy(dup, src, n);
	return (dup);
}

void	free_board(char **board, int board_size)
{
	int i;

	i = 0;
	while (i < board_size)
	{
		free(board[i]);
		board[i] = NULL;
		i++;
	}
	free(board);
	board = NULL;
}
