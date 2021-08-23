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

void	main_cycle_a(t_tools *t, int median, int len, int i)
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
		else if (median < (t->a)->order && t->a->prev)
		{
			rotate_a(t);
			t->head_a->flag = 0;
		}
		else if (median < (t->a)->order && t->a->prev == NULL)
		{
			t->head_a->flag = 0;
			break ;
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
	main_cycle_a(t, median, len, i);
	if (ft_lstsize(t->a) <= 3)
		sort_stack_three_elems(t);
}

void	main_cycle_b(t_tools *t, int median, int len, int i)
{
	while (t->b && i < len)
	{
		t->b = t->tail_b;
		if (t->b && median <= (t->b)->order)
		{
			push_a(t);
			t->tail_a->flag = t->flag;
			check_tail_ab(t, len);
		}
		else if (t->b && median > (t->b)->order && t->b->prev)
		{
			rotate_b(t);
			t->head_b->flag = t->flag;
			check_tail_ab(t, len);
		}
		else if (t->b && median > (t->b)->order && t->b->prev == NULL)
		{
			t->head_b->flag = t->flag;
			break ;
		}
		i = checks_for_cycle_b(t, len, i);
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
