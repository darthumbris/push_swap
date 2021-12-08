#include "push_swap.h"

int	check_duplicates(t_stack *stack_a)
{
	int				i;
	t_stack_elem	*current;
	t_stack_elem	*check;

	i = 0;
	check = stack_a->head;
	while (i < stack_a->size)
	{
		current = check->next;
		while (current != check)
		{
			if (current->nbr == check->nbr)
				return (0);
			current = current->next;
		}
		i++;
		check = check->next;
	}
	return (1);
}

int	check_int(char *nbr_str)
{
	long long	temp_nbr;
	int			min;
	int			i;
	int			len;

	i = 0;
	len = 0;
	temp_nbr = 0;
	min = 1;
	while (nbr_str[i] == ' ')
		i++;
	if (nbr_str[i] == '-')
		min = -1;
	if (nbr_str[i] == '+' || nbr_str[i] == '-')
		i++;
	while (ft_isdigit(nbr_str[i]))
	{
		len++;
		temp_nbr = temp_nbr * 10 + (*nbr_str - 48);
		if ((temp_nbr * min) > 2147483647 || (temp_nbr * min) < -2147483648)
			return (0);
		i++;
	}
	return (!nbr_str[i] && len);
}

t_stack	*check_input(char **argv)
{
	t_stack	*stack_a;

	stack_a = init_stack();
	if (!stack_a)
		exit_message("Malloc Failure", NULL, NULL, NULL);
	stack_a = fill_stack(argv, stack_a);
	if (!check_duplicates(stack_a))
		exit_message("Contains Duplicates", stack_a, NULL, NULL);
	if (!stack_a->size)
		exit_message("No numbers", stack_a, NULL, NULL);
	return (stack_a);
}
