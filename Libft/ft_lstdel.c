#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*l;
	t_list	*tmp;

	l = *alst;
	while (l != NULL)
	{
		tmp = l->next;
		(del)(l->content, l->content_size);
		free(l);
		l = tmp;
	}
	*alst = NULL;
}