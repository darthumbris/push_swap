#include <push_swap.h>

/*
 * swaps the first two elements of stack a
 */
void	swap_a(t_nbr_list *stack_a, int ss)
{
	int	temp;

	if (stack_a)
	{
		if (stack_a->next)
		{
			temp = stack_a->nbr;
			stack_a->nbr = stack_a->next->nbr;
			stack_a->next->nbr = temp;
			if (!ss)
				ft_putendl_fd("sa", 1);
		}
	}
}

/*
 * push first element from stack_b and add to front of stack_a
 * do nothing if stack b is empty
 */
void	push_a(t_nbr_list *stack_b, t_nbr_list *stack_a)
{
	if (stack_b)
	{
		list_add_front(&stack_a, stack_b);
		stack_b->next->prev = NULL;
		stack_b->nbr = 0;
		free(stack_b);
		ft_putendl_fd("pa", 1);
	}
}

/*
 * Shifts up all elements of stack_a by 1 
 * the first element becomes the last one.
 */
void	rotate_a(t_nbr_list *stack_a, int rr)
{
	if (stack_a)
	{
		list_add_back(&stack_a, stack_a);
		stack_a->next->prev = NULL;
		stack_a->nbr = 0;
		free(stack_a);
		if (!rr)
			ft_putendl_fd("ra", 1);
	}
}

/*
 * Shifts down all elements of stack_a by 1 
 * the last element becomes the first one.
 */
void	reverse_rotate_a(t_nbr_list *stack_a, int rrr)
{
	t_nbr_list	*last;

	if (stack_a)
	{
		last = list_last(stack_a);
		list_add_front(&stack_a, last);
		//last->prev->next = NULL;
		last->nbr = 0;
		last->next = NULL;
		free(last);
		if (!rrr)
			ft_putendl_fd("rra", 1);
	}
}
