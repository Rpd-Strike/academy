/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldonder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:36:42 by aldonder          #+#    #+#             */
/*   Updated: 2018/02/06 17:06:55 by aldonder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print(int **matrix, int siz)
{
	int	i;
	int	j;

	i = -1;
	while (++i < siz)
	{
		j = -1;
		while (++j < siz)
		{
			if (!matrix[i][j])
				ft_putchar('.');
			else
				ft_putchar((char)('A' + matrix[i][j] - 1));
		}
		ft_putchar('\n');
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int ind;

	ind = 0;
	while (str[ind])
	{
		ft_putchar(str[ind]);
		ind++;
	}
}
