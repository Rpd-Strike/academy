/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldonder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:28:00 by aldonder          #+#    #+#             */
/*   Updated: 2018/02/06 16:57:29 by aldonder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int gasit = 0;

void die_n_hell()
{
	ft_putstr("error");
}

void	patrat(int **matrix, t_tetris *t, int nr, int size, int ind)
{
	int x;
	int y;

	x = 0;
	if (ind > nr) {
		gasit = 1;
		return ;
	}
	if(gasit) return ;
	while (x < size - ft_height(*t))
	{
		y = 0;
		while (y < size - ft_width(*t))
		{
			if (check(matrix, *t, x ,y))
			{
				pune(matrix, *t, x, y, ind);
				patrat(matrix, t+1, nr, size, ind+1);
				if( gasit ) return ;
				pune(matrix, *t, x, y, 0);
			}
			y++;
		}
		x++;
	}
}

int	**do_solve(t_tetris *t, int nr, int *siz)
{
	int		**matrix;
	int 	size;

	++t;
	size = high_sqrt(nr * 4) - 1;
	matrix = make_matrix(size);
	gasit = 0;
	while(!gasit)
	{
		size ++;
		free_matrix(matrix, size - 1);
		matrix = make_matrix(size);

		patrat(matrix, t, nr, size, 1);
	}
	*siz = size;
	return (matrix);
}

void	do_read(int fd, int *nr, t_tetris *vec)
{
	char	buff[30];
	int		ret;
	int		ok;

	ok = 1;
	(*nr) = 0;
	while( (ret = read(fd, buff, 21)) != 0 )
	{
		if( ret > 21 || ret < 20 )
			ok = 0;
		if( ret == 21 && buff[20] != '\n' )
			ok = 0;
		if( !legal_char(buff, ret) )
			ok = 0;
		(*nr)++;
		place_tetrimino(buff, &(vec[*nr]));
		if( !check_tetrimino(vec[*nr]) )
			ok = 0;
	}

	if( !ok ) {
		die_n_hell();
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_tetris	t[30];
	int			**matrix;
	int			nr;
	int			fd;
	int			siz;

	if (argc != 2)
	{
		die_n_hell();
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		die_n_hell();

	do_read(fd, &nr, t);
	matrix = do_solve(t, nr, &siz);
	print(matrix, siz);
	return (0);
}
