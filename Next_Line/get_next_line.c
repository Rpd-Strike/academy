#include "get_next_line.h"

static t_data      *get_working_data(const int fd, t_data **list)
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

static int         fill_buff(t_data *data)
{
    int ret;
    int i;

    ret = read(data->fd, data->str, BUFF_SIZE);
    data->str[ret] = '\0';
    i = ret;
    while(++i <= BUFF_SIZE)
        data->str[i] = 0;
    if( ret <= 0 )
        data->ind = -1;
    return (ret);
}

static signed char get_next_char(t_data *data)
{ /// return next char from fd, -1 if error, 0 if already done
    int         ret;
    signed char ch;

    if( data->ind < 0 )
        return (0);
    if(data->str == NULL)
    {
        data->str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 2));
        ret = fill_buff(data);
        if(ret <= 0)
            return (signed char)(ret);
    }
    if( data->ind >= BUFF_SIZE )
    {
        data->ind = 0;
        ret = fill_buff(data);
        if( ret <= 0 )
            return (signed char)(ret);
    }
    ch = data->str[data->ind];
    data->ind += 1;
    ///printf("Next char: %c\n", ch);
    return (ch);
}

static void        my_append(char **line, size_t size, size_t max_size, char ch)
{
    char    *str;
    int     i;

    if( ch == '\n' )
        ch = '\0';
    i = -1;
    if( size > max_size )
    {
        str = (char *)malloc(sizeof(char) * (max_size + BUFF_SIZE));
        while(++i < (int)size)
            str[i] = (*line)[i];
        *line = str;
    }
    (*line)[size] = ch;
    ///printf("A apenduit: %c\n", ch);
    (*line)[size + 1] = '\0';
    ///printf("%s\n", (*line));
}

extern int         get_next_line(const int fd, char **line)
{
    static t_data   *list = NULL;
    t_data          *point;
    size_t          size;
    size_t          max_size;
    signed char     ch;

    point = list;
    *line = (char *)malloc(sizeof(char) * ((max_size = BUFF_SIZE) + 3));
    point = get_working_data(fd + (size = 0), &list);
    if (!point || point->ind < 0)
        return (0 - (point->ind < 0));
    /*if( point->ind < 0 )
        return (0);*/
    ///printf("A gasit un elem. de lista: %d\n", point->fd);
    while((ch = get_next_char(point)) > 0)
    {
        my_append(line, size, max_size, ch);
        size += (ch != '\0');
        if( ch == 0 )
            point->ind = -1;
        if( ch == '\n' || ch == 0 )
            break;
    }
    if( ch < 0 )
        return (ch);
    return (size > 0);
}
