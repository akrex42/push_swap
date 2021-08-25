#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <limits.h>
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
	t_list		*head_c;
	t_list		*tail_c;
	t_list		*c;
	int			size;
	int			flag;
	int			next;
	int			flag_rotate;

}	t_tools;

void	push_b(t_tools *t);
void	push_a(t_tools *t);
void	swap_a(t_tools *t);
void	swap_b(t_tools *t);
void	swap_ab(t_tools *t);
void	rotate_b(t_tools *t);
void	rotate_a(t_tools *t);
void	rotate_ab(t_tools *t);
void	reverse_rotate_a(t_tools *t);
void	reverse_rotate_b(t_tools *t);
void	reverse_rotate_ab(t_tools *t);
void	init_struct_tools(t_tools *t);
void	create_two_tabs(t_tools *t, char **argv, int argc);
void	sort_tab(t_tools *t);
void	print_tab_sorted(t_tools *t);
void	print_tab_not_sorted(t_tools *t);
void	add_indexes_to_list(t_tools *t);
void	print_stack_a(t_tools *t);
void	print_stack_b(t_tools *t);
int		sort_stack_two_elems(t_tools *t);
void	sort_stack_three_elems(t_tools *t);
void	sort_all(t_tools *t);
void	sort_median_b_cycle(t_tools *t, int length);
void	sort_stack_three_elems(t_tools *t);
int		sort_stack_two_elems_b(t_tools *t);
void	sort_stack_three_elems_b(t_tools *t);
int		check_if_sorted_a(t_tools *t);
int		check_if_sorted_b(t_tools *t);
void	sort_median_a(t_tools *t);
void	sort_median_b(t_tools *t);
void	check_tail_ab(t_tools *t, int len);
void	print_stack_c(t_tools *t);
void	change_stack_c(t_tools *t);
void	free_items(t_tools *t, int argc);
void	sort_median_a(t_tools *t);
void	sort_median_b(t_tools *t);
int		find_median_b(t_tools *t);
int		find_median_a(t_tools *t);
void	check_order_b(t_tools *t);
void	check_order_a(t_tools *t);
void	check_tail_b(t_tools *t, int len);
void	check_tail_a(t_tools *t, int len);
void	check_head_b(t_tools *t);
void	flag_zero(t_tools *t, int len);
void	flag_non_zero(t_tools *t, int len);
int		check_pb_pa_1(t_tools *t);
int		check_pb_pa_2(t_tools *t);
int		check_sb_sa_1(t_tools *t);
int		check_sb_sa_2(t_tools *t);
int		check_rb_rrb_1(t_tools *t);
int		check_rb_rrb_2(t_tools *t);
int		check_ra_rra_1(t_tools *t);
int		check_ra_rra_2(t_tools *t);
int		check_rb_ra_1(t_tools *t);
int		check_rb_ra_2(t_tools *t);
void	sort(t_tools *t, int len);
void	still_to_sort(t_tools *t, int len);
void	flag_zero_cycle(t_tools *t, int median);
void	swap(t_tools *t, int index, int j, int min);
void	check_args(int argc);
void	flag_non_zero(t_tools *t, int len);
void	flag_zero(t_tools *t, int len);
void	check_for_five(t_tools *t);
int		main_cycle_read(char *buf, char **line);
int		checks_for_cycle_b(t_tools *t, int len, int i);
void	ft_error(char *line);
int		get_next_line(char **line);
void	sort_median_b(t_tools *t);

#endif