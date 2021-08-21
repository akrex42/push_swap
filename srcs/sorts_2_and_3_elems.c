#include "../includes/push_swap.h"

int	sort_stack_two_elems(t_tools *t)
{
	if (t->tail_a->prev && t->tail_a->order - t->tail_a->prev->order == 1)
	{
		swap_a(t);
		return (1);
	}
	else if (t->tail_a->prev == NULL)
		return (1);
	return (0);
}

void	sort_stack_three_elems(t_tools *t)
{
	int	flag_cycle;

	flag_cycle = 0;
	t->a = t->tail_a;
	while (t->a->prev)
	{
		if (t->a->order != t->a->prev->order - 1)
		{
			flag_cycle = 1;
			break ;
		}
		t->a = t->a->prev;
	}
	if (flag_cycle != 1)
		return ;
	t->a = t->head_a;
	check_order_a(t);
}

int	sort_stack_two_elems_b(t_tools *t)
{
	if (t->tail_b->prev && t->tail_b->order > t->tail_b->prev->order)
	{
		swap_b(t);
		return (1);
	}
	else if (t->tail_b->prev == NULL)
	{
		return (1);
	}
	return (0);
}

void	sort_stack_three_elems_b(t_tools *t)
{
	int	flag_cycle;

	flag_cycle = 0;
	t->b = t->tail_b;
	if (t->b == NULL)
		return ;
	while (t->b->prev)
	{
		if (t->b->order != t->b->prev->order + 1)
		{
			flag_cycle = 1;
			break ;
		}
		t->b = t->b->prev;
	}
	if (flag_cycle != 1)
		return ;
	t->b = t->head_b;
	check_order_b(t);
}
