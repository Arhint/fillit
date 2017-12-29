/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:56:12 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/27 16:29:21 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validation(char *str)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	j = count % 5;
	if (j == 4)
		return (1);
	return (0);
}

int		valid_ph(char *str)
{
	int	i;
	int	count_hash;
	int	count_point;

	count_point = 0;
	count_hash = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#' && str[i + 1] == '#' && str[i + 5] == '#')
			count_hash += 2;
		else if (str[i] == '#' && str[i + 1] == '#')
			count_hash++;
		else if (str[i] == '#' && str[i + 5] == '#')
			count_hash++;
		else if (str[i] == '.')
			count_point++;
		i++;
	}
	if ((count_hash == 3 || count_hash == 4) && count_point == 12)
		return (1);
	return (0);
}
