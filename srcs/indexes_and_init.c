#include "../includes/push_swap.h"

void	init_struct_tools(t_tools *t)
{
	t->head_a = NULL;
	t->a = NULL;
	t->tail_a = NULL;
	t->head_b = NULL;
	t->tail_b = NULL;
	t->b = NULL;
	t->next = 1;
	t->flag = 0;
	t->head_c = NULL;
	t->c = NULL;
	t->tail_c = NULL;
	t->flag_rotate = 0;
}

void	create_two_tabs(t_tools *t, char **argv, int argc)
{
	int	i;
	int	j;

	j = 0;
	t->size = argc - 1;
	i = t->size;
	t->tab_sorted = malloc(sizeof(t->tab_sorted) * (t->size));
	t->tab_original = malloc(sizeof(t->tab_sorted) * (t->size));
	while (i > 0)
	{
		t->tab_sorted[j] = ft_atoi(argv[i]);
		i--;
		j++;
	}
	i = t->size;
	j = 0;
	while (i > 0)
	{
		t->tab_original[j] = ft_atoi(argv[i]);
		i--;
		j++;
	}
}

void	swap(t_tools *t, int index, int j, int min)
{
	int	tmp;

	tmp = t->tab_sorted[j];
	t->tab_sorted[j] = min;
	t->tab_sorted[index] = tmp;
}

void	sort_tab(t_tools *t)
{
	int	j;
	int	i;
	int	min;
	int	index;

	j = 0;
	while (j < t->size)
	{
		i = j;
		min = t->tab_sorted[j];
		index = j;
		while (i < t->size)
		{
			if (t->tab_sorted[i] < min)
			{
				min = t->tab_sorted[i];
				index = i;
			}
			i++;
		}
		swap(t, index, j, min);
		j++;
	}
}

void	add_indexes_to_list(t_tools *t)
{
	int	i;
	int	j;

	i = 0;
	while (i < t->size)
	{
		j = 0;
		while (j < t->size)
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
