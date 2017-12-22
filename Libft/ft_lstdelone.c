#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list *l;

	l = *alst;
	(del)(l->content, l->content_size);
	free(l);
	*alst = NULL;
}