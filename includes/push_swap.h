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
	t_list		*head_a;
	t_list		*tail_a;
	t_list		*a;
	t_list		*head_b;
	t_list		*tail_b;
	t_list		*b;
	int 		size;
	int         flag;
	int         next;

} t_tools;

void 	push_b(t_tools *t);
void 	push_a(t_tools *t);
void 	swap_a(t_tools *t);
void 	swap_b(t_tools *t);
void	swap_ab(t_tools *t);
void	rotate_b(t_tools *t);
void	rotate_a(t_tools *t);
void	rotate_ab(t_tools *t);
void	reverse_rotate_a(t_tools *t);
void	reverse_rotate_b(t_tools *t);
void	reverse_rotate_ab(t_tools *t);
void 	init_struct_tools(t_tools *t);
void 	create_two_tabs(t_tools *t, char **argv);
void 	sort_tab(t_tools *t);
void 	print_tab_sorted(t_tools *t);
void 	print_tab_not_sorted(t_tools *t);
void 	add_indexes_to_list(t_tools *t);
void 	print_stack_a(t_tools *t);
void 	print_stack_b(t_tools *t);
int		sort_stack_two_elems(t_tools *t);
void 	sort_stack_three_elems(t_tools *t);
int		find_median(t_tools *t);
void	sort_all(t_tools *t);
void 	sort_median_b_cycle(t_tools *t, int length);
void 	sort_stack_three_elems(t_tools *t);
int 	sort_stack_two_elems_b(t_tools *t);
void 	sort_stack_three_elems_b(t_tools *t);
int		check_if_sorted_a(t_tools *t);
int		check_if_sorted_b(t_tools *t);
void	sort_median_a(t_tools *t);
void	sort_median_b(t_tools *t);
void	sort_five(t_tools *t);
void check_tail_ab(t_tools *t, int len);

#endif