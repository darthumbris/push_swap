/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:38:50 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:38:50 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Checks for the 6 different ways the stack can be ordered.
 * and does the correct operations to sort it.
 */
void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->nbr;
	second = stack_a->head->next->nbr;
	third = stack_a->head->next->next->nbr;
	if (first > second && first < third)
		swap_a(stack_a, 0);
	else if (first > second && second > third)
	{
		swap_a(stack_a, 0);
		reverse_rotate_a(stack_a, 0);
	}
	else if (first > second && second < third)
		rotate_a(stack_a, 0);
	else if (first < second && second > third && first < third)
	{
		swap_a(stack_a, 0);
		rotate_a(stack_a, 0);
	}
	else if (first < second && second > third)
		reverse_rotate_a(stack_a, 0);
}
