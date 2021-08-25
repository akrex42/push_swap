#include "../includes/push_swap.h"

void	rotate_if_not_end_b(t_tools *t, int len)
{
	t->b = t->tail_b;
	rotate_b(t);
	t->b = t->tail_b;
	t->head_b->flag = t->flag;
	check_tail_ab(t, len);
}

int	check_till_the_end_b(t_tools *t, int median, int len)
{
	while (t->b)
	{
		if (t->b->order < median)
		{
			t->b = t->b->prev;
			continue ;
		}
		else
			break ;
	}
	if (t->b == NULL)
	{
		t->b = t->tail_b;
		while (t->b)
		{
			t->b->flag = t->flag;
			t->b = t->b->prev;
		}
		return (1);
	}
	else
		rotate_if_not_end_b(t, len);
	return (0);
}

void	main_cycle_b(t_tools *t, int median, int len, int i)
{
	while (t->b && i < len)
	{
		check_tail_ab(t, len);
		t->b = t->tail_b;
		if (t->b && t->head_b && ft_lstsize(t->head_b) == 5)
		{
			int count = 0;
			t->b = t->tail_b;
			count = 0;

			while (t->b)
			{
				if (t->b->order == t->next)
					break ;
				count++;
				t->b = t->b->prev;
			}
			if (count < 3 && t->tail_b)
			{
				ft_putnbr_fd(t->next, 1);
				print_stack_b(t);
				while (t->tail_b->order != t->next)
				{
					if (t->tail_b->order == t->next)
						break ;
					rotate_b(t);
					print_stack_b(t);
				}
				push_a(t);
				rotate_a(t);
				t->head_a->flag = 1000;
				t->next++;
			}
			else
			{
				while (t->tail_b->order != t->next)
				{
					reverse_rotate_b(t);
				}
				push_a(t);
				rotate_a(t);
				t->head_a->flag = 1000;
				t->next++;
			}
			t->b = t->tail_b;
			if (t->tail_b && ((t->tail_b->prev && t->tail_b->order < t->tail_b->prev->order)
			|| (t->tail_b->prev == NULL)))
			{
				swap_b(t);
			}
			if (t->head_b && ((t->head_b->next->next && t->head_b->order > t->head_b->next->next->order)
			|| (t->head_b->next->next && t->head_b->order == t->head_b->next->next->order - 1)))
			{
				reverse_rotate_b(t);
				if (t->tail_b && t->tail_b->prev && t->tail_b->order < t->tail_b->prev->order)
				{
					swap_b(t);
				}
			}
			else if (t->head_b && t->head_b->next->next && t->head_b->order < t->head_b->next->next->order
			&& t->head_b->order > t->head_b->next->order)
			{
				rotate_b(t);
				if (t->tail_b && t->tail_b->prev && t->tail_b->order < t->tail_b->prev->order)
				{
					swap_b(t);
				}
				reverse_rotate_b(t);
			}
			while (t->head_b)
			{
				push_a(t);
				print_stack_b(t);
			}
			check_tail_ab(t, len);
		}
		else if (t->b && median <= (t->b)->order)
		{
			push_a(t);
			t->tail_a->flag = t->flag;
			check_tail_ab(t, len);
		}
		else if (t->b && median > (t->b)->order && t->b->prev)
		{
			if (check_till_the_end_b(t, median, len) == 1)
				break ;
			check_tail_ab(t, len);
		}
		t->b = t->tail_b;
	}
}

void	sort_median_b(t_tools *t)
{
	int	median;
	int	len;
	int	i;

	i = 0;
	if (t->b)
		len = ft_lstsize(t->b);
	else
		return ;
	median = find_median_b(t);
	t->flag++;
	t->b = t->head_b;
	check_tail_ab(t, len);
	main_cycle_b(t, median, len, i);
}

