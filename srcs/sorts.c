#include "../includes/push_swap.h"

int 	sort_stack_two_elems(t_tools *t)
{
	if (t->tail_a->prev && t->tail_a->order - t->tail_a->prev->order == 1)
	{
		swap_a(t);
		return (1);
	}
	else if (t->tail_a->prev == NULL)
		return (1);
	return (0);
}

void 	sort_stack_three_elems(t_tools *t)
{
	int flag_cycle = 0;

	t->a = t->tail_a;
	while (t->a->prev)
	{
		if (t->a->order != t->a->prev->order - 1)
		{
			flag_cycle = 1;
			break;
		}
		t->a = t->a->prev;
	}
	if (flag_cycle != 1)
		return ;
//	print_stack_a(t);
//	print_stack_b(t);

	t->a = t->head_a;
	if (sort_stack_two_elems(t) == 1 && t->a->next->next == NULL)
	{}
	else if ((t->a->next->next && t->a->order < t->a->next->next->order) || (t->a->next->next && t->a->order == t->a->next->next->order + 1))
	{
		reverse_rotate_a(t);
		sort_stack_two_elems(t);
	}
	else if (t->a->next->next && t->a->order > t->a->next->next->order && t->a->order < t->a->next->order)
	{
		rotate_a(t);
//		print_stack_a(t);
		sort_stack_two_elems(t);
	}
	else if (t->a->next->next && t->a->order > t->a->next->next->order && t->a->order < t->a->next->order)
	{
		rotate_a(t);
//		print_stack_a(t->a, t->head_a);
		sort_stack_two_elems(t);
//		print_stack_a(t->a, t->head_a);
		reverse_rotate_a(t);
	}
//	print_stack_a(t);
//	print_stack_b(t);
}

int 	sort_stack_two_elems_b(t_tools *t)
{
	if (t->tail_b->prev && t->tail_b->order > t->tail_b->prev->order)
	{
		swap_b(t);
		return (1);
	}
	else if (t->tail_b->prev == NULL)
	{
		return (1);
	}
	return (0);
}

void 	sort_stack_three_elems_b(t_tools *t)
{
	int flag_cycle = 0;

	t->b = t->tail_b;
	if (t->b == NULL)
		return ;
	while (t->b->prev)
	{
		if (t->b->order != t->b->prev->order + 1)
		{
			flag_cycle = 1;
			break;
		}
		t->b = t->b->prev;
	}
	if (flag_cycle == 1)
	{
		flag_cycle = 0;
	} else
		return ;

	t->b = t->head_b;

	if (sort_stack_two_elems_b(t) == 1 && t->b->next->next == NULL)
	{}
	else if ((t->b->next->next && t->b->order < t->b->next->next->order) || (t->b->next->next && t->b->order == t->b->next->next->order + 1))
	{
		reverse_rotate_b(t);
//		print_stack_a(t->a, t->head_a);
		sort_stack_two_elems_b(t);
	}
	else if (t->b->next->next && t->b->order > t->b->next->next->order && t->b->order < t->b->next->order)
	{
		rotate_b(t);
//		print_stack_a(t->a, t->head_a);
		sort_stack_two_elems_b(t);
//		print_stack_a(t->a, t->head_a);
		reverse_rotate_b(t);
	}
	if (t->tail_b)
	{
		while (t->tail_b && t->tail_b->order == t->next)
		{
			push_a(t);
			rotate_a(t);
			t->head_a->flag = 1000;
			t->next++;
		}
	}
}

int	find_median(t_tools *t)
{
	int	max;
	int	min;
	int	i;
	int len;

	i = 0;
	t->a = t->head_a;
	max = t->a->order;
	min = t->a->order;
	len = ft_lstsize(t->a);
	while (i < len && t->a)
	{
		if (max < t->a->order)
			max = t->a->order;
		if (min > t->a->order)
			min = t->a->order;
		t->a = t->a->next;
		i++;
	}
	return (max + min);
}

int	find_median_a(t_tools *t)
{
	int	max;
	int	min;
	int	i;
	int median;
	int len;

	i = 0;
	t->a = t->head_a;
	max = t->a->order;
	min = t->a->order;
	len = ft_lstsize(t->a);
	while (i < len && t->a)
	{
		if (max < t->a->order)
			max = t->a->order;
		if (min > t->a->order)
			min = t->a->order;
		t->a = t->a->next;
		i++;
	}
	median = (max + min) / 2;
	return (median);
}

int	find_median_b(t_tools *t)
{
	int	max;
	int	min;
	int	i;
	int median;
	int len;

	i = 0;
	t->b = t->head_b;
	max = t->b->order;
	min = t->b->order;
	len = ft_lstsize(t->b);
	while (i < len && t->b)
	{
		if (max < t->b->order)
			max = t->b->order;
		if (min > t->b->order)
			min = t->b->order;
		t->b = t->b->next;
		i++;
	}
	median = (max + min) / 2;
	return (median);
}

int check_if_sorted_a(t_tools *t)
{
	int flag_cycle = 0;

	t->a = t->tail_a;
	while (t->a->prev)
	{
		if (t->a->order != t->a->prev->order - 1)
		{
			flag_cycle = 1;
			break ;
		}
		t->a = t->a->prev;
	}
	t->a = t->tail_a;
	return (flag_cycle);
}

int check_if_sorted_b(t_tools *t)
{
	int flag_cycle = 0;

	t->b = t->tail_b;
	while (t->b->prev)
	{
		if (t->b->order != t->b->prev->order + 1)
		{
			flag_cycle = 1;
			break;
		}
		t->b = t->b->prev;
	}
	t->b = t->tail_b;
	return (flag_cycle);
}

void sort_median_a(t_tools *t)
{
	int median;
	int i = 0;
	int len;

	median = find_median_a(t);
	t->a = t->head_a;
	i = 0;
	len = ft_lstsize(t->a);
	t->a = t->tail_a;
	t->flag++;
	while (i < len && t->a)
	{
		t->a = (t->a)->prev;
		t->a = t->tail_a;
		if (median >= (t->a)->order)
		{
			push_b(t);
			t->tail_b->flag = t->flag;
		}
		else if ((t->a)->order && (t->a)->order == t->next)
		{
			rotate_a(t);
			t->head_a->flag = 1000;
			t->next++;
		}
		else if (median < (t->a)->order)
		{
			rotate_a(t);
			t->head_a->flag = 0;
		}
//		t->a = (t->a)->prev;
		i++;
		t->a = t->head_a;
	}
	if (ft_lstsize(t->a) <= 3)
	{
		sort_stack_three_elems(t);
	}
}

void sort_median_b(t_tools *t)
{
	int median;
	int i = 0;
	int len;

	if (t->b)
		len = ft_lstsize(t->b);
	else
		return ;
	median = find_median_b(t);
	t->flag++;
	t->b = t->head_b;
	check_tail_ab(t, len);
	while (t->b && i < len)
	{
		t->b = t->tail_b;
		if (t->b && median <= (t->b)->order)
		{
            push_a(t);
            t->tail_a->flag = t->flag;
            check_tail_ab(t, len);
        }
		else if (t->b && median > (t->b)->order)
		{
			rotate_b(t);
			t->head_b->flag = t->flag;
			check_tail_ab(t, len);
		}
		check_tail_ab(t, len);
		if (t->b)
			t->b = (t->b)->prev;
		else
			return ;
		i++;
		t->b = t->head_b;
		if (ft_lstsize(t->b) <= 3)
		{
			if (t->tail_b)
				sort_stack_three_elems_b(t);
			check_tail_ab(t, len);
		}
	}
}