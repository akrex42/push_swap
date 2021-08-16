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
		lst->order = (t->tail_b)->order;
		t->head_b = lst;
		t->tail_b = (t->tail_b)->prev;
		if (t->tail_b)
			(t->tail_b)->next = NULL;
		free(tmp1);

//		t->c = ft_lstadd_front(&(t->head_c), &(t->tail_c));
//		t->c->content = "rb";
		write(1, "rb", 2);
		write(1, "\n", 1);
//		write(1, "\n", 1);
	}
}

void 	init_struct_tools(t_tools *t)
{
	t->head_a = NULL;
	t->a = NULL;
	t->tail_a = NULL;
	t->head_b = NULL;
	t->tail_b = NULL;
	t->b = NULL;
	t->next = 1;
	t->flag = 0;
}

void 	create_two_tabs(t_tools *t, char **argv, int argc)
{
	int	i;
	int j;
	char **splitted;
	(void)argc;
	j = 0;
	i = 0;
	splitted = ft_split(argv[1], ' ');
//	ft_putstr_fd(argv[1], 1);
	while (splitted[i] != NULL)
	{
//		ft_putendl_fd(splitted[i]);
		i++;
	}
	t->size = i - 1;
	t->tab_sorted = malloc(sizeof(t->tab_sorted) * (i));
	t->tab_original = malloc(sizeof(t->tab_sorted) * (i));
	i--;
	while (i >= 0)
	{
		t->tab_sorted[j] = ft_atoi(splitted[i]);
//		ft_putnbr_fd(t->tab_sorted[j], 1);
		i--;
		j++;
	}
	i = t->size;
	j = 0;
	while (i >= 0)
	{
		t->tab_original[j] = ft_atoi(splitted[i]);
		i--;
		j++;
	}
}

void 	sort_tab(t_tools *t)
{
	int j;
	int i;
	int	min;
	int index;
	int tmp;

	j = 0;

	while (j <= t->size)
	{
		i = j;
		min = t->tab_sorted[j];
		index = j;
		while (i <= t->size)
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

void 	add_indexes_to_list(t_tools *t)
{
	int i;
	int j;

	i = 0;

	while (i <= t->size)
	{
		j = 0;
		while (j <= t->size)
		{
			if (t->tab_original[i] == t->tab_sorted[j])
			{
				t->a = ft_lstadd_back(&(t->head_a), &(t->tail_a));
				t->a->order = j + 1;
				t->a->flag = 0;
			}
			j++;
		}
		i++;
	}
}