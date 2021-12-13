/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   select_sorter.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:38:45 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:38:45 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Depending on the length of the stack
 * will select a sorter to use to optimize it
 */
void	select_sorter(t_stack *stack_a_chunk, t_stack *stack_a_radix)
{
	t_stack	*stack_b;

	if (check_sorted(stack_a_chunk))
	{
		clear_stack(&stack_a_chunk);
		clear_stack(&stack_a_radix);
		exit(EXIT_SUCCESS);
	}
	if (stack_a_chunk->size == 2)
		swap_a(stack_a_chunk, 0);
	else if (stack_a_chunk->size == 3)
		sort_three(stack_a_chunk);
	else if (stack_a_chunk->size <= 5)
	{
		stack_b = init_stack();
		quick_sort(stack_a_chunk, stack_b);
		clear_stack(&stack_b);
	}
	else
		big_sorter(stack_a_chunk, stack_a_radix);
	clear_stack(&stack_a_radix);
	clear_stack(&stack_a_chunk);
}
