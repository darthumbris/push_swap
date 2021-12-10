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
