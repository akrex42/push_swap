#include "../includes/push_swap.h"

int	check_pb_pa_2(t_tools *t)
{
	if (!ft_strncmp(t->c->content, "pb", ft_strlen(t->c->content)))
	{
		if (!ft_strncmp(t->c->next->content, "pa",
				ft_strlen(t->c->next->content)))
		{
			if (t->c->prev && t->c->next->next)
			{
				t->c->prev->next = t->c->next->next;
				t->c->next->next->prev = t->c->prev;
				free(t->c->next);
				free(t->c);
				t->c = t->head_c;
				return (1);
			}
		}
	}
	return (0);
}

int	check_pb_pa_1(t_tools *t)
{
	if (!ft_strncmp(t->c->content, "pa", ft_strlen(t->c->content)))
	{
		if (!ft_strncmp(t->c->next->content, "pb",
				ft_strlen(t->c->next->content)))
		{
			if (t->c->prev && t->c->next->next)
			{
				t->c->prev->next = t->c->next->next;
				t->c->next->next->prev = t->c->prev;
				free(t->c->next);
				free(t->c);
				t->c = t->head_c;
				return (1);
			}
		}
	}
	return (0);
}

int	check_rb_ra_1(t_tools *t)
{
	if (!ft_strncmp(t->c->content, "ra", ft_strlen(t->c->content)))
	{
		if (!ft_strncmp(t->c->next->content, "rb",
				ft_strlen(t->c->next->content)))
		{
			if (t->c->prev && t->c->next->next)
			{
				t->c->next->content = "rr";
				t->c->next->prev = t->c->prev;
				t->c->prev->next = t->c->next;
				free(t->c);
				t->c = t->head_c;
				return (1);
			}
		}
	}
	return (0);
}

int	check_rb_ra_2(t_tools *t)
{
	if (!ft_strncmp(t->c->content, "rb", ft_strlen(t->c->content)))
	{
		if (!ft_strncmp(t->c->next->content, "ra",
				ft_strlen(t->c->next->content)))
		{
			if (t->c->prev && t->c->next->next)
			{
				t->c->next->content = "rr";
				t->c->next->prev = t->c->prev;
				t->c->prev->next = t->c->next;
				free(t->c);
				t->c = t->head_c;
				return (1);
			}
		}
	}
	return (0);
}

int	check_sb_sa_1(t_tools *t)
{
	if (!ft_strncmp(t->c->content, "sa", ft_strlen(t->c->content)))
	{
		if (!ft_strncmp(t->c->next->content, "sb",
				ft_strlen(t->c->next->content)))
		{
			if (t->c->prev && t->c->next->next)
			{
				t->c->next->content = "ss";
				t->c->next->prev = t->c->prev;
				t->c->prev->next = t->c->next;
				free(t->c);
				t->c = t->head_c;
				return (1);
			}
		}
	}
	return (0);
}
