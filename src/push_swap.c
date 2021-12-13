/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: shoogenb <shoogenb@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 09:36:22 by shoogenb      #+#    #+#                 */
/*   Updated: 2021/12/13 09:36:27 by shoogenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a_chunk;
	t_stack	*stack_a_radix;

	if (argc < 2)
		return (EXIT_SUCCESS);
	stack_a_chunk = check_input(argv);
	stack_a_radix = check_input(argv);
	if (stack_a_chunk)
		select_sorter(stack_a_chunk, stack_a_radix);
	return (EXIT_SUCCESS);
}
