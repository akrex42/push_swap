#include "../includes/push_swap.h"

void	rotate_b(t_tools *t)
{
	t_list *tmp1;
	t_list *lst;

	tmp1 = NULL;
	lst = NULL;

	if (t->tail_b)
	{
		tmp1 = t->tail_b;
		lst = ft_lstadd_front(&(t->head_b), &(t->tail_b));
		lst->content = (t->tail_b)->content;
		t->head_b = lst;
		t->tail_b = (t->tail_b)->prev;
		if (t->tail_b)
			(t->tail_b)->next = NULL;
		free(tmp1);
		write(1, "rb", 2);
		write(1, "\n", 1);
	}
}

void 	init_struct_tools(t_tools *t, int argc)
{
	t->tab_sorted = malloc(sizeof(t->tab_sorted) * (argc - 2));
	t->tab_original = malloc(sizeof(t->tab_sorted) * (argc - 2));
	t->head_a = NULL;
	t->a = NULL;
	t->tail_a = NULL;
	t->head_b = NULL;
	t->tail_b = NULL;
	t->b = NULL;
}

void 	create_two_tabs(t_tools *t, char **argv, int argc)
{
	int	i;
	int j;

	j = 0;
	i = argc - 1;
	while (i > 0)
	{
		t->tab_sorted[j] = ft_atoi(argv[i]);
		i--;
		j++;
	}

	i = argc - 1;
	j = 0;
	while (i > 0)
	{
		t->tab_original[j] = ft_atoi(argv[i]);
		i--;
		j++;
	}
}

void 	sort_tab(t_tools *t, int argc)
{
	int j;
	int i;
	int	min;
	int index;
	int tmp;

	j = 0;

	while (j < argc - 1)
	{
		i = j;
		min = t->tab_sorted[j];
		index = j;
		while (i < argc - 1)
		{
			if (t->tab_sorted[i] < min)
			{
				min = t->tab_sorted[i];
				index = i;
			}
			i++;
		}
		tmp = t->tab_sorted[j];
		t->tab_sorted[j] = min;
		t->tab_sorted[index] = tmp;
		j++;
	}
}

void 	add_indexes_to_list(t_tools *t, int argc)
{
	int i;
	int j;

	i = 0;

	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (t->tab_original[i] == t->tab_sorted[j])
			{
				t->a = ft_lstadd_back(&(t->head_a), &(t->tail_a));
				t->a->content = j;
			}
			j++;
		}
		i++;
	}
}