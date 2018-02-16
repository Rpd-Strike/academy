/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldonder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:19:15 by aldonder          #+#    #+#             */
/*   Updated: 2018/02/06 16:48:47 by aldonder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_memdel(void **ap)
{
	if (!ap)
		return ;
	free(*ap);
	*ap = NULL;
}

t_tetrimino	coordonate(t_tetris t)
{
	int			i;
	int			j;
	int			k;
	t_tetrimino alfa;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t.t[i][j] == 1)
			{
				alfa.coord[k].x = i;
				alfa.coord[k++].y = j;
			}
			j++;
		}
		i++;
	}
	return (alfa);
}

int			**make_matrix(int size)
{
	int	**matrix;
	int	i;
	int	j;

	i = 0;
	matrix = (int **)malloc(sizeof(int *) * (size + 1));
	while (i < size)
	{
		matrix[i] = (int *)malloc(sizeof(int) * (size + 1));
		j = 0;
		while (j < size)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}

void		free_matrix(int **matrix, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&(matrix[i]));
		i++;
	}
	ft_memdel((void **)matrix);
}

int			high_sqrt(int a)
{
	int ret;

	ret = 0;
	while (ret * ret < a)
		ret++;
	return (ret);
}
