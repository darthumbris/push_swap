#include <push_swap.h>

void	list_clear(t_nbr_list **list)
{
	t_nbr_list	*temp;

	temp = *list;
	while ((*list))
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
	*list = NULL;
}

t_nbr_list	*list_last(t_nbr_list *list)
{
	while (list)
	{
		if (list->next == NULL)
			return (list);
		list = list->next;
	}
	return (list);
}

void	list_add_front(t_nbr_list **list, t_nbr_list *new)
{
	new->next = *list;
	new->prev = NULL;
	(*list)->prev = new;
	*list = new;
}

void	list_add_back(t_nbr_list **list, t_nbr_list *new)
{
	t_nbr_list	*back;

	if (list)
	{
		if (*list)
		{
			back = list_last(*list);
			back->next = new;
			new->prev = back;
		}
		else
			*list = new;
	}
}

t_nbr_list	*new_nbr_list(int nbr)
{
	t_nbr_list	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
