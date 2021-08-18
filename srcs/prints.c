#include "../includes/push_swap.h"

void 	print_tab_sorted(t_tools *t)
{
	int i;

	i = 0;
	while (i < t->size)
	{
		ft_putnbr_fd(t->tab_sorted[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void 	print_tab_not_sorted(t_tools *t)
{
	int i;

	i = 0;
	while (i < t->size)
	{
		ft_putnbr_fd(t->tab_original[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void 	print_stack_a(t_tools *t)
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

void 	print_stack_b(t_tools *t)
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

void 	change_stack_c(t_tools *t)
{
	t->c = t->head_c;
	while (t->c)
	{
		if (t->c->next)
		{
			if (!ft_strncmp(t->c->content, "pa", ft_strlen(t->c->content)))
			{
				if (!ft_strncmp(t->c->next->content, "pb", ft_strlen(t->c->next->content)))
				{
					if (t->c->prev && t->c->next->next)
					{
						t->c->prev->next = t->c->next->next;
						t->c->next->next->prev = t->c->prev;
//						t->c = t->c->prev;
//						t->c->next = t->c->next->next;
						free(t->c);
//						free(t->c->next);
						t->c = t->head_c;
					}
				}
			}
			if (!ft_strncmp(t->c->content, "pb", ft_strlen(t->c->content)))
			{
				if (!ft_strncmp(t->c->next->content, "pa", ft_strlen(t->c->next->content)))
				{
					if (t->c->prev && t->c->next->next)
					{
						t->c->prev->next = t->c->next->next;
						t->c->next->next->prev = t->c->prev;
						//						t->c = t->c->prev;
						//						t->c->next = t->c->next->next; // leaks possible
						free(t->c);
						//						free(t->c->next);
						t->c = t->head_c;
					}
				}
			}
			if (!ft_strncmp(t->c->content, "rb", ft_strlen(t->c->content)))
			{
				if (!ft_strncmp(t->c->next->content, "ra", ft_strlen(t->c->next->content)))
				{
					if (t->c->prev && t->c->next->next)
					{
						t->c->next->content = "rr";
						t->c->next->prev = t->c->prev;
						t->c->prev->next = t->c->next;
						//						t->c = t->c->prev;
						//						t->c->next = t->c->next->next; // leaks possible
						free(t->c);
						t->c = t->head_c;
					}
				}
			}
			else if (!ft_strncmp(t->c->content, "ra", ft_strlen(t->c->content)))
			{
				if (!ft_strncmp(t->c->next->content, "rb", ft_strlen(t->c->next->content)))
				{
					if (t->c->prev && t->c->next->next)
					{
						t->c->next->content = "rr";
						t->c->next->prev = t->c->prev;
						t->c->prev->next = t->c->next;
						//						t->c = t->c->prev;
						//						t->c->next = t->c->next->next; // leaks possible
						free(t->c);
						t->c = t->head_c;
					}
				}
			}
			else if (!ft_strncmp(t->c->content, "ra", ft_strlen(t->c->content)))
			{
				if (!ft_strncmp(t->c->next->content, "rb", ft_strlen(t->c->next->content)))
				{
					if (t->c->prev && t->c->next->next)
					{
						t->c->next->content = "rr";
						t->c->next->prev = t->c->prev;
						t->c->prev->next = t->c->next;
						//						t->c = t->c->prev;
						//						t->c->next = t->c->next->next; // leaks possible
						free(t->c);
						t->c = t->head_c;
					}
				}
			}
			else if (!ft_strncmp(t->c->content, "sa", ft_strlen(t->c->content)))
			{
				if (!ft_strncmp(t->c->next->content, "sb", ft_strlen(t->c->next->content)))
				{
					if (t->c->prev && t->c->next->next)
					{
						t->c->next->content = "ss";
						t->c->next->prev = t->c->prev;
						t->c->prev->next = t->c->next;
						//						t->c = t->c->prev;
						//						t->c->next = t->c->next->next; // leaks possible
						free(t->c);
						t->c = t->head_c;
					}
				}
			}
			else if (!ft_strncmp(t->c->content, "sb", ft_strlen(t->c->content)))
			{
				if (!ft_strncmp(t->c->next->content, "sa", ft_strlen(t->c->next->content)))
				{
					if (t->c->prev && t->c->next->next)
					{
						t->c->next->content = "ss";
						t->c->next->prev = t->c->prev;
						t->c->prev->next = t->c->next;
						//						t->c = t->c->prev;
						//						t->c->next = t->c->next->next; // leaks possible
						free(t->c);
						t->c = t->head_c;
					}
				}
			}
			else if (!ft_strncmp(t->c->content, "ra", ft_strlen(t->c->content)))
			{
				if (!ft_strncmp(t->c->next->content, "rra", ft_strlen(t->c->next->content)))
				{
					if (t->c->prev && t->c->next->next)
					{
						t->c->prev->next = t->c->next->next;
						t->c->next->next->prev = t->c->prev;
						//						t->c = t->c->prev;
						//						t->c->next = t->c->next->next; // leaks possible
						free(t->c);
						//						free(t->c->next);
						t->c = t->head_c;
					}
				}
			}
			else if (!ft_strncmp(t->c->content, "rra", ft_strlen(t->c->content)))
			{
				if (!ft_strncmp(t->c->next->content, "ra", ft_strlen(t->c->next->content)))
				{
					if (t->c->prev && t->c->next->next)
					{
						t->c->prev->next = t->c->next->next;
						t->c->next->next->prev = t->c->prev;
						//						t->c = t->c->prev;
						//						t->c->next = t->c->next->next; // leaks possible
						free(t->c);
						//						free(t->c->next);
						t->c = t->head_c;
					}
				}
			}
			else if (!ft_strncmp(t->c->content, "rb", ft_strlen(t->c->content)))
			{
				if (!ft_strncmp(t->c->next->content, "rrb", ft_strlen(t->c->next->content)))
				{
					if (t->c->prev && t->c->next->next)
					{
						t->c->prev->next = t->c->next->next;
						t->c->next->next->prev = t->c->prev;
						//						t->c = t->c->prev;
						//						t->c->next = t->c->next->next; // leaks possible
						free(t->c);
						//						free(t->c->next);
						t->c = t->head_c;
					}
				}
			}
			else if (!ft_strncmp(t->c->content, "rrb", ft_strlen(t->c->content)))
			{
				if (!ft_strncmp(t->c->next->content, "rb", ft_strlen(t->c->next->content)))
				{
					if (t->c->prev && t->c->next->next)
					{
						t->c->prev->next = t->c->next->next;
						t->c->next->next->prev = t->c->prev;
						//						t->c = t->c->prev;
						//						t->c->next = t->c->next->next; // leaks possible
						free(t->c);
						//						free(t->c->next);
						t->c = t->head_c;
					}
				}
			}
		}
		t->c = t->c->next;
	}
	t->c = t->head_c;
}

void 	print_stack_c(t_tools *t)
{
	t->c = t->head_c;
	int i = 0;
	int len = ft_lstsize(t->head_c);
	while (t->c && i < len)
	{
		ft_putstr_fd((char *)t->c->content, 1);
		ft_putchar_fd('\n', 1);
		t->c = t->c->next;
		i++;
	}
	t->c = t->head_c;
}