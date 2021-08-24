#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_tools	t;

	check_args(argc);
	init_struct_tools(&t);
	create_two_tabs(&t, argv, argc);
	sort_tab(&t);
	add_indexes_to_list(&t);
	sort_all(&t);
	change_stack_c(&t);
	print_stack_c(&t);
	free_items(&t, argc);
	return (0);
}
