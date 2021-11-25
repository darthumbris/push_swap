#include <push_swap.h>

t_stack	*fill_stack(char **argv, t_stack *stack_a)
{
	int				i;

	i = 1;
	while (argv[i])
	{
		if (!check_int(argv[i]))
		{
			clear_stack(&stack_a);
			exit_message("Contains invalid numbers");
			return (NULL);
		}
		add_to_stack_back(stack_a, new_stack_element(ft_atoi(argv[i])));
		i++;
	}
	return (stack_a);
}
