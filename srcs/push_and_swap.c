#include "../includes/push_swap.h"

void	push_b(t_tools *t)
{
	t_list	*tmp;

	tmp = NULL;
	if (t->tail_a)
	{
		tmp = t->tail_a;
		ft_lstadd_back(&(t->head_b), &(t->tail_b));
		(t->tail_b)->order = (t->tail_a)->order;
		t->tail_a = (t->tail_a)->prev;
		if (t->tail_a)
			(t->tail_a)->next = NULL;
		else
			t->head_a = NULL;
		free(tmp);
		t->c = ft_lstadd_back(&(t->head_c), &(t->tail_c));
		t->c->content = "pb";
	}
}

void	push_a(t_tools *t)
{
	t_list	*tmp;

	tmp = NULL;
	if (t->tail_b)
	{
		tmp = t->tail_b;
		ft_lstadd_back(&(t->head_a), &(t->tail_a));
		(t->tail_a)->order = (t->tail_b)->order;
		t->tail_b = (t->tail_b)->prev;
		if (t->tail_b)
			(t->tail_b)->next = NULL;
		else
			t->head_b = NULL;
		free(tmp);
		t->c = ft_lstadd_back(&(t->head_c), &(t->tail_c));
		t->c->content = "pa";
	}
}

void	swap_a(t_tools *t)
{
	int	tmp;

	if (t->tail_a && (t->tail_a)->prev)
	{
		tmp = (t->tail_a)->prev->order;
		(t->tail_a)->prev->order = (t->tail_a)->order;
		(t->tail_a)->order = tmp;
		t->c = ft_lstadd_back(&(t->head_c), &(t->tail_c));
		t->c->content = "sa";
	}
}

void	swap_b(t_tools *t)
{
	int	tmp;

	if (t->tail_b && (t->tail_b)->prev)
	{
		tmp = (t->tail_b)->prev->order;
		(t->tail_b)->prev->order = (t->tail_b)->order;
		(t->tail_b)->order = tmp;
		t->c = ft_lstadd_back(&(t->head_c), &(t->tail_c));
		t->c->content = "sb";
	}
}

void	swap_ab(t_tools *t)
{
	int	tmp;

	if (t->tail_b && (t->tail_b)->prev && t->tail_a && (t->tail_a)->prev)
	{
		tmp = (t->tail_b)->prev->order;
		(t->tail_b)->prev->order = (t->tail_b)->order;
		(t->tail_b)->order = tmp;
		tmp = (t->tail_a)->prev->order;
		(t->tail_a)->prev->order = (t->tail_a)->order;
		(t->tail_a)->order = tmp;
		t->c = ft_lstadd_back(&(t->head_c), &(t->tail_c));
		t->c->content = "ss";
	}
}
