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
	t_stack_elem	*markup_head;
	int				size;
}				t_stack;

void			exit_message(char *msg);

t_stack			*check_input(char **argv);
int				check_duplicates(t_stack *stack_a);
int				check_int(char *nbr_str);

t_stack_elem	*new_stack_element(int nbr);
void			clear_stack(t_stack **stack);

t_stack			*init_stack(void);
t_stack			*fill_stack(char **argv, t_stack *stack_a);
void			add_to_stack_back(t_stack *stack, t_stack_elem *elem);
void			add_to_stack_front(t_stack *stack, t_stack_elem *elem);
int				find_stack_max(t_stack *stack);

void			select_sorter(t_stack *stack_a);
int				check_sorted(t_stack *stack_a);
void			indexer(t_stack *stack_a);
//-----------operations--------------------------
void			swap_a(t_stack *stack_a, int ss);
void			push_a(t_stack *stack_a, t_stack *stack_b);
void			rotate_a(t_stack *stack_a, int rr);
void			reverse_rotate_a(t_stack *stack_a, int rrr);
void			swap_b(t_stack *stack_b, int ss);
void			push_b(t_stack *stack_a, t_stack *stack_b);
void			rotate_b(t_stack *stack_b, int rr);
void			reverse_rotate_b(t_stack *stack_b, int rrr);
void			swap_a_and_b(t_stack *stack_a, t_stack *stack_b);
void			rotate_a_and_b(t_stack *stack_a, t_stack *stack_b);
void			rev_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b);
//----------------sorters--------------------------
void			sort_three(t_stack *stack_a);
void			quick_sort(t_stack *stack_a, t_stack *stack_b);
void			big_sorter(t_stack *stack_a, t_stack *stack_b);
#endif