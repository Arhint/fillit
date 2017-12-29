/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:12:02 by ssavchen          #+#    #+#             */
/*   Updated: 2017/11/27 16:42:41 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_lst
{
	char			*content;
	char			l;
	int				x[4];
	int				y[4];
	struct s_lst	*next;
}					t_lst;

int					get_board_size(char *str);
int					num_tetriminos(char *str);
char				*file_to_buffer(char *str);
t_lst				*set_valid_list(char *str);
int					check_placement(char **board, int *x, int *y,
	int board_size);
char				*ft_strndup(const char *src, size_t n);
void				real_solver(t_lst *begin, int board_size);
int					num_tetriminos_str(char *str);
int					is_valid(char *str);
t_lst				*get_coord(t_lst *begin);
char				**create_board(int board_size);
void				print_board(char **board, int board_size);
void				move_dependence(t_lst *begin, int a, int b);
int					solve(t_lst *begin, char **board, int board_size);
void				error();
void				free_board(char **board, int board_size);
void				set_tertimino_on_board(char **board, int *x,
	int *y, char c);
void				unset_tertimino_on_board(char **board,
	int board_size, t_lst *begin);
int					validation(char	*str);
int					valid_ph(char *str);
int					ft_sqrt(int nb);

#endif
