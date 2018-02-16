/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldonder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:14:41 by aldonder          #+#    #+#             */
/*   Updated: 2018/02/06 17:16:04 by aldonder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		legal_char(char *str, int size)
{
	int ind;
	int ok;

	ok = 1;
	ind = 0;
	if (size > 20)
		--size;
	while (ind < size)
	{
		if (ind % 5 == 4)
		{
			if (str[ind] != '\n')
				ok = 0;
		}
		else if (!(str[ind] == '.' || str[ind] == '#'))
			ok = 0;
		++ind;
	}
	return (ok);
}

void	place_tetrimino(char *str, t_tetris *tet)
{
	int	ind;

	ind = 0;
	while (ind < 20)
	{
		if (str[ind] == '#')
			tet->t[ind / 5][ind % 5] = 1;
		else if (str[ind] == '.')
			tet->t[ind / 5][ind % 5] = 0;
		++ind;
	}
}

void	flood_fill(int x, int y, t_tetris t, int viz[][4])
{
	if (viz[x][y])
		return ;
	viz[x][y] = 1;
	if (x < 3)
		if (t.t[x + 1][y])
			flood_fill(x + 1, y, t, viz);
	if (x > 0)
		if (t.t[x - 1][y])
			flood_fill(x - 1, y, t, viz);
	if (y < 3)
		if (t.t[x][y + 1])
			flood_fill(x, y + 1, t, viz);
	if (y > 0)
		if (t.t[x][y - 1])
			flood_fill(x, y - 1, t, viz);
}

void	make_zero(int mat[][4])
{
	mat[0][0] = mat[0][1] = mat[0][2] = mat[0][3] = 0;
	mat[1][0] = mat[1][1] = mat[1][2] = mat[1][3] = 0;
	mat[2][0] = mat[2][1] = mat[2][2] = mat[2][3] = 0;
	mat[3][0] = mat[3][1] = mat[3][2] = mat[3][3] = 0;
}

int		check_tetrimino(t_tetris t)
{
	int	i;
	int	j;
	int	got;
	int	mat[4][4];

	make_zero(mat);
	got = 0;
	i = -1;
	while (++i < 4 && !got)
	{
		j = -1;
		while (++j < 4 && !got)
		{
			if (t.t[i][j] != 0)
			{
				flood_fill(i, j, t, mat);
				got = 1;
			}
		}
	}
	if (!got)
		return (0);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			got += (int)(t.t[i][j] && mat[i][j]);
		}
	}
	return (got == 5);
}
