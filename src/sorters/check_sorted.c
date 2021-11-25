#include <push_swap.h>

/*
 * checks if the stack is sorted correctly.
 */
int	check_sorted(t_stack *stack_a)
{
	t_stack_elem	*temp;
	int				i;

	i = 1;
	temp = stack_a->head;
	while (i < stack_a->size)
	{
		if (temp->next)
			if (temp->nbr > temp->next->nbr)
				return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}
