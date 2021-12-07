#include "push_swap.h"

void	rotate_b_comm(t_stack *stack_b, t_com_list *com_list)
{
	rotate_b(stack_b, 1);
	add_command(com_list, new_command("rb"));
}

void	rrb_com(t_stack *stack_b, t_com_list *com_list)
{
	add_command(com_list, new_command("rrb"));
	reverse_rotate_a(stack_b, 1);
}

void	push_b_comm(t_stack *stack_a, t_stack *stack_b, t_com_list *com_list)
{
	push_b(stack_a, stack_b, 1);
	add_command(com_list, new_command("pb"));
}

void	swap_b_com(t_stack *stack_b, t_com_list *com_list)
{
	add_command(com_list, new_command("sb"));
	swap_a(stack_b, 1);
}
