#include "push_swap.h"

t_stack	*fill_stack(char **argv, t_stack *stack_a)
{
	int				i;
	t_stack_elem	*new;

	i = 1;
	while (argv[i])
	{
		if (!check_int(argv[i]))
			exit_message("Contains invalid numbers", stack_a, NULL, NULL);
		new = new_stack_element(ft_atoi(argv[i]), -1);
		if (!new)
			exit_message("Contains invalid numbers", stack_a, NULL, NULL);
		add_to_stack_back(stack_a, new);
		i++;
	}
	return (stack_a);
}
