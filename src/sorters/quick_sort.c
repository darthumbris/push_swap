#include <push_swap.h>

/*
 * This function checks how many elements of the stack
 * have a value less than the value of the pivot point.
 */
static int	amount_elem_less_pivot(t_stack *stack_a, int pivot)
{
	int				i;
	t_stack_elem	*temp;
	int				result;

	i = stack_a->size;
	temp = stack_a->head;
	result = 0;
	while (i)
	{
		if (temp->nbr < pivot)
			result++;
		temp = temp->next;
		i--;
	}
	return (result);
}

/*
 * This function finds the pivot point
 * it sets the pivot point for the 
 * element that has only 2 other
 * elements that are smaller than it.
 */
static int	find_pivot(t_stack *stack_a)
{
	int				i;
	t_stack_elem	*temp;
	int				pivot;

	i = stack_a->size;
	temp = stack_a->head;
	while (i)
	{
		if (amount_elem_less_pivot(stack_a, temp->nbr) == 2)
			pivot = temp->nbr;
		temp = temp->next;
		i--;
	}
	return (pivot);
}

/*
 * Uses the quicksort algorithm to sort stack_a
 * using stack_b.
 */
void	quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	pivot;
	int	max_stack_b;

	while (stack_a->size > 3)
	{
		pivot = find_pivot(stack_a);
		i = amount_elem_less_pivot(stack_a, pivot);
		while (i)
		{
			if (stack_a->head->nbr < pivot)
			{
				push_b(stack_a, stack_b);
				i--;
			}
			else
				rotate_a(stack_a, 0);
		}
	}
	max_stack_b = find_stack_max(stack_b);
	sort_three(stack_a);
	if (stack_b->head->nbr != max_stack_b)
		rotate_b(stack_b, 0);
	while (stack_b->size)
		push_a(stack_a, stack_b);
}
