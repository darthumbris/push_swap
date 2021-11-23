#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>

typedef struct s_nbr_list
{
	int					nbr;
	struct s_nbr_list	*next;
	struct s_nbr_list	*prev;
}				t_nbr_list;

t_nbr_list	*check_input(char **argv);
int			check_duplicates(int n, t_nbr_list *list);
int			nbr_len(char *nbr_str);

void		list_clear(t_nbr_list **list);
void		list_add_back(t_nbr_list **list, t_nbr_list *new);
t_nbr_list	*new_nbr_list(int nbr);
void		list_add_front(t_nbr_list **list, t_nbr_list *new);
t_nbr_list	*list_last(t_nbr_list *list);

t_nbr_list	*fill_stack(char **argv);
void		select_sorter(t_nbr_list *stack_a);
int			check_sorted(t_nbr_list *stack_a);
//-----------operations--------------------------
void		swap_a(t_nbr_list *stack_a, int ss);
void		push_a(t_nbr_list *stack_b, t_nbr_list *stack_a);
void		rotate_a(t_nbr_list *stack_a, int rr);
void		reverse_rotate_a(t_nbr_list *stack_a, int rrr);
void		swap_b(t_nbr_list *stack_b, int ss);
void		push_b(t_nbr_list *stack_a, t_nbr_list *stack_b);
void		rotate_b(t_nbr_list *stack_b, int rr);
void		reverse_rotate_b(t_nbr_list *stack_b, int rrr);
void		swap_a_and_b(t_nbr_list *stack_a, t_nbr_list *stack_b);
void		rotate_a_and_b(t_nbr_list *stack_a, t_nbr_list *stack_b);
void		rev_rotate_a_and_b(t_nbr_list *stack_a, t_nbr_list *stack_b);
//----------------sorters--------------------------
void		sort_three(t_nbr_list *stack_a);
#endif