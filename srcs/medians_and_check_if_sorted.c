#include "../includes/push_swap.h"

int	check_if_sorted_b(t_tools *t)
{
	int	flag_cycle;

	flag_cycle = 0;
	t->b = t->tail_b;
	while (t->b->prev)
	{
		if (t->b->order != t->b->prev->order + 1)
		{
			flag_cycle = 1;
			break ;
		}
		t->b = t->b->prev;
	}
	t->b = t->tail_b;
	return (flag_cycle);
}

void	rotate_if_not_end_a(t_tools *t)
{
	t->a = t->tail_a;
	rotate_a(t);
	t->a = t->tail_a;
	t->head_a->flag = 0;
}

int	check_till_the_end_a(t_tools *t, int median)
{
	while (t->a)
	{
		if (t->a->order > median)
		{
			t->a = t->a->prev;
			continue ;
		}
		else
			break ;
	}
	if (t->a == NULL)
	{
		t->a = t->tail_a;
		while (t->a)
		{
			t->a->flag = 0;
			t->a = t->a->prev;
		}
		return (1);
	}
	else
		rotate_if_not_end_a(t);
	return (0);
}

void	main_cycle_a(t_tools *t, int median, int len, int i)
{
	t->a = t->tail_a;
	while (i < len && t->a)
	{
		t->a = t->tail_a;
		if (median >= (t->head_a)->order)
		{
			reverse_rotate_a(t);
			push_b(t);
			t->tail_b->flag = t->flag;
		}
		else if (median >= (t->a)->order)
		{
			push_b(t);
			t->tail_b->flag = t->flag;
		}
		else if (median < (t->a)->order && t->a->prev)
		{
			if (check_till_the_end_a(t, median) == 1)
				break ;
		}
		i++;
		t->a = t->head_a;
	}
}

void	cycle_for_five(t_tools *t, int len, int median, int i)
{
	t->a = t->tail_a;
	while (i < len && t->a)
	{
		t->a = t->tail_a;
		if (median >= (t->a)->order)
		{
			push_b(t);
			t->tail_b->flag = t->flag;
		}
		else if (median < (t->a)->order)
		{
			rotate_a(t);
			t->a = t->tail_a;
			t->head_a->flag = 0;
		}
		i++;
		t->a = t->head_a;
	}
}

void	sort_median_a(t_tools *t)
{
	int	median;
	int	i;
	int	len;

	i = 0;
	median = find_median_a(t);
	t->a = t->head_a;
	len = ft_lstsize(t->a);
	t->a = t->tail_a;
	t->flag++;
	if (ft_lstsize(t->a) <= 5)
		cycle_for_five(t, len, median, i);
	else
		main_cycle_a(t, median, len, i);
	if (ft_lstsize(t->a) <= 3)
		sort_stack_three_elems(t);
}
