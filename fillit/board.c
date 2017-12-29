/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:00:36 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/29 15:01:50 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_board_size(char *str)
{
	int board_size;

	board_size = num_tetriminos_str(str);
	board_size *= 4;
	while (ft_sqrt(board_size) == 0)
		board_size++;
	return (ft_sqrt(board_size));
}

char	**create_board(int board_size)
{
	char	**board;
	int		a;
	int		b;

	a = 0;
	board = (char **)malloc(sizeof(char *) * (board_size + 1));
	if (board == NULL)
		return (NULL);
	while (a < board_size)
	{
		board[a] = (char *)malloc(sizeof(char) * (board_size + 1));
		b = 0;
		while (b < board_size)
		{
			board[a][b] = '.';
			b++;
		}
		board[a][b] = '\0';
		a++;
	}
	board[a] = 0;
	return (board);
}

void	print_board(char **board, int board_size)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < board_size)
	{
		b = 0;
		while (b < board_size)
		{
			write(1, &board[a][b], 1);
			b++;
		}
		write(1, "\n", 1);
		a++;
	}
}

int		num_tetriminos_str(char *str)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (!(i % 21))
		{
			num++;
			if (num > 26)
				error();
		}
		i++;
	}
	return (num);
}
