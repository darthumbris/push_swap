/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands_stack_a.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:39:02 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:39:02 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_comm(t_stack *stack_a, t_com_list *com_list)
{
	t_commands	*new;

	new = new_command("ra");
	if (!new)
		exit_message("Malloc Failure", stack_a, com_list, NULL);
	rotate_a(stack_a, 1);
	add_command(com_list, new);
}

void	rra_com(t_stack *stack_a, t_com_list *com_list)
{
	t_commands	*new;

	new = new_command("rra");
	if (!new)
		exit_message("Error", stack_a, com_list, NULL);
	add_command(com_list, new);
	reverse_rotate_a(stack_a, 1);
}

void	push_a_comm(t_stack *stack_a, t_stack *stack_b, t_com_list *com_list)
{
	t_commands	*new;

	new = new_command("pa");
	if (!new)
		exit_message("Error", stack_a, com_list, stack_b);
	push_a(stack_a, stack_b, 1);
	add_command(com_list, new);
}

void	swap_a_com(t_stack *stack_a, t_com_list *com_list)
{
	t_commands	*new;

	new = new_command("sa");
	if (!new)
		exit_message("Error", stack_a, com_list, NULL);
	add_command(com_list, new);
	swap_a(stack_a, 1);
}
