#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_nbr_list	*stack_a;

	if (argc < 2)
	{
		ft_putendl_fd("Error", 1);
		return (EXIT_FAILURE);
	}
	stack_a = check_input(argv);
	if (stack_a)
		select_sorter(stack_a);
	else
	{
		ft_putendl_fd("Error", 1);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
