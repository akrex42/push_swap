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
		else if (median >= (t->head_a)->order)
		{
			reverse_rotate_a(t);
			push_b(t);
			t->tail_b->flag = t->flag;
		}
		else if (median < (t->a)->order && t->a->prev)
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
				break ;
			}
			else
			{
				t->a = t->tail_a;
				rotate_a(t);
				t->head_a->flag = 0;
			}
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
		check_tail_ab(t, len);
		t->b = t->tail_b;
		if (t->b && median <= (t->b)->order)
		{
			push_a(t);
			t->tail_a->flag = t->flag;
			check_tail_ab(t, len);
		}
		else if (t->b && t->head_b && median <= (t->head_b)->order && (t->head_b)->flag == (t->tail_b)->flag && ft_lstsize(t->head_b) <= 5)
		{
			reverse_rotate_b(t);
			push_a(t);
			t->tail_a->flag = t->flag;
			check_tail_ab(t, len);
		}
		else if (t->b && median > (t->b)->order && t->b->prev)
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
				break ;
			}
			else
			{
				t->b = t->tail_b;
				rotate_b(t);
				t->head_b->flag = t->flag;
			}
			check_tail_ab(t, len);
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
