#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	if (l == NULL)
		return (NULL);
	if (content == NULL)
	{
		l->content_size = 0;
		l->content = NULL;
	}
	else
	{
		l->content = ft_memalloc(content_size);
		ft_memcpy(l->content, content, content_size);
		l->content_size = content_size;
	}
	l->next = NULL;
	return (l);
}