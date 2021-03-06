/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   combined_operations.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:36:58 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:36:58 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a, 1);
	swap_b(stack_b, 1);
	ft_putendl_fd("ss", 1);
}

void	rotate_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a, 1);
	rotate_b(stack_b, 1);
	ft_putendl_fd("rr", 1);
}

void	rev_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(stack_a, 1);
	reverse_rotate_b(stack_b, 1);
	ft_putendl_fd("rrr", 1);
}
