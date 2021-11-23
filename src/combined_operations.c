#include <push_swap.h>

void	swap_a_and_b(t_nbr_list *stack_a, t_nbr_list *stack_b)
{
	swap_a(stack_a, 1);
	swap_b(stack_b, 1);
	ft_putendl_fd("ss", 1);
}

void	rotate_a_and_b(t_nbr_list *stack_a, t_nbr_list *stack_b)
{
	rotate_a(stack_a, 1);
	rotate_b(stack_b, 1);
	ft_putendl_fd("rr", 1);
}

void	rev_rotate_a_and_b(t_nbr_list *stack_a, t_nbr_list *stack_b)
{
	reverse_rotate_a(stack_a, 1);
	reverse_rotate_b(stack_b, 1);
	ft_putendl_fd("rrr", 1);
}
