#include "../includes/push_swap.h"

void	check_line(t_tools *t, char *line)
{
	if (!ft_strncmp(line, "sa", 3))
		swap_a(t);
	else if (!ft_strncmp(line, "sb", 3))
		swap_b(t);
	else if (!ft_strncmp(line, "ss", 3))
		swap_ab(t);
	else if (!ft_strncmp(line, "pa", 3))
		push_a(t);
	else if (!ft_strncmp(line, "pb", 3))
		push_b(t);
	else if (!ft_strncmp(line, "ra", 3))
		rotate_a(t);
	else if (!ft_strncmp(line, "rb", 3))
		rotate_b(t);
	else if (!ft_strncmp(line, "rr", 3))
		rotate_ab(t);
	else if (!ft_strncmp(line, "rra", 4))
		reverse_rotate_a(t);
	else if (!ft_strncmp(line, "rrb", 4))
		reverse_rotate_b(t);
	else if (!ft_strncmp(line, "rrr", 4))
		reverse_rotate_ab(t);
	else
		ft_error(line);
}

void	main_cycle_checker(t_tools *t, char *line)
{
	int	res;

	res = 0;
	while (1)
	{
		res = get_next_line(&line);
		if (res == 2)
			ft_error(line);
		if (res == 0)
		{
			free(line);
			break ;
		}
		check_line(t, line);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	char	*line;
	t_tools	t;

	line = NULL;
	check_args(argc);
	init_struct_tools(&t);
	create_two_tabs(&t, argv, argc);
	sort_tab(&t);
	add_indexes_to_list(&t);
	main_cycle_checker(&t, line);
	if (check_if_sorted_a(&t) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_items(&t, argc);
}
