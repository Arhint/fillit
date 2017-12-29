/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:04:04 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/27 16:25:14 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst	*get_coord(t_lst *begin)
{
	t_lst	*tmp;
	int		i;
	int		j;

	tmp = begin;
	while (tmp->next)
	{
		i = 0;
		j = 0;
		while (j < 20)
		{
			if (tmp->content[j] == '#')
			{
				tmp->x[i] = j / 5;
				tmp->y[i] = j % 5;
				i++;
			}
			j++;
		}
		tmp = tmp->next;
	}
	return (begin);
}

void	move_dependence(t_lst *begin, int a, int b)
{
	int	i;

	i = 0;
	a = a - begin->x[i];
	b = b - begin->y[i];
	while (i < 4)
	{
		begin->x[i] = begin->x[i] + a;
		begin->y[i] = begin->y[i] + b;
		i++;
	}
}
