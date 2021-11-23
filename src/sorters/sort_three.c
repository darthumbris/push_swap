#include <push_swap.h>

/*
 * Checks for the 6 different ways the stack can be ordered.
 * and does the correct operations to sort it.
 */
void	sort_three(t_nbr_list *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->nbr;
	second = stack_a->next->nbr;
	third = stack_a->next->next->nbr;
	if (first > second && first < third)
		swap_a(stack_a, 0);
	else if (first > second && second < third)
		rotate_a(stack_a, 0);
	else if (first < second && second > third)
		reverse_rotate_a(stack_a, 0);
	else if (first > second && second > third)
	{
		swap_a(stack_a, 0);
		reverse_rotate_a(stack_a, 0);
	}
	else if (first < second && second > third && first < third)
	{
		swap_a(stack_a, 0);
		rotate_a(stack_a, 0);
	}
}