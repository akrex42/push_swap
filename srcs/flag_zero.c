#include "../includes/push_swap.h"

void	check_for_zero(t_tools *t)
{
	t->a = t->tail_a;
	rotate_a(t);
	t->head_a->flag = 0;
	t->a = t->tail_a;
}

int	check_till_the_end_zero(t_tools *t, int median)
{
	t->a = t->tail_a;
	while (t->a->flag != 1000)
	{
		if (t->a->order > median)
		{
			t->a = t->a->prev;
			continue ;
		}
		else
			break ;
	}
	if (t->a->flag == 1000)
	{
		t->a = t->tail_a;
		while (t->a->flag != 1000)
		{
			t->a->flag = 0;
			t->a = t->a->prev;
		}
		return (1);
	}
	else
		check_for_zero(t);
	return (0);
}

void	flag_zero_cycle(t_tools *t, int median)
{
	t->a = t->tail_a;
	while (t->a->flag == 0)
	{
		t->a = t->tail_a;
		if (median >= (t->a)->order)
		{
			push_b(t);
			t->tail_b->flag = 0;
			t->a = t->tail_a;
		}
		else if (median < (t->a)->order && t->a->prev)
		{
			if (check_till_the_end_zero(t, median) == 1)
				break ;
		}
		t->a = t->tail_a;
	}
}
