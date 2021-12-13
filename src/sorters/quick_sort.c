/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:38:37 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:38:38 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
 * Uses a pivot point to push the elements 
 * smaller than the pivot to stack_b
 * until there are only three elements left in stack_a
 * then it will either rotate_b if needed and
 * then push_a to get all the 
 * elements from stack_b back in the correct spot.
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
				push_b(stack_a, stack_b, 0);
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
		push_a(stack_a, stack_b, 0);
}
