/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sorted.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:38:27 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:38:27 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * checks if the stack is sorted correctly.
 */
int	check_sorted(t_stack *stack_a)
{
	t_stack_elem	*temp;
	int				i;

	i = 1;
	if (!stack_a)
		return (1);
	temp = stack_a->head;
	if (!temp)
		return (1);
	while (i < stack_a->size)
	{
		if (temp->next)
			if (temp->nbr > temp->next->nbr)
				return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}
