#include "../includes/push_swap.h"

void	rotate_a(t_tools *t)
{
	t_list *tmp1;
	t_list *lst;

	tmp1 = NULL;
	lst = NULL;
	if (t->tail_a)
	{
		tmp1 = t->tail_a;
		lst = ft_lstadd_front(&(t->head_a), &(t->tail_a));
		lst->order = t->tail_a->order;
		t->head_a = lst;
		t->tail_a = t->tail_a->prev;
		if (t->tail_a)
			t->tail_a->next = NULL;
		free(tmp1);
	}
	t->c = ft_lstadd_back(&(t->head_c), &(t->tail_c));
	t->c->content = "ra";
}

void	rotate_ab(t_tools *t)
{
	t_list *tmp1;
	t_list *tmp;
	t_list *lst;

	tmp1 = NULL;
	tmp = NULL;
	lst = NULL;

	if (t->tail_a && t->tail_b)
	{
		tmp = t->tail_a;
		lst = ft_lstadd_front(&(t->head_a), &(t->tail_a));
		lst->order = t->tail_a->order;
		t->head_a = lst;
		t->tail_a = (t->tail_a)->prev;
		if (t->tail_a)
			(t->tail_a)->next = NULL;
		free(tmp);
		tmp1 = t->tail_b;
		lst = ft_lstadd_front(&(t->head_b),&(t->tail_b));
		lst->order = (t->tail_b)->order;
		t->head_b = lst;
		t->tail_b = (t->tail_b)->prev;
		if (t->tail_b)
			(t->tail_b)->next = NULL;
		free(tmp1);
	}
	t->c = ft_lstadd_back(&(t->head_c), &(t->tail_c));
	t->c->content = "rr";
}

void	reverse_rotate_a(t_tools *t)
{
	t_list *tmp1;
	t_list *lst;

	tmp1 = NULL;
	lst = NULL;

	if (t->tail_a)
	{
		tmp1 = t->head_a;
		lst = ft_lstadd_back(&(t->head_a), &(t->tail_a));
		lst->order = (t->head_a)->order;
		t->tail_a = lst;
		t->head_a = (t->head_a)->next;
		if (t->head_a)
			(t->head_a)->prev = NULL;
		free(tmp1);
	}
	t->c = ft_lstadd_back(&(t->head_c), &(t->tail_c));
	t->c->content = "rra";
}

void	reverse_rotate_b(t_tools *t)
{
	t_list *tmp1;
	t_list *lst;

	tmp1 = NULL;
	lst = NULL;
	if (t->tail_b)
	{
		tmp1 = t->head_b;
		lst = ft_lstadd_back(&(t->head_b),&(t->tail_b));
		lst->order = (t->head_b)->order;
		t->tail_b = lst;
		t->head_b = (t->head_b)->next;
		if (t->head_b)
			(t->head_b)->prev = NULL;
		free(tmp1);
	}
	t->c = ft_lstadd_back(&(t->head_c), &(t->tail_c));
	t->c->content = "rrb";
}

void	reverse_rotate_ab(t_tools *t)
{
	t_list *tmp1;
	t_list *tmp;
	t_list *lst;

	tmp1 = NULL;
	tmp = NULL;
	lst = NULL;

	if (t->tail_b && t->tail_a)
	{
		tmp = t->head_a;
		lst = ft_lstadd_back(&(t->head_a), &(t->tail_a));
		lst->order = (t->head_a)->order;
		t->tail_a = lst;
		t->head_a = (t->head_a)->next;
		if (t->head_a)
			(t->head_a)->prev = NULL;
		free(tmp);
		tmp1 = t->head_b;
		lst = ft_lstadd_back(&(t->head_b),&(t->tail_b));
		lst->order = (t->head_b)->order;
		t->tail_b = lst;
		t->head_b = (t->head_b)->next;
		if (t->head_b)
			(t->head_b)->prev = NULL;
		free(tmp1);
	}
	t->c = ft_lstadd_back(&(t->head_c), &(t->tail_c));
	t->c->content = "rrr";
}