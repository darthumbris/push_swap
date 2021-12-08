#include "push_swap.h"

static void	empty_stack_b_simple(t_stack *stack_a, t_stack *stack_b, \
									t_com_list *com_list)
{
	while (stack_b->size)
		push_a_comm(stack_a, stack_b, com_list);
}

void	radix_loop(t_stack *stack_a, t_stack *stack_b, \
					t_com_list *com_list, int max_bits)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = stack_a->size;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((stack_a->head->index) >> i) & 1) == 1)
				rotate_a_comm(stack_a, com_list);
			else
				push_b_comm(stack_a, stack_b, com_list);
			j++;
		}
		empty_stack_b_simple(stack_a, stack_b, com_list);
		i++;
	}
}

t_com_list	*radix_sort(t_stack *stack_a)
{
	t_stack			*stack_b;
	t_com_list		*com_list;
	int				max_bits;
	int				max_num;

	stack_b = init_stack();
	if (!stack_b)
		exit_message("Malloc Failure", stack_a, NULL, NULL);
	com_list = init_com_list();
	if (!com_list)
		exit_message("Malloc Failure", stack_a, NULL, stack_b);
	max_bits = 0;
	max_num = stack_a->size - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	radix_loop(stack_a, stack_b, com_list, max_bits);
	clear_stack(&stack_b);
	return (com_list);
}
