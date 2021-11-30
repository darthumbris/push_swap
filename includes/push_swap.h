#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <stdio.h>

typedef struct s_stack_elem
{
	int					nbr;
	int					index;
	unsigned int		keep;
	struct s_stack_elem	*next;
	struct s_stack_elem	*prev;
}				t_stack_elem;

typedef struct s_stack
{
	t_stack_elem	*head;
	int				size;
}				t_stack;

typedef struct s_commands
{
	char				*operation;
	struct s_commands	*next;
}				t_commands;

typedef struct s_com_list
{
	t_commands	*head;
	int			size;
}				t_com_list;

void			exit_message(char *msg);
//---------Parse functions--------------------
t_stack			*check_input(char **argv);
int				check_duplicates(t_stack *stack_a);
int				check_int(char *nbr_str);
//----------stack-functions---------------------
t_stack			*init_stack(void);
t_stack_elem	*new_stack_element(int nbr);
void			clear_stack(t_stack **stack);
t_stack			*fill_stack(char **argv, t_stack *stack_a);
void			add_to_stack_back(t_stack *stack, t_stack_elem *elem);
void			add_to_stack_front(t_stack *stack, t_stack_elem *elem);
int				find_stack_max(t_stack *stack);
t_stack_elem	*find_stack_min(t_stack *stack, int next);
//---------sorter-utils-------------------------
void			select_sorter(t_stack *stack_a_index, t_stack *stack_a_greater);
int				check_sorted(t_stack *stack_a);
void			indexer(t_stack *stack_a);
int				count_rra_moves(t_stack *stack_a);
int				count_ra_moves(t_stack *stack_a);
void			empty_stack_b(t_stack *stack_a, t_stack *stack_b, \
								t_com_list *com_list);
//-----------operations--------------------------
void			swap_a(t_stack *stack_a, int show);
void			push_a(t_stack *stack_a, t_stack *stack_b, int show);
void			rotate_a(t_stack *stack_a, int show);
void			reverse_rotate_a(t_stack *stack_a, int show);
void			swap_b(t_stack *stack_b, int show);
void			push_b(t_stack *stack_a, t_stack *stack_b, int show);
void			rotate_b(t_stack *stack_b, int show);
void			reverse_rotate_b(t_stack *stack_b, int show);
void			swap_a_and_b(t_stack *stack_a, t_stack *stack_b);
void			rotate_a_and_b(t_stack *stack_a, t_stack *stack_b);
void			rev_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b);
//----------------sorters--------------------------
void			sort_three(t_stack *stack_a);
void			quick_sort(t_stack *stack_a, t_stack *stack_b);
void			big_sorter(t_stack *stack_a_index, t_stack *stack_a_greater);
t_com_list		*chunk_sort(t_stack *stack_a);
t_com_list		*radix_sort(t_stack *stack_a);
//----------command-functions------------------------
t_com_list		*init_com_list(void);
t_commands		*new_command(char	*operation);
void			add_command(t_com_list *com_list, t_commands *command);
void			clear_com_list(t_com_list **com_list);
void			print_com_list(t_com_list *com_list);
#endif