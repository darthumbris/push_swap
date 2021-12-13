/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_message.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:36:36 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:36:36 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_message(char *msg, t_stack *stack_a, t_com_list *list, \
				t_stack *stack_b)
{
	ft_putendl_fd(msg, 2);
	if (stack_a)
		clear_stack(&stack_a);
	if (stack_b)
		clear_stack(&stack_b);
	if (list)
		clear_com_list(&list);
	exit(EXIT_FAILURE);
}
