#include "../includes/push_swap.h"

void	print_tab_sorted(t_tools *t)
{
	int	i;

	i = 0;
	while (i < t->size)
	{
		ft_putnbr_fd(t->tab_sorted[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void	print_tab_not_sorted(t_tools *t)
{
	int	i;

	i = 0;
	while (i < t->size)
	{
		ft_putnbr_fd(t->tab_original[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void	print_stack_a(t_tools *t)
{
	t->a = t->head_a;
	while (t->a)
	{
		ft_putnbr_fd(t->a->order, 1);
		ft_putchar_fd(' ', 1);
		t->a = t->a->next;
	}
	ft_putchar_fd('\n', 1);
	t->a = t->head_a;
}

void	print_stack_b(t_tools *t)
{
	t->b = t->head_b;
	while (t->b)
	{
		ft_putnbr_fd(t->b->order, 1);
		ft_putchar_fd(' ', 1);
		t->b = t->b->next;
	}
	ft_putchar_fd('\n', 1);
	t->b = t->head_b;
}

void	print_stack_c(t_tools *t)
{
	int	i;
	int	len;

	t->c = t->head_c;
	i = 0;
	len = ft_lstsize(t->head_c);
	while (t->c && i < len)
	{
		ft_putstr_fd((char *)t->c->content, 1);
		ft_putchar_fd('\n', 1);
		t->c = t->c->next;
		i++;
	}
	t->c = t->head_c;
}
