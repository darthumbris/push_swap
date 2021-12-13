/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:38:08 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:38:09 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
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

t_stack_elem	*new_stack_element(int nbr, int index)
{
	t_stack_elem	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	new->keep = 0;
	return (new);
}
