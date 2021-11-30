#include "push_swap.h"

static void	empty_stack_b_simple(t_stack *stack_a, t_stack *stack_b, \
									t_com_list *com_list)
{
	while (stack_b->size)
	{
		push_a(stack_a, stack_b, 1);
		add_command(com_list, new_command("pa"));
	}
}

void	radix_loop(t_stack *stack_a, t_stack *stack_b, \
					t_com_list *com_list, int max_bits)
{
	int	i;
	int	j;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		i++;
		while (j < stack_a->size)
		{
			j++;
			if ((((stack_a->head->index) >> i) & 1) == 1)
			{
				rotate_a(stack_a, 1);
				add_command(com_list, new_command("ra"));
			}
			else
			{
				push_b(stack_a, stack_b, 1);
				add_command(com_list, new_command("pb"));
			}
		}
		empty_stack_b_simple(stack_a, stack_b, com_list);
	}
}

t_com_list	*radix_sort(t_stack *stack_a)
{
	t_stack		*stack_b;
	t_com_list	*com_list;
	int			max_bits;

	stack_b = init_stack();
	com_list = init_com_list();
	max_bits = 0;
	while (((stack_a->size - 1) >> max_bits) != 0)
		++max_bits;
	radix_loop(stack_a, stack_b, com_list, max_bits);
	return (com_list);
}
