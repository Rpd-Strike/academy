/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpuscasu <fpuscasu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:48:38 by fpuscasu          #+#    #+#             */
/*   Updated: 2018/02/16 19:56:20 by fpuscasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv)
{
	char	*meh;
	int		fd;

	if (argc != 2)
	{
		printf("Expect one argument\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
    while (get_next_line(fd, &meh))
    {
    	printf("Read:\n");
    	printf("%s\n", meh);
    }
    return (0);
}
