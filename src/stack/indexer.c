#include <push_swap.h>

void	get_minimum(t_stack *stack_a)
{
	// int		i;
	// int		min;
	// t_stack	*temp;
	if (stack_a)
		ft_putendl_fd("get minimum", 1);
}

/*
 * Indexes the stack so that the smallest number
 * gets index 0 and biggest number gets index
 * stack size - 1 
 */
void	indexer(t_stack	*stack_a)
{
	int	n;

	n = stack_a->head->nbr;
	while (stack_a)
	{
		if (stack_a->head->nbr < n && stack_a->head->index == -1)
		{
			n = stack_a->head->nbr;
		}
	}
}
