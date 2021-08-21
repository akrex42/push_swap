#include "../includes/push_swap.h"

void	still_to_sort(t_tools *t, int len)
{
	check_tail_ab(t, len);
	while (t->tail_a->flag != t->flag)
	{
		if (t->tail_a->flag == 1000)
			break ;
		if (t->flag == 0)
			break ;
		t->flag--;
	}
	check_tail_ab(t, len);
	if (t->flag != 0 && ((check_if_sorted_a(t) != 0)
			|| (check_if_sorted_a(t) == 0
				&& ft_lstsize(t->head_a) != len)))
		flag_non_zero(t, len);
	else if (t->tail_a->flag == 0 && t->flag == 0
		&& ((check_if_sorted_a(t) != 0)
			|| (check_if_sorted_a(t) == 0
				&& ft_lstsize(t->head_a) != len)))
		flag_zero(t, len);
	check_tail_ab(t, len);
}

void	main_cycle(t_tools *t, int len)
{
	while (t->next != len + 1)
	{
		if (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) == len)
			break ;
		check_tail_ab(t, len);
		if (((check_if_sorted_a(t) == 1)
				|| (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
		{
			check_tail_ab(t, len);
			sort(t, len);
			check_tail_ab(t, len);
		}
		check_tail_ab(t, len);
	}
}

void	size_thousand(t_tools *t)
{
	int	len;

	len = ft_lstsize(t->a);
	if (check_if_sorted_a(t) == 0)
		return ;
	sort_median_a(t);
	check_tail_ab(t, len);
	while (t->head_b)
	{
		check_tail_ab(t, len);
		check_tail_ab(t, len);
		sort_median_b(t);
		check_tail_ab(t, len);
		check_tail_ab(t, len);
	}
	if (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) == len)
		return ;
	main_cycle(t, len);
}

void	size_five(t_tools *t)
{
	int	len;

	len = ft_lstsize(t->a);
	if (check_if_sorted_a(t) == 0)
		return ;
	sort_median_a(t);
	t->b = t->head_b;
	if (ft_lstsize(t->b) <= 3)
	{
		sort_stack_three_elems_b(t);
		while (t->head_b)
		{
			check_tail_ab(t, len);
			push_a(t);
			check_tail_ab(t, len);
		}
	}
	while (check_if_sorted_a(t) != 0)
		check_tail_ab(t, len);
}

void	sort_all(t_tools *t)
{
//	print_stack_a(t);
//	print_stack_b(t);

	t->a = t->head_a;
	if (ft_lstsize(t->a) <= 3)
		sort_stack_three_elems(t);
	else if (ft_lstsize(t->a) <= 5)
		size_five(t);
	else if (ft_lstsize(t->a) <= 1000)
		size_thousand(t);
}
