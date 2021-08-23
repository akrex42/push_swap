#include "../includes/push_swap.h"

void	free_items(t_tools *t, int argc)
{
	int		i;
	t_list	*to_free;

	t->a = t->head_a;
	i = argc - 1;
	while (i && t->a)
	{
		to_free = t->a;
		t->a = t->a->next;
		free(to_free);
		i--;
	}
	t->c = t->head_c;
	while (t->c)
	{
		to_free = t->c;
		t->c = t->c->next;
		free(to_free);
	}
	free(t->tab_original);
	free(t->tab_sorted);
}

void	change_stack_c(t_tools *t)
{
	t->c = t->head_c;
	while (t->c)
	{
		if (t->c->next)
		{
			check_pb_pa_1(t);
			check_pb_pa_2(t);
			if (check_rb_ra_1(t) == 0)
				check_rb_ra_2(t);
			else if (check_sb_sa_1(t) == 0)
				check_sb_sa_2(t);
			else if (check_ra_rra_1(t) == 0)
				check_ra_rra_2(t);
			else if (check_rb_rrb_1(t) == 0)
				check_rb_rrb_2(t);
		}
		t->c = t->c->next;
	}
	t->c = t->head_c;
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
	flag_zero_cycle(t, median);
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
