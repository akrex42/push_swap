#include "../includes/push_swap.h"

/* Errors include for example: some arguments aren’t integers,
 * some arguments are
bigger than an integer, and/or there are duplicates.
 */

void	check_tail_ab(t_tools *t, int len)
{
	while (t->tail_a && t->tail_a->order == t->next
		&& ((check_if_sorted_a(t) != 0)
			|| (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
	{
		rotate_a(t);
		t->head_a->flag = 1000;
		t->next++;
	}
	while (t->tail_a->prev && t->tail_a->prev->order == t->next
		&& ((check_if_sorted_a(t) != 0)
			|| (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
	{
		if (t->tail_b && t->tail_b->prev
			&& t->tail_b->prev->order < t->tail_b->order)
			swap_ab(t);
		else
			swap_a(t);
		rotate_a(t);
		t->head_a->flag = 1000;
		t->next++;
	}
	check_tail_b(t, len);
	check_head_b(t);
	t->a = t->head_a;
	t->b = t->head_b;
}

void	flag_zero_part_2(t_tools *t, int len)
{
	while (t->head_a && t->head_a->flag != 1000)
	{
		if (t->tail_b && t->tail_b->order != t->next)
			reverse_rotate_ab(t);
		else
			reverse_rotate_a(t);
		t->tail_a->flag = 0;
	}
	check_tail_ab(t, len);
	while (t->head_b)
	{
		check_tail_ab(t, len);
		check_tail_ab(t, len);
		sort_median_b(t);
		check_tail_ab(t, len);
		check_tail_ab(t, len);
	}
}

void	flag_zero(t_tools *t, int len)
{
	int	max;
	int	min;
	int	median;

	t->a = t->tail_a;
	max = t->a->order;
	min = t->a->order;
	while (t->a->flag == t->flag)
	{
		if (max < t->a->order)
			max = t->a->order;
		if (min > t->a->order)
			min = t->a->order;
		t->a = t->a->prev;
	}
	median = (max + min) / 2;
	t->a = t->tail_a;
	while (t->tail_a->flag == t->flag)
	{
		if (median >= (t->tail_a)->order)
			push_b(t);
		else if (median < (t->tail_a)->order)
			rotate_a(t);
	}
	flag_zero_part_2(t, len);
}

void	flag_non_zero(t_tools *t, int len)
{
	check_tail_ab(t, len);
	while (t->tail_a->flag == t->flag)
	{
		push_b(t);
		check_tail_ab(t, len);
		check_tail_ab(t, len);
		check_tail_ab(t, len);
	}
	check_tail_ab(t, len);
	while (t->head_b)
	{
		check_tail_ab(t, len);
		sort_median_b(t);
		check_tail_ab(t, len);
	}
}

int	main(int argc, char **argv)
{
	t_tools	t;

	init_struct_tools(&t);
	create_two_tabs(&t, argv, argc);
	sort_tab(&t);
	add_indexes_to_list(&t);
//		print_stack_a(&t);
//		print_stack_b(&t);
	sort_all(&t);
//	print_stack_a(&t);
//	print_stack_b(&t);
//	change_stack_c(&t);
	print_stack_c(&t);
	free_items(&t, argc);
	return (0);
}

/* TODO error checking
   TODO checker
*/