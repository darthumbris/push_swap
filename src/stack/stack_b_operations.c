#include "push_swap.h"

/*
 * swaps the first two elements of stack b
 */
void	swap_b(t_stack *stack_b, int show)
{
	int	temp;

	if (stack_b)
	{
		if (stack_b->head->next)
		{
			temp = stack_b->head->nbr;
			stack_b->head->nbr = stack_b->head->next->nbr;
			stack_b->head->next->nbr = temp;
			if (!show)
				ft_putendl_fd("sb", 1);
		}
	}
}

/*
 * push first element from stack_a and add to front of stack_b
 * do nothing if stack a is empty
 */
void	push_b(t_stack *stack_a, t_stack *stack_b, int show)
{
	t_stack_elem	*current;
	t_stack_elem	*tail;

	if (!stack_a->head)
		return ;
	current = stack_a->head;
	tail = stack_a->head->prev;
	add_to_stack_front(stack_b, new_stack_element(stack_a->head->nbr));
	stack_a->head = stack_a->head->next;
	tail->next = stack_a->head;
	stack_a->head->prev = tail;
	stack_a->size--;
	free(current);
	if (!show)
		ft_putendl_fd("pb", 1);
	if (stack_a->size == 0)
		stack_a->head = NULL;
}

/*
 * Shifts up all elements of stack_a by 1 
 * the first element becomes the last one.
 */
void	rotate_b(t_stack *stack_b, int show)
{
	if (stack_b)
	{
		stack_b->head = stack_b->head->next;
		if (!show)
			ft_putendl_fd("rb", 1);
	}
}

/*
 * Shifts down all elements of stack_a by 1 
 * the last element becomes the first one.
 */
void	reverse_rotate_b(t_stack *stack_b, int show)
{
	if (stack_b)
	{
		stack_b->head = stack_b->head->prev;
		if (!show)
			ft_putendl_fd("rrb", 1);
	}
}
