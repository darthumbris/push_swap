#include "push_swap.h"

/*
 * Depending on the length of the stack
 * will select a sorter to use to optimize it
 */
void	select_sorter(t_stack *stack_a_index, t_stack *stack_a_greater)
{
	t_stack	*stack_b;

	if (check_sorted(stack_a_index))
	{
		clear_stack(&stack_a_index);
		clear_stack(&stack_a_greater);
		exit(EXIT_SUCCESS);
	}
	if (stack_a_index->size == 2)
		swap_a(stack_a_index, 0);
	else if (stack_a_index->size == 3)
		sort_three(stack_a_index);
	else if (stack_a_index->size <= 5)
	{
		stack_b = init_stack();
		quick_sort(stack_a_index, stack_b);
		free(stack_b);
	}
	else
		big_sorter(stack_a_index, stack_a_greater);
}
