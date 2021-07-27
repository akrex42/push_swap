#include "../includes/push_swap.h"

int 	sort_stack_two_elems(t_tools *t)
{
	if (t->tail_a->prev && t->tail_a->content > t->tail_a->prev->content)
		swap_a(t);
	else
		return (1);
	return (0);
}

void 	sort_stack_three_elems(t_tools *t)
{
	t->a = t->head_a;

	if (sort_stack_two_elems(t) == 1)
	{}
	else if (t->a->content < t->a->next->next->content)
	{
		reverse_rotate_a(t);
//		print_stack_a(t->a, t->head_a);
		sort_stack_two_elems(t);
	}
	else if (t->a->content > t->a->next->next->content && t->a->content < t->a->next->content)
	{
		rotate_a(t);
//		print_stack_a(t->a, t->head_a);
		sort_stack_two_elems(t);
//		print_stack_a(t->a, t->head_a);
		reverse_rotate_a(t);
	}
}

int 	sort_stack_two_elems_b(t_tools *t)
{
	if (t->tail_b->prev && t->tail_b->content < t->tail_b->prev->content)
		swap_b(t);
	else
		return (1);
	return (0);
}

void 	sort_stack_three_elems_b(t_tools *t)
{
	t->b = t->head_b;

	if (sort_stack_two_elems_b(t) == 1)
	{}
	else if (t->b->content > t->b->next->next->content)
	{
		reverse_rotate_b(t);
//		print_stack_a(t->a, t->head_a);
		sort_stack_two_elems_b(t);
	}
	else if (t->b->content < t->b->next->next->content && t->b->content > t->b->next->content)
	{
		rotate_b(t);
//		print_stack_a(t->a, t->head_a);
		sort_stack_two_elems_b(t);
//		print_stack_a(t->a, t->head_a);
		reverse_rotate_b(t);
	}
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
	max = t->a->content;
	min = t->a->content;
	len = ft_lstsize(t->a);
	while (i < len && t->a)
	{
		if (max < t->a->content)
			max = t->a->content;
		if (min > t->a->content)
			min = t->a->content;
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
	max = t->b->content;
	min = t->b->content;
	len = ft_lstsize(t->b);
	while (i < len && t->b)
	{
		if (max < t->b->content)
			max = t->b->content;
		if (min > t->b->content)
			min = t->b->content;
		t->b = t->b->next;
		i++;
	}
	median = (max + min) / 2;
	return (median);
}

void sort_all(t_tools *t)
{
	int median;
	int len;
	int i;

	while (1)
	{
		median = find_median_a(t);
		t->a = t->head_a;
		i = 0;
		len = ft_lstsize(t->a);
		t->a = t->tail_a;
		while (i < len && t->a)
		{
			t->a = t->tail_a;
			if (median >= (t->a)->content)
				push_b(t);
//			else if (median > (t->head_a)->content)
//				reverse_rotate_a(t);
			else if (median < (t->a)->content)
				rotate_a(t);
			t->a = (t->a)->prev;
			i++;
		}
		t->a = t->head_a;
		if (ft_lstsize(t->a) <= 3)
		{
			sort_stack_three_elems(t);
			break ;
		}
	}
	print_stack_a(t);
	print_stack_b(t);
	while (1)
	{
		median = find_median_b(t);
		t->b = t->head_b;
		i = 0;
		len = ft_lstsize(t->b);
		t->b = t->tail_b;
		while (i < len && t->b)
		{
			t->b = t->tail_b;
			if (median <= (t->b)->content)
				push_a(t);
//			else if (median > (t->head_b)->content)
//				reverse_rotate_b(t);
			else if (median > (t->b)->content)
				rotate_b(t);
			t->b = (t->b)->prev;
			i++;
		}
		t->b = t->head_b;
//		ft_putnbr_fd((t->b)->content, 1);
		if (ft_lstsize(t->b) <= 3)
		{
//			ft_putnbr_fd((t->b)->content, 1);
			sort_stack_three_elems_b(t);
//			ft_putnbr_fd((t->b)->content, 1);
			t->b = t->head_b;
			while (1)
			{
				if (t->head_b)
					push_a(t);
				else
					break ;
			}
			break ;
		}

	}

}