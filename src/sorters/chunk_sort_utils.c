/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_sort_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:38:33 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:38:34 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	check_in_chunk_halve(t_stack *stack_b, int max)
{
	int				i;
	t_stack_elem	*temp;

	temp = stack_b->head;
	i = 0;
	while (i < stack_b->size / 2)
	{
		if (temp->nbr == max)
			return (1);
		i++;
		temp = temp->next;
	}
	return (0);
}

void	empty_stack_b(t_stack *stack_a, t_stack *stack_b, t_com_list *com_list)
{
	int				max;

	max = find_stack_max(stack_b);
	if (check_in_chunk_halve(stack_b, max))
	{
		while (stack_b->head->nbr != max)
			rotate_b_comm(stack_b, com_list);
	}
	else
	{
		while (stack_b->head->nbr != max)
			rrb_com(stack_b, com_list);
	}
	push_a_comm(stack_a, stack_b, com_list);
}

int	count_ra_moves(t_stack *stack_a)
{
	int				i;
	int				ra_moves;
	t_stack_elem	*temp;

	i = 0;
	ra_moves = 0;
	temp = stack_a->head;
	while (i < stack_a->size / 2)
	{
		if (temp->keep)
			break ;
		ra_moves++;
		temp = temp->next;
		i++;
	}
	return (ra_moves);
}

int	count_rra_moves(t_stack *stack_a)
{
	int				i;
	int				rra_moves;
	t_stack_elem	*temp;

	i = 0;
	rra_moves = 1;
	temp = stack_a->head->prev;
	while (i < stack_a->size / 2)
	{
		if (temp->keep)
			break ;
		rra_moves++;
		temp = temp->prev;
		i++;
	}
	return (rra_moves);
}
