#include <push_swap.h>

/*
 * checks if the stack is sorted correctly.
 */
int	check_sorted(t_nbr_list *stack_a)
{
	t_nbr_list	*temp;

	temp = stack_a;
	while (temp)
	{
		if (temp->next)
			if (temp->nbr > temp->next->nbr)
				return (0);
		temp = temp->next;
	}
	return (1);
}
