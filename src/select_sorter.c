#include <push_swap.h>

void	select_sorter(t_nbr_list *stack_a)
{
	t_nbr_list	*temp;
	int			len_list;

	if (check_sorted(stack_a))
	{
		list_clear(&stack_a);
		exit(EXIT_SUCCESS);
	}
	temp = stack_a;
	len_list = 0;
	while (temp)
	{
		len_list++;
		temp = temp->next;
	}
	if (len_list == 2)
		swap_a(stack_a, 0);
	if (len_list == 3)
		sort_three(stack_a);
}
