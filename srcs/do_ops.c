#include "../includes/push_swap.h"

void 	push_b(t_tools *t)
{
	t_list *tmp;

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
//		write(1, "p", 1);
//		t->c = ft_lstadd_front(&(t->head_c), &(t->tail_c));
//		t->c->content = "pb";
		write(1, "pb", 2);
		write(1, "\n", 1);
//		write(1, "\n", 1);
	}
}

void 	push_a(t_tools *t)
{
	t_list *tmp;

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

//		t->c = ft_lstadd_front(&(t->head_c), &(t->tail_c));
//		t->c->content = "pa";
		write(1, "pa", 2);
		write(1, "\n", 1);
//		write(1, "\n", 1);
	}
}

void	swap_a(t_tools *t)
{
	int tmp;

	if (t->tail_a && (t->tail_a)->prev)
	{
		tmp = (t->tail_a)->prev->order;
		(t->tail_a)->prev->order = (t->tail_a)->order;
		(t->tail_a)->order = tmp;

//		write(1, "\n", 1);
//		t->c = ft_lstadd_front(&(t->head_c), &(t->tail_c));
//		t->c->content = "sa";
		write(1, "sa", 2);
		write(1, "\n", 1);
	}
}

void	swap_b(t_tools *t)
{
	int tmp;

	if (t->tail_b && (t->tail_b)->prev)
	{
		tmp = (t->tail_b)->prev->order;
		(t->tail_b)->prev->order = (t->tail_b)->order;
		(t->tail_b)->order = tmp;

//		t->c = ft_lstadd_front(&(t->head_c), &(t->tail_c));
//		t->c->content = "sb";
		write(1, "sb", 2);
		write(1, "\n", 1);
	}
}

void	swap_ab(t_tools *t)
{
	int tmp;

	if (t->tail_b && (t->tail_b)->prev && t->tail_a && (t->tail_a)->prev)
	{
		tmp = (t->tail_b)->prev->order;
		(t->tail_b)->prev->order = (t->tail_b)->order;
		(t->tail_b)->order = tmp;
		tmp = (t->tail_a)->prev->order;
		(t->tail_a)->prev->order = (t->tail_a)->order;
		(t->tail_a)->order = tmp;
//
//		t->c = ft_lstadd_front(&(t->head_c), &(t->tail_c));
//		t->c->content = "ss";
		write(1, "ss", 2);
		write(1, "\n", 1);
	}
}