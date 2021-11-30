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

	i = stack->size;
	max = -2147483648;
	temp = stack->head;
	while (i)
	{
		if (max < temp->nbr)
			max = temp->nbr;
		temp = temp->next;
		i--;
	}
	return (max);
}

/*
 * This function will find the minimum value
 * in the stack and return the element with that 
 * minimum value. If the next is true then it
 * will find the element with a minimum value
 * that hasn't been indexed yet.
 */
t_stack_elem	*find_stack_min(t_stack *stack, int next)
{
	int				i;
	t_stack_elem	*current;
	t_stack_elem	*min;

	min = NULL;
	if (stack)
	{
		i = 0;
		current = stack->head;
		while (i < stack->size)
		{
			if (!next)
			{
				if (!min || current->nbr < min->nbr)
					min = current;
			}
			else if (current->index == -1 && (!min || current->nbr < min->nbr))
				min = current;
			i++;
			current = current->next;
		}
	}
	return (min);
}
