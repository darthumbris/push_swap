#include <push_swap.h>

t_nbr_list	*fill_stack(char **argv)
{
	t_nbr_list	*stack_a;
	t_nbr_list	*temp;
	int			i;

	i = 1;
	stack_a = NULL;
	while (argv[i])
	{
		temp = new_nbr_list(ft_atoi(argv[i]));
		if (temp == NULL || !nbr_len(argv[i]) || \
			!check_duplicates(temp->nbr, stack_a))
		{
			list_clear(&temp);
			return (NULL);
		}
		list_add_back(&stack_a, temp);
		i++;
	}
	return (stack_a);
}
