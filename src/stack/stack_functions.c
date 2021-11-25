#include <push_swap.h>

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit_message("Malloc Failure");
	stack->head = NULL;
	stack->markup_head = NULL;
	stack->size = 0;
	return (stack);
}

void	add_to_stack_front(t_stack *stack, t_stack_elem *elem)
{
	t_stack_elem	*tail;

	if (stack && elem)
	{
		if (!stack->head)
		{
			stack->head = elem;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			tail = stack->head->prev;
			elem->prev = tail;
			tail->next = elem;
			elem->next = stack->head;
			stack->head->prev = elem;
			stack->head = elem;
		}
		stack->size++;
	}
}

void	add_to_stack_back(t_stack *stack, t_stack_elem *elem)
{
	t_stack_elem	*tail;

	if (stack && elem)
	{
		if (!stack->head)
		{
			stack->head = elem;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			tail = stack->head->prev;
			elem->prev = tail;
			tail->next = elem;
			elem->next = stack->head;
			stack->head->prev = elem;
		}
		stack->size++;
	}
}

void	clear_stack(t_stack **stack)
{
	int				i;
	t_stack_elem	*delete;
	t_stack_elem	*head;

	i = 0;
	head = (*stack)->head;
	while (i < (*stack)->size)
	{
		delete = head;
		head = head->next;
		free(delete);
		i++;
	}
	free(*stack);
}

t_stack_elem	*new_stack_element(int nbr)
{
	t_stack_elem	*new;

	new = malloc(sizeof(*new));
	if (!new)
		exit_message("Malloc Failure");
	new->nbr = nbr;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	new->keep = 0;
	return (new);
}
