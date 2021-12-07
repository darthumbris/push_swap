#include "push_swap.h"

void	rotate_a_comm(t_stack *stack_a, t_com_list *com_list)
{
	rotate_a(stack_a, 1);
	add_command(com_list, new_command("ra"));
}

void	rra_com(t_stack *stack_a, t_com_list *com_list)
{
	add_command(com_list, new_command("rra"));
	reverse_rotate_a(stack_a, 1);
}

void	push_a_comm(t_stack *stack_a, t_stack *stack_b, t_com_list *com_list)
{
	push_a(stack_a, stack_b, 1);
	add_command(com_list, new_command("pa"));
}

void	swap_a_com(t_stack *stack_a, t_com_list *com_list)
{
	add_command(com_list, new_command("sa"));
	swap_a(stack_a, 1);
}
