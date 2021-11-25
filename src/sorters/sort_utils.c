#include <push_swap.h>

int	find_stack_max(t_stack *stack)
{
	int				i;
	int				max;
	t_stack_elem	*temp;

	i = stack->size;
	max = -2147483648;
	temp = stack->head;
	while (i)
	{
		if (max < temp->nbr)
			max = temp->nbr;
		temp = temp->next;
		i--;
	}
	return (max);
}
