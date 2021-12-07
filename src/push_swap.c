#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a_chunk;
	t_stack	*stack_a_radix;

	if (argc < 2)
	{
		ft_putendl_fd("Error", 1);
		return (EXIT_FAILURE);
	}
	stack_a_chunk = check_input(argv);
	stack_a_radix = check_input(argv);
	if (stack_a_chunk)
		select_sorter(stack_a_chunk, stack_a_radix);
	else
	{
		ft_putendl_fd("Error", 1);
		return (EXIT_FAILURE);
	}
	//system("leaks push_swap");
	return (EXIT_SUCCESS);
}
