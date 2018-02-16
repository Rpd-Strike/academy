/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpuscasu <fpuscasu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:32:02 by aldonder          #+#    #+#             */
/*   Updated: 2018/02/06 16:49:39 by aldonder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include "debug.h" /// de scos

# define my_abs(x) ((x) < 0 ? -(x) : (x))

typedef struct	s_tetris
{
	int t[4][4];
}				t_tetris;

typedef	struct	s_point
{
	int x, y;
}				t_point;

typedef struct	s_tetrimino
{
	t_point coord[4];
}				t_tetrimino;

int         	legal_char(char *str, int size);
void        	place_tetrimino(char *str, t_tetris *tet);
void        	flood_fill(int x, int y, t_tetris t, int viz[][4]);
void        	make_zero(int mat[][4]);
int         	check_tetrimino(t_tetris t);
void        	ft_memdel(void **ap);
t_tetrimino 	coordonate (t_tetris t);
int         	**make_matrix(int size);
void        	free_matrix(int **matrix, int size);
int         	high_sqrt(int a);
int         	ft_height(t_tetris t);
int         	ft_width(t_tetris t);
int         	check(int **matrix, t_tetris t, int x, int y);
void        	pune(int **matrix, t_tetris t, int x, int y, int c);
void        	print(int **matrix, int siz);
void        	ft_putchar(char c);
void        	ft_putstr(char *str);

#endif
