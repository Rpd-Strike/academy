#include "get_next_line.h"

t_data  *get_working_data(const int fd, t_data **list)
{
    t_data  *last;
    t_data  *point;

    point = *list;
    last = NULL;
    while( point )
    {
        if( point->fd == fd )
            return (point);
        last = point;
        point = point->next;
    }
    if( !(point = (t_data *)malloc(sizeof(t_data))) )
        return (0);
    point->str = NULL;
    point->ind = 0;
    point->fd = fd;
    point->next = NULL;
    if( last )
        last->next = point;
    else
        *list = point;
    return (point);
}

int     get_next_line(const int fd, char **line)
{
    static t_data   *list = NULL;
    t_data          *point = list;

    point = get_working_data(fd, &list);
    if( !point )
        return (-1);
    
}
