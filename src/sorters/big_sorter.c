#include "push_swap.h"

/*
 * This function will make two command lists
 * which will contain the commands used for 
 * the two different ways to solve the stack.
 * then whichever is smallest gets printed.
 */
void	big_sorter(t_stack *stack_a_chunk, t_stack *stack_a_radix)
{
	t_com_list	*commands_chunk;
	t_com_list	*commands_radix;

	if (stack_a_chunk && stack_a_radix)
	{
		indexer(stack_a_radix);
		commands_chunk = chunk_sort(stack_a_chunk);
		commands_radix = radix_sort(stack_a_radix);
		if (commands_radix->size > commands_chunk->size)
		{
			print_com_list(commands_chunk);
			ft_putendl_fd("did chunk", 1);
		}
		else
		{
			print_com_list(commands_radix);
			ft_putendl_fd("did radix", 1);
		}
		free(commands_radix);
		free(commands_chunk);
		free(stack_a_radix);
		free(stack_a_chunk);
	}
}
