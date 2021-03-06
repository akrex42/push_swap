#include "../includes/push_swap.h"

void	sort(t_tools *t, int len)
{
	check_tail_ab(t, len);
	if ((check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)
		|| (check_if_sorted_a(t) != 0))
	{
		if (t->tail_a && ((check_if_sorted_a(t) != 0)
				|| (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
			still_to_sort(t, len);
		check_tail_ab(t, len);
	}
	check_tail_ab(t, len);
}

void	swap(t_tools *t, int index, int j, int min)
{
	int	tmp;

	tmp = t->tab_sorted[j];
	t->tab_sorted[j] = min;
	t->tab_sorted[index] = tmp;
}

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
		swap_a(t);
		rotate_a(t);
		t->head_a->flag = 1000;
		t->next++;
	}
	check_tail_b(t, len);
	t->a = t->head_a;
	t->b = t->head_b;
}

void	check_args(int argc)
{
	if (argc == 1)
		exit (-1);
}
