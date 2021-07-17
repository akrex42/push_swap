#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_list		*head_a = NULL;
	t_list		*a = NULL;
	t_list 		*tail_a = NULL;
	t_list		*head_b = NULL;
//	t_list 		*tail_b = NULL;
	t_list 		*b = NULL;
	t_tools		t;

	init_struct_tools(&t, argc);

	// copy values to two tabs

	create_two_tabs(&t, argv, argc);

	// sort one tab_sorted

	sort_tab(&t, argc);

	// print tabs

	print_tab_not_sorted(&t, argc);
//	print_tab_sorted(&t, argc);

	// add indexes to the list

	add_indexes_to_list(&t, &head_a, &a, &tail_a, argc);

	// print before any op

	print_stack_a(a, head_a);
	print_stack_b(b, head_b);

	// perform ops

//	push_b(&head_a, &head_b, &tail_a, &tail_b);
//	push_b(&head_a, &head_b, &tail_a, &tail_b);
//	sort_stack_two_elems(&a, &head_a, &tail_a);
	sort_stack_three_elems(&a, &head_a, &tail_a);

	// print stacks

	print_stack_a(a, head_a);
	print_stack_b(b, head_b);

	// TODO circular list
	// TODO free
	// TODO pointers to head and tail

	return (0);
}