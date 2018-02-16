#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFF_SIZE 32

typedef struct  s_data
{
    char            *str;
    int             ind;
    int             fd;
    struct s_data   *next;
}               t_data;

int		get_next_line(const int fd, char **line);

#endif
