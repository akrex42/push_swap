#include "../includes/push_swap.h"

void	rotate_if_not_end_b(t_tools *t, int len)
{
	t->b = t->tail_b;
	rotate_b(t);
	t->b = t->tail_b;
	t->head_b->flag = t->flag;
	check_tail_ab(t, len);
}

int	check_till_the_end_b(t_tools *t, int median, int len)
{
	while (t->b)
	{
		if (t->b->order < median)
		{
			t->b = t->b->prev;
			continue ;
		}
		else
			break ;
	}
	if (t->b == NULL)
	{
		t->b = t->tail_b;
		while (t->b)
		{
			t->b->flag = t->flag;
			t->b = t->b->prev;
		}
		return (1);
	}
	else
		rotate_if_not_end_b(t, len);
	return (0);
}

void	main_cycle_b(t_tools *t, int median, int len, int i)
{
	while (t->b && i < len)
	{
		check_tail_ab(t, len);
		t->b = t->tail_b;
		if (t->b && median <= (t->b)->order)
		{
			push_a(t);
			t->tail_a->flag = t->flag;
			check_tail_ab(t, len);
		}
		else if (t->b && median > (t->b)->order && t->b->prev)
		{
			if (check_till_the_end_b(t, median, len) == 1)
				break ;
			check_tail_ab(t, len);
		}
		t->b = t->tail_b;
	}
}

void	sort_median_b(t_tools *t)
{
	int	median;
	int	len;
	int	i;

	i = 0;
	if (t->b)
		len = ft_lstsize(t->b);
	else
		return ;
	median = find_median_b(t);
	t->flag++;
	t->b = t->head_b;
	check_tail_ab(t, len);
	main_cycle_b(t, median, len, i);
}
