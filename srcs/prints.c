#include "../includes/push_swap.h"

void 	print_tab_sorted(t_tools *t, int argc)
{
	int i;

	i = 0;
	while (i < argc - 1)
	{
		ft_putnbr_fd(t->tab_sorted[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void 	print_tab_not_sorted(t_tools *t, int argc)
{
	int i;

	i = 0;
	while (i < argc - 1)
	{
		ft_putnbr_fd(t->tab_original[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void 	print_stack_a(t_list *a, t_list *head_a)
{
	a = head_a;

	while (a)
	{
		ft_putnbr_fd(a->content, 1);
		ft_putchar_fd(' ', 1);
		a = a->next;
	}
	ft_putchar_fd('\n', 1);
}

void 	print_stack_b(t_list *b, t_list *head_b)
{
	b = head_b;

	while (b)
	{
		ft_putnbr_fd(b->content, 1);
		ft_putchar_fd(' ', 1);
		b = b->next;
	}
	ft_putchar_fd('\n', 1);
}