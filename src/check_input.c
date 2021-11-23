#include <push_swap.h>

static int	check_all_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicates(int n, t_nbr_list *list)
{
	t_nbr_list	*temp;

	temp = list;
	while (temp)
	{
		if (temp->nbr == n)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	nbr_len(char *nbr_str)
{
	int			len;
	long long	temp_nbr;
	int			min;

	temp_nbr = 0;
	len = 0;
	min = 1;
	if (*nbr_str == '-')
	{
		min = -1;
		nbr_str++;
	}
	while (*nbr_str == '0')
		nbr_str++;
	while (*nbr_str)
	{
		temp_nbr = temp_nbr * 10 + (*nbr_str - 48);
		len++;
		nbr_str++;
	}
	if ((temp_nbr * min) > 2147483647 || (temp_nbr * min) < -2147483648)
		return (0);
	return (len);
}

t_nbr_list	*check_input(char **argv)
{
	t_nbr_list	*stack_a;

	if (!check_all_digits(argv))
		return (0);
	stack_a = fill_stack(argv);
	return (stack_a);
}
