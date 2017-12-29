/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:14:47 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/27 16:36:34 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_placement(char **board, int *x, int *y, int board_size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (x[i] >= board_size || y[i] >= board_size)
			return (0);
		if (board[x[i]][y[i]] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	set_tertimino_on_board(char **board, int *x, int *y, char c)
{
	int i;

	i = 0;
	while (i < 4)
	{
		board[x[i]][y[i]] = c;
		i++;
	}
}

void	unset_tertimino_on_board(char **board, int board_size, t_lst *begin)
{
	int		i;
	int		j;

	i = 0;
	while (i < board_size)
	{
		j = 0;
		while (j < board_size)
		{
			if (board[i][j] == begin->l)
				board[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		solve(t_lst *begin, char **board, int board_size)
{
	int x;
	int y;

	if (!begin->next)
		return (1);
	x = 0;
	while (x < board_size)
	{
		y = 0;
		while (y < board_size)
		{
			move_dependence(begin, x, y);
			if (check_placement(board, begin->x, begin->y, board_size))
			{
				set_tertimino_on_board(board, begin->x, begin->y, begin->l);
				if (solve(begin->next, board, board_size))
					return (1);
				else
					unset_tertimino_on_board(board, board_size, begin);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	real_solver(t_lst *begin, int board_size)
{
	char **brd;

	brd = create_board(board_size);
	while (!(solve(begin, brd, board_size)))
	{
		free_board(brd, board_size);
		board_size++;
		brd = create_board(board_size);
	}
	print_board(brd, board_size);
	free_board(brd, board_size);
}
