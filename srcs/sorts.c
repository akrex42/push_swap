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
		else if (median < (t->a)->order)
		{
			rotate_a(t);
		}
		t->a = (t->a)->prev;
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

void sort_five(t_tools *t)
{
	int i = 0;
	if (check_if_sorted_a(t))
	{
		sort_median_a(t);
		if (check_if_sorted_a(t) || t->head_b != NULL)
		{
			sort_stack_three_elems(t);
			sort_stack_two_elems_b(t);
			t->b = t->head_b;
			while (i < 2)
			{
				if (t->head_b)
					push_a(t);
				i++;
			}
		}
		else
			return ;
	}
	else
		return ;
}

#if 0

void swap_and_rotate_till_dead_b(t_tools *t)
{
	int flag_cycle = 0;
	t->b = t->head_b;
	int min = t->head_b->order;

	while (t->b->next)
	{
		if (min >= t->b->next->order)
		{
			min = t->b->next->order;
			flag_cycle = 1;
		}
		t->b = t->b->next;
	}
	while (1)
	{
		t->b = t->head_b;
		if (t->tail_b->prev && (t->tail_b->order < t->tail_b->prev->order && t->tail_b->order != min))
		{
			swap_b(t);
		}
		else if (t->tail_b->prev && ((t->tail_b->order > t->tail_b->prev->order) || (t->tail_b->order < t->tail_b->prev->order && t->tail_b->order == min)))
		{
			rotate_b(t);
		}
		t->b = t->head_b;
		while (t->b->next)
		{
			if (t->b->order != t->b->next->order - 1)
			{
				flag_cycle = 1;
				break ;
			}
			t->b = t->b->next;
		}
		if (flag_cycle == 1)
		{
			flag_cycle = 0;
		}
		else if (t->head_b->order == min)
			break ;
	}
}

void swap_and_rotate_till_dead_a(t_tools *t)
{
	int flag_cycle = 0;

		int index = t->head_a->order;
		while (1)
			{
				t->a = t->head_a;
				if (t->tail_a->prev && ((t->tail_a->order < t->tail_a->prev->order) || (t->tail_a->order > t->tail_a->prev->order && t->tail_a->order == index)))
				{
					rotate_a(t);
				}
				else if (t->tail_a->prev && ((t->tail_a->order == t->tail_a->prev->order + 1)
					|| (t->tail_a->order > t->tail_a->prev->order)))
				{
					swap_a(t);
				}
				t->a = t->head_a;
				while (t->a->next)
				{
					if (t->a->order != t->a->next->order + 1)
					{
						flag_cycle = 1;
						break ;
					}
					t->a = t->a->next;
				}
				if (flag_cycle == 1)
				{
					flag_cycle = 0;
				}
				else if (t->head_a->order == index)
					break ;
			}
}

void sort_median_a_cycle(t_tools *t, int length_a)
{
	int median;
//	int len;
	int flag = 0;
	int i = 0;
//	int j = 0;

	t->a = t->head_a;
	if (t->a && ft_lstsize(t->a) <= 3)
	{
		sort_stack_three_elems(t);
		return ;
	}
	else if (t->a && ft_lstsize(t->a) <= 8)
	{
		sort_five(t);
	}
	else if (check_if_sorted_a(t) == 0 && check_if_sorted_b(t) == 0)
	{
		t->b = t->head_b;
//		ft_putstr_fd("there", 1);
		int len = ft_lstsize(t->b);
		len -= 1;
		while (len)
		{
			push_a(t);
			len--;
		}
		flag = 1;
		return ;
	}
	t->a = t->tail_a;
	if (t->a->prev && t->a->order > t->a->prev->order)
	{
		swap_a(t);
	}
	t->a = t->head_a;
	if (t->tail_a && t->tail_a->order - t->head_a->order == 1 && !flag)
	{
		reverse_rotate_a(t);
	}
	if (t->tail_a && t->head_a->order - t->tail_a->order == 1 && !flag)
	{
		rotate_a(t);
	}
	median = find_median_a(t);
//	while (j < length_a)
//	{
//		ft_putnbr_fd(median, 1);

		i = 0;
//		len = ft_lstsize(t->a);
//		t->a = t->tail_a;

		while (i < length_a && t->tail_a && !flag)
		{
			t->a = t->head_a;
			if (ft_lstsize(t->a) <= 3)
				break ;
			if (t->tail_a->prev && t->tail_a->order > t->tail_a->prev->order)
				swap_a(t);
			if (median >= (t->tail_a)->order)
				push_b(t);
			else if (median < (t->tail_a)->order)
				rotate_a(t);
//			ft_putnbr_fd(i, 1);
//			t->a = t->tail_a;
//			t->a = (t->a)->prev;
//			t->a = t->head_a;
			i++;
		}
		t->a = t->tail_a;
		if (t->a->prev && t->a->order < t->a->prev->order)
		{
			swap_a(t);
		}
		t->a = t->tail_a;
		if (t->a->prev->prev && t->a->prev->order > t->a->prev->prev->order && !flag)
		{
			push_b(t);
			swap_a(t);
		}
		t->a = t->head_a;
		if (t->a && ft_lstsize(t->a) <= 3 && length_a <= 3 && !flag)
		{
			sort_stack_three_elems(t);
			return ;
		}
		else
		{
			if (!flag)
			{
				t->a = t->head_a;
				t->b = t->head_b;
				length_a = ft_lstsize(t->a);
				int length_b = ft_lstsize(t->b);
//				print_stack_a(t);
//				print_stack_b(t);
				sort_median_a_cycle(t, length_a / 2 + length_a % 2);
				sort_median_b_cycle(t, length_b / 2);
			}
			else
				return ;
		}
//		j++;
//	}
}

void sort_median_b_cycle(t_tools *t, int length_b)
{
	int median;
//	int len;
	int i = 0;
	int flag = 0;
//	int j = 0;

	if (t->head_b)
	{
		t->b = t->head_b;
		if (ft_lstsize(t->b) <= 3)
		{
			sort_stack_three_elems_b(t);
			return ;
		}
	}
	else if (t->head_b)
	{
		if (check_if_sorted_b(t) == 0)
			flag = 1;
	}
	else if (t->head_b == NULL && !flag)
	{
		flag = 1;
	}
	t->b = t->tail_b;
	if (t->b->prev && t->b->order < t->b->prev->order)
	{
		swap_b(t);
	}
	t->b = t->head_b;
	if (t->tail_b && t->head_b->order - t->tail_b->order == 1 && !flag)
	{
		reverse_rotate_b(t);
	}
	median = find_median_b(t);
	i = 0;
		while (i < length_b && t->tail_b && !flag)
		{
			t->b = t->head_b;
			if (ft_lstsize(t->b) <= 3)
				break ;
			if (t->tail_b->prev && t->tail_b->order < t->tail_b->prev->order)
				swap_b(t);
			if (median < (t->tail_b)->order)
				push_a(t);
			else if (median >= (t->tail_b)->order)
				rotate_b(t);
			i++;
		}
		t->b = t->tail_b;
		if (t->b->prev && t->b->order < t->b->prev->order)
		{
			swap_b(t);
		}
		t->b = t->head_b;
//		ft_putnbr_fd(length_b, 1);
//		ft_putstr_fd("here", 1);
		if (t->b && ft_lstsize(t->b) <= 3 && length_b <= 3 && !flag)
		{
			sort_stack_three_elems_b(t);
			return ;
		}
		else
		{
//			ft_putnbr_fd(length_b, 1);
			if (flag == 0)
			{
				t->a = t->head_a;
				t->b = t->head_b;
				int length_a = ft_lstsize(t->a);
				length_b = ft_lstsize(t->b);
//				print_stack_a(t);
//				print_stack_b(t);
				sort_median_b_cycle(t, length_b / 2);
				sort_median_a_cycle(t, length_a / 2 + length_a % 2);
			}
			else
				return ;
		}
}

void sort_b_three(t_tools *t)
{
	while (t->tail_b)
	{
		if (t->tail_b->prev && t->tail_b->prev->prev && t->tail_b->prev->prev->prev)
		{
			if (t->tail_b->order > t->tail_b->prev->order && t->tail_b->order > t->tail_b->prev->prev->order)
			{
				if (t->tail_a->order - t->tail_b->order == 1)
				{
					push_a(t);
				}
				else
					rotate_b(t);
			}
			else if (t->tail_b->order > t->tail_b->prev->order && t->tail_b->order < t->tail_b->prev->prev->order)
			{
				if (t->tail_a->order - t->tail_b->prev->prev->order == 1)
				{
					rotate_b(t);
					rotate_b(t);
					push_a(t);
					reverse_rotate_b(t);
					reverse_rotate_b(t);
				}
				else
					rotate_b(t);
			}
			else if (t->tail_b->order < t->tail_b->prev->order && t->tail_b->order > t->tail_b->prev->prev->order)
			{
				swap_b(t);
				if (t->tail_a->order - t->tail_b->order == 1)
				{
					push_a(t);
				}
				else
				{
					swap_b(t);
					rotate_b(t);
				}
			}
			else if (t->tail_b->order < t->tail_b->prev->order && t->tail_b->order < t->tail_b->prev->prev->order)
			{
				if (t->tail_b->prev->prev->order < t->tail_b->prev->order)
				{
					swap_b(t);
					if (t->tail_a->order - t->tail_b->order == 1)
						push_a(t);
					else
						rotate_b(t);
				}
				else if (t->tail_b->prev->prev->order > t->tail_b->prev->order)
				{
					swap_b(t);
					rotate_b(t);
					if (t->tail_a->order - t->tail_b->order == 1)
						push_a(t);
					else
						rotate_b(t);
				}
			}
		}
		else if (check_if_sorted_b(t) == 0)
		{
			t->b = t->head_b;
			while (1)
			{
				if (t->head_b)
					push_a(t);
				else
					break;
			}
			break ;
		}
		else if (t->tail_b->prev && t->tail_b->prev->prev)
		{
			sort_stack_three_elems_b(t);
			push_a(t);
			push_a(t);
			push_a(t);
		}
		else if (t->tail_b->prev)
		{
			sort_stack_two_elems_b(t);
			push_a(t);
			push_a(t);
		}
//		print_stack_a(t);
//		print_stack_b(t);
	}
}

void	previous_sort(t_tools *t)
{
	if (check_if_sorted_a(t))
		{
			sort_median_a_cycle(t);
		}
		while (t->tail_b)
		{
			if (t->tail_b->prev && t->tail_b->prev->prev && t->tail_b->prev->prev->prev)
			{
				if (t->tail_b->order > t->tail_b->prev->order && t->tail_b->order > t->tail_b->prev->prev->order)
				{
					if (t->tail_a->order - t->tail_b->order == 1)
					{
						push_a(t);
					}
					else
						rotate_b(t);
				}
				else if (t->tail_b->order > t->tail_b->prev->order && t->tail_b->order < t->tail_b->prev->prev->order)
				{
					if (t->tail_a->order - t->tail_b->prev->prev->order == 1)
					{
						rotate_b(t);
						rotate_b(t);
						push_a(t);
						reverse_rotate_b(t);
						reverse_rotate_b(t);
					}
					else
						rotate_b(t);
				}
				else if (t->tail_b->order < t->tail_b->prev->order && t->tail_b->order > t->tail_b->prev->prev->order)
				{
					swap_b(t);
					if (t->tail_a->order - t->tail_b->order == 1)
					{
						push_a(t);
					}
					else
					{
						swap_b(t);
						rotate_b(t);
					}
				}
				else if (t->tail_b->order < t->tail_b->prev->order && t->tail_b->order < t->tail_b->prev->prev->order)
				{
					if (t->tail_b->prev->prev->order < t->tail_b->prev->order)
					{
						swap_b(t);
						if (t->tail_a->order - t->tail_b->order == 1)
							push_a(t);
						else
							rotate_b(t);
					}
					else if (t->tail_b->prev->prev->order > t->tail_b->prev->order)
					{
						swap_b(t);
						rotate_b(t);
						if (t->tail_a->order - t->tail_b->order == 1)
							push_a(t);
						else
							rotate_b(t);
					}
				}
			}
			else if (check_if_sorted_b(t) == 0)
			{
				t->b = t->head_b;
				while (1)
				{
					if (t->head_b)
						push_a(t);
					else
						break;
				}
				return ;
			}
			else if (t->tail_b->prev && t->tail_b->prev->prev)
			{
				sort_stack_three_elems_b(t);
				push_a(t);
				push_a(t);
				push_a(t);
			}
			else if (t->tail_b->prev)
			{
				sort_stack_two_elems_b(t);
				push_a(t);
				push_a(t);
			}
//			print_stack_a(t);
//			print_stack_b(t);
		}
		print_stack_a(t);
		print_stack_b(t);
		//	else if (ft_lstsize(t->a) <= 71)
//	{
//		int len_gen = ft_lstsize(t->a);
//		int i = 0;
//
//		if (check_if_sorted_a(t))
//		{
//			sort_median_a_cycle(t);
//		}
//		if (check_if_sorted_b(t))
//		{
//			sort_median_b(t);
//		}
////		print_stack_a(t);
////		print_stack_b(t);
////		if (check_if_sorted_b(t))
////		{
////			sort_median_b(t);
////		}
////		print_stack_a(t);
////		print_stack_b(t);
//		prepare_b(t);
//		int len = ft_lstsize(t->head_b);
//		sort_b_three(t);
//
//		i = len + 1;
//		while (i)
//		{
//			rotate_a(t);
//			i--;
//		}
//		int rest = len_gen - len - 3;
//		i = rest;
//		while (i)
//		{
//			push_b(t);
//			i--;
//		}
////		print_stack_a(t);
////		print_stack_b(t);
//		if (check_if_sorted_b(t))
//		{
//			sort_median_b(t);
//		}
////		print_stack_a(t);
////		print_stack_b(t);
////		if (check_if_sorted_b(t))
////		{
////			sort_median_b(t);
////		}
////		print_stack_a(t);
////		print_stack_b(t);
//		prepare_b(t);
//		len = ft_lstsize(t->head_b);
//		sort_b_three(t);
//		i = len + 1;
//		while (i)
//		{
//			rotate_a(t);
//			i--;
//		}
//		rest = len_gen - (len - 1 + len_gen - rest);
//		i = rest;
//		while (i)
//		{
//			push_b(t);
//			i--;
//		}
////		print_stack_a(t);
////		print_stack_b(t);
//		if (check_if_sorted_b(t))
//		{
//			sort_median_b(t);
//		}
////		print_stack_a(t);
////		print_stack_b(t);
////		if (check_if_sorted_b(t))
////		{
////			sort_median_b(t);
////		}
////		print_stack_a(t);
////		print_stack_b(t);
//		prepare_b(t);
//		len = ft_lstsize(t->head_b);
//		sort_b_three(t);
////		print_stack_a(t);
////		print_stack_b(t);
//		i = len + 1;
//		while (i)
//		{
//			rotate_a(t);
//			i--;
//		}
////		print_stack_a(t);
////		print_stack_b(t);
//		rest = len_gen - (len + 1 + len_gen - rest);
//		while (rest)
//		{
//			push_b(t);
//			rest--;
//		}
//
////		print_stack_a(t);
////		print_stack_b(t);
//		prepare_b(t);
//		len = ft_lstsize(t->head_b);
//		sort_b_three(t);
//		i = len + 1;
//		while (i)
//		{
//			rotate_a(t);
//			i--;
//		}
////		prepare_b(t);
////		len = ft_lstsize(t->head_b);
////		sort_b_three(t);
////		i = len + 1;
////		while (i)
////		{
////			rotate_a(t);
////			i--;
////		}
////		print_stack_a(t);
////		print_stack_b(t);
////		if (check_if_sorted_b(t))
////		{
////			sort_median_b(t);
////		}
}

//void sort_ten(t_tools *t)
//{
//	//		print_stack_a(t);
//	//		print_stack_b(t);
//
//	sort_median_a_cycle(t);
//	sort_median_b_cycle(t);
//	//
//	//		print_stack_a(t);
//	//		print_stack_b(t);
//	if (check_if_sorted_a(t))
//	{
//		sort_median_a(t);
//		//	//			print_stack_a(t);
//		//	//			print_stack_b(t);
////		sort_five(t);
//		print_stack_a(t);
//		print_stack_b(t);
//		if (check_if_sorted_a(t))
//		{
//			swap_and_rotate_till_dead_a(t);
//			if (check_if_sorted_b(t))
//				swap_and_rotate_till_dead_b(t);
//			t->b = t->head_b;
//			while (1)
//			{
//				if (t->head_b)
//					push_a(t);
//				else
//					break;
//			}
//			print_stack_a(t);
//			print_stack_b(t);
//		}
//		else
//			return ;
//	}
//	else
//		return ;
//}

void prepare_b(t_tools *t)
{
	int len1 = 0;

	int i = 0;
	int len = ft_lstsize(t->head_b);
	t->b = t->head_b;
	int max = t->b->order;
	while (i < len && t->b)
	{
		if (max < t->b->order)
			max = t->b->order;
		i++;
		t->b = t->b->next;
	}
	t->b = t->head_b;
	while (t->b)
	{
		if (t->b->order == max)
		{
			len1 = ft_lstsize(t->b);
			break ;
		}
		t->b = t->b->next;
	}
	len1 -= 1;
//	ft_putnbr_fd(len1, 1);
	while (len1)
	{
		rotate_b(t);
		len1--;
	}
	push_a(t);
}

#endif