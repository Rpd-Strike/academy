/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldonder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:21:12 by aldonder          #+#    #+#             */
/*   Updated: 2018/02/06 17:03:27 by aldonder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_height(t_tetris t)
{
	t_tetrimino alfa;
	int			ret;
	int			i;
	int			j;
	int			myval;

	i = 0;
	j = 0;
	alfa = coordonate(t);
	ret = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			myval = my_abs(alfa.coord[i].x - alfa.coord[j].x);
			if (myval > ret)
				ret = myval;
			j++;
		}
		i++;
	}
	return (ret);
}

int		ft_width(t_tetris t)
{
	t_tetrimino alfa;
	int			ret;
	int			i;
	int			j;
	int			myval;

	i = 0;
	j = 0;
	alfa = coordonate(t);
	ret = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			myval = my_abs(alfa.coord[i].y - alfa.coord[j].y);
			if (myval > ret)
				ret = myval;
			j++;
		}
		i++;
	}
	return (ret);
}

int		check(int **matrix, t_tetris t, int x, int y)
{
	int			i;
	t_tetrimino alfa;

	i = 0;
	alfa = coordonate(t);
	while (i < 4)
	{
		if (y + alfa.coord[i].y - alfa.coord[0].y < 0)
			return (0);
		if (matrix[x + alfa.coord[i].x - alfa.coord[0].x]
				[y + alfa.coord[i].y - alfa.coord[0].y] != 0)
			return (0);
		i++;
	}
	return (1);
}

void	pune(int **matrix, t_tetris t, int x, int y, int c)
{
	t_tetrimino alfa;
	int			i;

	alfa = coordonate(t);
	i = 0;
	while (i < 4)
	{
		matrix[x + alfa.coord[i].x - alfa.coord[0].x]
			[y + alfa.coord[i].y - alfa.coord[0].y] = c;
		i++;
	}
}
