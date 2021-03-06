/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:38:30 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:38:30 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smart_move_to_top_stacka(t_stack *stack_a, t_com_list *com_list)
{
	int	ra_moves;
	int	rra_moves;

	ra_moves = count_ra_moves(stack_a);
	rra_moves = count_rra_moves(stack_a);
	if (ra_moves <= rra_moves)
	{
		while (ra_moves)
		{
			ra_moves--;
			rotate_a_comm(stack_a, com_list);
		}
	}
	else
	{
		while (rra_moves)
		{
			rra_moves--;
			rra_com(stack_a, com_list);
		}
	}
}

static int	get_chunk_elements(t_stack *stack_a, int chunk_hold)
{
	int				i;
	int				elements;
	t_stack_elem	*temp;

	i = 0;
	temp = stack_a->head;
	elements = 0;
	while (i < stack_a->size)
	{
		if (temp->nbr < chunk_hold)
		{
			temp->keep = 1;
			elements++;
		}
		temp = temp->next;
		i++;
	}
	return (elements);
}

static void	move_top_to_stackb(t_stack *stack_a, t_stack *stack_b, \
							t_com_list *com_list, int chunk_hold)
{
	int	i;

	i = get_chunk_elements(stack_a, chunk_hold);
	while (i)
	{
		smart_move_to_top_stacka(stack_a, com_list);
		push_b_comm(stack_a, stack_b, com_list);
		i--;
	}
}

static int	get_chunk_step(t_stack *stack_a)
{
	int	step;
	int	min;
	int	max;

	max = find_stack_max(stack_a);
	min = find_stack_min(stack_a);
	if (stack_a->size <= 100)
		step = ((max - min) / 6) + 1;
	if (stack_a->size > 100)
		step = ((max - min) / 10) + 1;
	return (step);
}

t_com_list	*chunk_sort(t_stack *stack_a)
{
	t_stack		*stack_b;
	t_com_list	*com_list;
	int			i;
	int			chunk_step;
	int			chunk_hold;

	stack_b = init_stack();
	if (!stack_b)
		exit_message("Error", stack_a, NULL, NULL);
	chunk_step = get_chunk_step(stack_a);
	chunk_hold = find_stack_min(stack_a) + chunk_step;
	i = stack_a->size;
	com_list = init_com_list();
	if (!com_list)
		exit_message("Error", stack_a, NULL, stack_b);
	while (i)
	{
		move_top_to_stackb(stack_a, stack_b, com_list, chunk_hold);
		chunk_hold += chunk_step;
		i = stack_a->size;
	}
	while (stack_b->size)
		empty_stack_b(stack_a, stack_b, com_list);
	clear_stack(&stack_b);
	return (com_list);
}
