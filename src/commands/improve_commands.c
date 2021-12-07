#include "push_swap.h"

int	count_push(t_commands **head, int size, int *i, char *str)
{
	int	count;

	count = 0;
	while (ft_strncmp((*head)->operation, str, 2) == 0 && *i < size - 1)
	{
		(*head) = (*head)->next;
		(*i)++;
		count++;
	}
	return (count);
}

void	shift_command_list(t_commands **head, int shift)
{
	while (shift)
	{
		*head = (*head)->next;
		shift--;
	}
}

void	set_not_print(t_commands **head, int amount)
{
	while (amount)
	{
		(*head)->print = 0;
		*head = (*head)->next;
		amount--;
	}
}

void	improve_radix_commands(t_commands *head, int size)
{
	int			i;
	t_commands	*temp;
	int			pb_count;
	int			pa_count;

	i = 0;
	while (i < size - 1)
	{
		pb_count = 0;
		pa_count = 0;
		temp = head;
		pb_count = count_push(&head, size, &i, "pb");
		pa_count = count_push(&head, size, &i, "pa");
		if (pa_count < pb_count && pa_count && pb_count)
		{
			shift_command_list(&temp, pb_count - pa_count);
			set_not_print(&temp, pa_count * 2);
		}
		else if (pa_count && pb_count)
			set_not_print(&temp, pb_count * 2);
		else
			head = head->next;
		i++;
	}
}
