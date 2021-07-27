#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_tools		t;

	init_struct_tools(&t, argc);

	// copy values to two tabs

	create_two_tabs(&t, argv, argc);

	// sort one tab_sorted

	sort_tab(&t, argc);

	// print tabs

//	print_tab_not_sorted(&t, argc);
//	print_tab_sorted(&t, argc);

	// add indexes to the list

	add_indexes_to_list(&t, argc);
//	ft_putchar_fd('h', 1);
	// print before any op

//	print_stack_a(&t);
//	print_stack_b(&t);

	// perform ops

//	push_b(&t);

//	sort_stack_two_elems(&t);
//	sort_stack_three_elems(&t);

	// print stacks
	sort_all(&t);
//	print_stack_a(&t);
//	print_stack_b(&t);
//	find_median(&t);

	// TODO circular list
	// TODO free
	// TODO pointers to head and tail

	return (0);
}