#include "push_swap.h"

void	rotate_b_comm(t_stack *stack_b, t_com_list *com_list)
{
	t_commands	*new;

	new = new_command("rb");
	if (!new)
		exit_message("Malloc Failure", stack_b, com_list, NULL);
	rotate_b(stack_b, 1);
	add_command(com_list, new);
}

void	rrb_com(t_stack *stack_b, t_com_list *com_list)
{
	t_commands	*new;

	new = new_command("rrb");
	if (!new)
		exit_message("Malloc Failure", stack_b, com_list, NULL);
	add_command(com_list, new);
	reverse_rotate_a(stack_b, 1);
}

void	push_b_comm(t_stack *stack_a, t_stack *stack_b, t_com_list *com_list)
{
	t_commands	*new;

	new = new_command("pb");
	if (!new)
		exit_message("Malloc Failure", stack_a, com_list, stack_b);
	push_b(stack_a, stack_b, 1);
	add_command(com_list, new);
}

void	swap_b_com(t_stack *stack_b, t_com_list *com_list)
{
	t_commands	*new;

	new = new_command("sb");
	if (!new)
		exit_message("Malloc Failure", stack_b, com_list, NULL);
	add_command(com_list, new);
	swap_a(stack_b, 1);
}
