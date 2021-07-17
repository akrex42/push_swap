#include "../includes/push_swap.h"

void	rotate_a(t_list **head_a, t_list **tail_a)
{
	t_list *tmp1;
	t_list *lst;

	tmp1 = NULL;
	lst = NULL;
	if (*tail_a)
	{
		tmp1 = *tail_a;
		lst = ft_lstadd_front(head_a, tail_a);
		lst->content = (*tail_a)->content;
		*head_a = lst;
		*tail_a = (*tail_a)->prev;
		if (*tail_a)
			(*tail_a)->next = NULL;
		free(tmp1);
		write(1, "ra", 2);
		write(1, "\n", 1);
	}
}

void	rotate_ab(t_list **head_a, t_list **tail_a, t_list **head_b, t_list **tail_b)
{
	t_list *tmp1;
	t_list *tmp;
	t_list *lst;

	tmp1 = NULL;
	tmp = NULL;
	lst = NULL;

	if (*tail_a && *tail_b)
	{
		tmp = *tail_a;
		lst = ft_lstadd_front(head_a, tail_a);
		lst->content = (*tail_a)->content;
		*head_a = lst;
		*tail_a = (*tail_a)->prev;
		if (*tail_a)
			(*tail_a)->next = NULL;
		free(tmp);
		tmp1 = *tail_b;
		lst = ft_lstadd_front(head_b, tail_b);
		lst->content = (*tail_b)->content;
		*head_b = lst;
		*tail_b = (*tail_b)->prev;
		if (*tail_b)
			(*tail_b)->next = NULL;
		free(tmp1);
		write(1, "rr", 2);
		write(1, "\n", 1);
	}
}

void	reverse_rotate_a(t_list **head_a, t_list **tail_a)
{
	t_list *tmp1;
	t_list *lst;

	tmp1 = NULL;
	lst = NULL;

	if (*tail_a)
	{
		tmp1 = *head_a;
		lst = ft_lstadd_back(head_a, tail_a);
		lst->content = (*head_a)->content;
		*tail_a = lst;
		*head_a = (*head_a)->next;
		if (*head_a)
			(*head_a)->prev = NULL;
		free(tmp1);
		write(1, "rra", 3);
		write(1, "\n", 1);
	}
}

void	reverse_rotate_b(t_list **head_b, t_list **tail_b)
{
	t_list *tmp1;
	t_list *lst;

	tmp1 = NULL;
	lst = NULL;
	if (*tail_b)
	{
		tmp1 = *head_b;
		lst = ft_lstadd_back(head_b, tail_b);
		lst->content = (*head_b)->content;
		*tail_b = lst;
		*head_b = (*head_b)->next;
		if (*head_b)
			(*head_b)->prev = NULL;
		free(tmp1);
		write(1, "rrb", 3);
		write(1, "\n", 1);
	}
}

void	reverse_rotate_ab(t_list **head_a, t_list **tail_a, t_list **head_b, t_list **tail_b)
{
	t_list *tmp1;
	t_list *tmp;
	t_list *lst;

	tmp1 = NULL;
	tmp = NULL;
	lst = NULL;

	if (*tail_b && *tail_a)
	{
		tmp = *head_a;
		lst = ft_lstadd_back(head_a, tail_a);
		lst->content = (*head_a)->content;
		*tail_a = lst;
		*head_a = (*head_a)->next;
		if (*head_a)
			(*head_a)->prev = NULL;
		free(tmp);
		tmp1 = *head_b;
		lst = ft_lstadd_back(head_b, tail_b);
		lst->content = (*head_b)->content;
		*tail_b = lst;
		*head_b = (*head_b)->next;
		if (*head_b)
			(*head_b)->prev = NULL;
		free(tmp1);
		write(1, "rrr", 3);
		write(1, "\n", 1);
	}
}