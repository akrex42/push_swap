#include "../includes/push_swap.h"

void	rotate_while_checking(t_tools *t, int len)
{
	swap_ab(t);
	while (t->tail_a && t->tail_a->order
		== t->next && ((check_if_sorted_a(t) != 0)
			|| (check_if_sorted_a(t) == 0
				&& ft_lstsize(t->head_a) != len)))
	{
		if (t->tail_b->prev && t->tail_b->prev->order == t->next)
			swap_b(t);
		rotate_a(t);
		t->head_a->flag = 1000;
		t->next++;
	}
}

void	check_tail_b(t_tools *t, int len)
{
	(void)len;
	if (t->tail_b)
	{
		while (t->tail_b && t->tail_b->order == t->next)
		{
			push_a(t);
			rotate_a(t);
			t->head_a->flag = 1000;
			t->next++;
		}
	}
}

void	rotate_b(t_tools *t)
{
	t_list	*tmp1;
	t_list	*lst;

	tmp1 = NULL;
	lst = NULL;
	if (t->tail_b)
	{
		tmp1 = t->tail_b;
		lst = ft_lstadd_front(&(t->head_b), &(t->tail_b));
		lst->order = (t->tail_b)->order;
		lst->flag = (t->tail_b)->flag;
		t->head_b = lst;
		t->tail_b = (t->tail_b)->prev;
		if (t->tail_b)
			(t->tail_b)->next = NULL;
		free(tmp1);
		if (t->flag_rotate == 0)
		{
			t->c = ft_lstadd_back(&(t->head_c), &(t->tail_c));
			t->c->content = "rb";
		}
	}
}

int	check_if_sorted_a(t_tools *t)
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
	t->a = t->tail_a;
	return (flag_cycle);
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
