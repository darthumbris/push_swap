#include "push_swap.h"

/*
 * Indexes the stack so that the smallest number
 * gets index 0 and biggest number gets index
 * stack size - 1 this makes it much easier
 * to use sorting algorithms (especially
 * those that don't work with negatives)
 */
void	indexer(t_stack	*stack_a)
{
	int				index;
	t_stack_elem	*current;

	index = 0;
	while (index < stack_a->size)
	{
		current = find_stack_min(stack_a, 1);
		current->index = index++;
	}
}
