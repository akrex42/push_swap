#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_tools		t;

	init_struct_tools(&t);

	// copy values to two tabs

	create_two_tabs(&t, argv, argc);

	// sort one tab_sorted

	sort_tab(&t);

	// print tabs

	// add indexes to the list

	add_indexes_to_list(&t);
	sort_all(&t);

	change_stack_c(&t);
	print_stack_c(&t);

	t.a = t.head_a;
	int i = argc - 1;
	while (i)
	{
		free(t.a);
		i--;
	}
	free(t.tab_original);
	free(t.tab_sorted);

	// TODO free

	return (0);
}