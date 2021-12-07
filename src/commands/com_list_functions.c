#include "push_swap.h"

void	print_com_list(t_com_list *com_list)
{
	t_commands	*temp;

	if (com_list)
	{
		temp = com_list->head;
		while (temp)
		{
			if (temp->print)
				ft_putendl_fd(temp->operation, 1);
			temp = temp->next;
		}
	}
}

t_com_list	*init_com_list(void)
{
	t_com_list	*command_list;

	command_list = malloc(sizeof(t_com_list));
	if (!command_list)
		return (NULL);
	command_list->head = NULL;
	command_list->size = 0;
	return (command_list);
}

void	add_command(t_com_list *com_list, t_commands *command)
{
	t_commands	*tail;

	if (com_list && command)
	{
		if (!com_list->head)
			com_list->head = command;
		else
		{
			tail = com_list->head;
			while (tail->next)
				tail = tail->next;
			tail->next = command;
		}
		com_list->size++;
	}
}

t_commands	*new_command(char	*operation)
{
	t_commands	*new;

	new = malloc(sizeof(t_commands));
	if (!new)
		exit_message("Malloc Failure");
	new->next = NULL;
	new->operation = ft_strdup(operation);
	new->print = 1;
	return (new);
}

void	clear_com_list(t_com_list **com_list)
{
	int			i;
	t_commands	*delete;
	t_commands	*head;

	i = 0;
	head = (*com_list)->head;
	while (i < (*com_list)->size)
	{
		delete = head;
		head = head->next;
		free(delete->operation);
		free(delete);
		i++;
	}
	free(*com_list);
}
