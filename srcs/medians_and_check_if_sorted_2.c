#include "../includes/push_swap.h"

int	find_median_a(t_tools *t)
{
	int	max;
	int	min;
	int	i;
	int	median;
	int	len;

	i = 0;
	t->a = t->head_a;
	max = t->a->order;
	min = t->a->order;
	len = ft_lstsize(t->a);
	while (i < len && t->a)
	{
		if (max < t->a->order)
			max = t->a->order;
		if (min > t->a->order)
			min = t->a->order;
		t->a = t->a->next;
		i++;
	}
	median = (max + min) / 2;
	return (median);
}

int	find_median_b(t_tools *t)
{
	int	max;
	int	min;
	int	i;
	int	median;
	int	len;

	i = 0;
	t->b = t->head_b;
	max = t->b->order;
	min = t->b->order;
	len = ft_lstsize(t->b);
	while (i < len && t->b)
	{
		if (max < t->b->order)
			max = t->b->order;
		if (min > t->b->order)
			min = t->b->order;
		t->b = t->b->next;
		i++;
	}
	median = (max + min) / 2;
	return (median);
}

void	check_order_b_2(t_tools *t)
{
	while (t->tail_b && t->tail_b->order == t->next)
	{
		push_a(t);
		rotate_a(t);
		t->head_a->flag = 1000;
		t->next++;
	}
}

void	check_order_b(t_tools *t)
{
	if (sort_stack_two_elems_b(t) == 1 && t->b->next->next == NULL)
	{
	}
	else if ((t->b->next->next && t->b->order < t->b->next->next->order)
		|| (t->b->next->next && t->b->order == t->b->next->next->order + 1))
	{
		reverse_rotate_b(t);
		sort_stack_two_elems_b(t);
	}
	else if (t->b->next->next && t->b->order > t->b->next->next->order
		&& t->b->order < t->b->next->order)
	{
		rotate_b(t);
		sort_stack_two_elems_b(t);
		reverse_rotate_b(t);
	}
	if (t->tail_b)
		check_order_b_2(t);
}

void	check_order_a(t_tools *t)
{
	if (sort_stack_two_elems(t) == 1 && t->a->next->next == NULL)
	{
	}
	else if ((t->a->next->next && t->a->order < t->a->next->next->order)
		|| (t->a->next->next && t->a->order == t->a->next->next->order + 1))
	{
		reverse_rotate_a(t);
		sort_stack_two_elems(t);
	}
	else if (t->a->next->next && t->a->order > t->a->next->next->order
		&& t->a->order < t->a->next->order)
	{
		rotate_a(t);
		sort_stack_two_elems(t);
	}
	else if (t->a->next->next && t->a->order > t->a->next->next->order
		&& t->a->order < t->a->next->order)
	{
		rotate_a(t);
		sort_stack_two_elems(t);
		reverse_rotate_a(t);
	}
}
