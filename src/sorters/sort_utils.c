#include "push_swap.h"

/*
 * This function will find the maximum value
 * in the stack and return the max value as an int
 */
int	find_stack_max(t_stack *stack)
{
	int				i;
	int				max;
	t_stack_elem	*temp;

	i = 0;
	max = -2147483648;
	temp = stack->head;
	while (i < stack->size)
	{
		if (max < temp->nbr)
			max = temp->nbr;
		temp = temp->next;
		i++;
	}
	return (max);
}

int	find_stack_min(t_stack *stack)
{
	int				i;
	int				min;
	t_stack_elem	*temp;

	i = 0;
	min = 2147483647;
	temp = stack->head;
	while (i < stack->size)
	{
		if (min > temp->nbr)
			min = temp->nbr;
		temp = temp->next;
		i++;
	}
	return (min);
}

/*
 * This function will find the minimum value
 * in the stack and return the element with that 
 * minimum value. If the next is true then it
 * will find the element with a minimum value
 * that hasn't been indexed yet.
 */
t_stack_elem	*find_stack_min_next(t_stack *stack)
{
	int				bool_i;
	t_stack_elem	*current;
	t_stack_elem	*min;
	int				i;

	min = NULL;
	bool_i = 0;
	current = stack->head;
	i = 0;
	if (current)
	{
		while (current && i < stack->size)
		{
			if ((current->index == -1) && (!bool_i || current->nbr < min->nbr))
			{
				min = current;
				bool_i = 1;
			}
			current = current->next;
			i++;
		}
	}
	return (min);
}
