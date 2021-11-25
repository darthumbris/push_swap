#include <push_swap.h>

/*
 * Depending on the length of the stack
 * will select a sorter to use to optimize it
 */
void	select_sorter(t_stack *stack_a)
{
	t_stack	*stack_b;

	if (check_sorted(stack_a))
	{
		clear_stack(&stack_a);
		exit(EXIT_SUCCESS);
	}
	if (stack_a->size > 3)
		stack_b = init_stack();
	if (stack_a->size == 2)
		swap_a(stack_a, 0);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		quick_sort(stack_a, stack_b);
	else
		big_sorter(stack_a, stack_b);
}
