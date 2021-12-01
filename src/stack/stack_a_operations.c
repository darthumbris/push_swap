#include "push_swap.h"

/*
 * swaps the first two elements of stack a
 */
void	swap_a(t_stack *stack_a, int show)
{
	int	temp;
	int	temp_index;

	if (stack_a)
	{
		if (stack_a->head->next)
		{
			temp = stack_a->head->nbr;
			temp_index = stack_a->head->index;
			stack_a->head->nbr = stack_a->head->next->nbr;
			stack_a->head->index = stack_a->head->next->index;
			stack_a->head->next->nbr = temp;
			stack_a->head->next->index = temp_index;
			if (!show)
				ft_putendl_fd("sa", 1);
		}
	}
}

/*
 * push first element from stack_b and add to front of stack_a
 * do nothing if stack b is empty
 */
void	push_a(t_stack *stack_a, t_stack *stack_b, int show)
{
	t_stack_elem	*current;
	t_stack_elem	*tail;

	if (!stack_b->head)
		return ;
	current = stack_b->head;
	tail = stack_b->head->prev;
	add_to_stack_front(stack_a, new_stack_element
		(stack_b->head->nbr, stack_b->head->index));
	stack_b->head = stack_b->head->next;
	tail->next = stack_b->head;
	stack_b->head->prev = tail;
	stack_b->size--;
	free(current);
	if (!show)
		ft_putendl_fd("pa", 1);
	if (stack_b->size == 0)
		stack_b->head = NULL;
}

/*
 * Shifts up all elements of stack_a by 1 
 * the first element becomes the last one.
 */
void	rotate_a(t_stack *stack_a, int show)
{
	if (stack_a)
	{
		stack_a->head = stack_a->head->next;
		if (!show)
			ft_putendl_fd("ra", 1);
	}
}

/*
 * Shifts down all elements of stack_a by 1 
 * the last element becomes the first one.
 */
void	reverse_rotate_a(t_stack *stack_a, int show)
{
	if (stack_a)
	{
		stack_a->head = stack_a->head->prev;
		if (!show)
			ft_putendl_fd("rra", 1);
	}
}
