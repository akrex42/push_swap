#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct s_tools
{
	int			*tab_sorted;
	int			*tab_original;

} t_tools;

void 	push_b(t_list **head_a, t_list **head_b, t_list **tail_a, t_list **tail_b);
void 	push_a(t_list **head_a, t_list **head_b, t_list **tail_a, t_list **tail_b);
void 	swap_a(t_list **tail_a);
void 	swap_b(t_list **tail_b);
void	swap_ab(t_list **tail_b, t_list **tail_a);
void	rotate_b(t_list **head_b, t_list **tail_b);
void	rotate_a(t_list **head_a, t_list **tail_a);
void	rotate_ab(t_list **head_a, t_list **tail_a, t_list **head_b, t_list **tail_b);
void	reverse_rotate_a(t_list **head_a, t_list **tail_a);
void	reverse_rotate_b(t_list **head_b, t_list **tail_b);
void	reverse_rotate_ab(t_list **head_a, t_list **tail_a, t_list **head_b, t_list **tail_b);
void 	init_struct_tools(t_tools *t, int argc);
void 	create_two_tabs(t_tools *t, char **argv, int argc);
void 	sort_tab(t_tools *t, int argc);
void 	print_tab_sorted(t_tools *t, int argc);
void 	print_tab_not_sorted(t_tools *t, int argc);
void 	add_indexes_to_list(t_tools *t, t_list **head_a, t_list **a, t_list **tail_a, int argc);
void 	print_stack_a(t_list *a, t_list *head_a);
void 	print_stack_b(t_list *b, t_list *head_b);
void 	sort_stack_two_elems(t_list **tail_a);
void 	sort_stack_three_elems(t_list **a, t_list **head_a, t_list **tail_a);
int		find_median(t_list *a, t_list *head_a);
void	sort_all(t_list **a, t_list **head_a, t_list **tail_b, t_list **head_b, t_list **tail_a);

#endif