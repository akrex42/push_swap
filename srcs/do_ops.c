#include "../includes/push_swap.h"

void 	push_b(t_list **head_a, t_list **head_b, t_list **tail_a, t_list **tail_b)
{
	t_list *tmp;

	tmp = NULL;
	if (*tail_a)
	{
		tmp = *tail_a;
		ft_lstadd_back(head_b, tail_b);
		(*tail_b)->content = (*tail_a)->content;
		*tail_a = (*tail_a)->prev;
		if (*tail_a)
			(*tail_a)->next = NULL;
		else
			*head_a = NULL;
		free(tmp);
		write(1, "pb", 2);
		write(1, "\n", 1);
	}
}

void 	push_a(t_list **head_a, t_list **head_b, t_list **tail_a, t_list **tail_b)
{
	t_list *tmp;

	tmp = NULL;
	if (*tail_b)
	{
		tmp = *tail_b;
		ft_lstadd_back(head_a, tail_a);
		(*tail_a)->content = (*tail_b)->content;
		*tail_b = (*tail_b)->prev;
		if (*tail_b)
			(*tail_b)->next = NULL;
		else
			*head_b = NULL;
		free(tmp);
		write(1, "pa", 2);
		write(1, "\n", 1);
	}
}

void	swap_a(t_list **tail_a)
{
	int tmp;

	if (*tail_a && (*tail_a)->prev)
	{
		tmp = (*tail_a)->prev->content;
		(*tail_a)->prev->content = (*tail_a)->content;
		(*tail_a)->content = tmp;
		write(1, "sa", 2);
		write(1, "\n", 1);
	}
}

void	swap_b(t_list **tail_b)
{
	int tmp;

	if (*tail_b && (*tail_b)->prev)
	{
		tmp = (*tail_b)->prev->content;
		(*tail_b)->prev->content = (*tail_b)->content;
		(*tail_b)->content = tmp;
		write(1, "sb", 2);
		write(1, "\n", 1);
	}
}

void	swap_ab(t_list **tail_a, t_list **tail_b)
{
	int tmp;

	if (*tail_b && (*tail_b)->prev && *tail_a && (*tail_a)->prev)
	{
		tmp = (*tail_b)->prev->content;
		(*tail_b)->prev->content = (*tail_b)->content;
		(*tail_b)->content = tmp;
		tmp = (*tail_a)->prev->content;
		(*tail_a)->prev->content = (*tail_a)->content;
		(*tail_a)->content = tmp;
		write(1, "ss", 2);
		write(1, "\n", 1);
	}
}