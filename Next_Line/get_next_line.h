/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpuscasu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:48:53 by fpuscasu          #+#    #+#             */
/*   Updated: 2018/02/16 19:50:11 by fpuscasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFF_SIZE 10

typedef struct	s_data
{
	char			*str;
	int				ind;
	int				fd;
	struct s_data	*next;
}				t_data;

int				get_next_line(const int fd, char **line);

#endif
