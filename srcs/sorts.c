#include "../includes/push_swap.h"

int 	sort_stack_two_elems(t_tools *t)
{
	if (t->tail_a->prev && t->tail_a->content > t->tail_a->prev->content)
		swap_a(t);
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
		if (t->a->content != t->a->prev->content - 1)
		{
			flag_cycle = 1;
			break;
		}
		t->a = t->a->prev;
	}
	if (flag_cycle == 1)
	{
		flag_cycle = 0;
	} else
		return ;

	t->a = t->head_a;
	if (sort_stack_two_elems(t) == 1)
	{}
	else if ((t->a->next->next && t->a->content < t->a->next->next->content) || (t->a->next->next && t->a->content == t->a->next->next->content + 1))
	{
		reverse_rotate_a(t);
		sort_stack_two_elems(t);
	}
	else if (t->a->next->next && t->a->content > t->a->next->next->content && t->a->content < t->a->next->content)
	{
		rotate_a(t);
//		print_stack_a(t);
		sort_stack_two_elems(t);
	}
	else if (t->a->next->next && t->a->content > t->a->next->next->content && t->a->content < t->a->next->content)
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
	else if (t->tail_b->prev == NULL)
		return (1);
	return (0);
}

void 	sort_stack_three_elems_b(t_tools *t)
{
	int flag_cycle = 0;

	t->b = t->tail_b;
	while (t->b->prev)
	{
		if (t->b->content != t->b->prev->content + 1)
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

	if (sort_stack_two_elems_b(t) == 1)
	{}
	else if ((t->b->next->next && t->b->content > t->b->next->next->content) || (t->b->next->next && t->b->content == t->b->next->next->content - 1))
	{
		reverse_rotate_b(t);
//		print_stack_a(t->a, t->head_a);
		sort_stack_two_elems_b(t);
	}
	else if (t->b->next->next && t->b->content < t->b->next->next->content && t->b->content > t->b->next->content)
	{
		rotate_b(t);
//		print_stack_a(t->a, t->head_a);
		sort_stack_two_elems_b(t);
//		print_stack_a(t->a, t->head_a);
		reverse_rotate_b(t);
	}
}

int	find_median(t_tools *t)
{
	int	max;
	int	min;
	int	i;
//	int median;
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
//	median = (max + min) / 2;
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

int check_if_sorted_a(t_tools *t)
{
	int flag_cycle = 0;

	t->a = t->tail_a;
	while (t->a->prev)
	{
		if (t->a->content != t->a->prev->content - 1)
		{
			flag_cycle = 1;
			break;
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
		if (t->b->content != t->b->prev->content + 1)
		{
			flag_cycle = 1;
			break;
		}
		t->b = t->b->prev;
	}
	t->b = t->tail_b;
	return (flag_cycle);
}

void sort_median_a(t_tools *t, int median)
{
	int i = 0;
	int len;

	t->a = t->head_a;
	i = 0;
	len = ft_lstsize(t->a);
	t->a = t->tail_a;
	while (i < len && t->a)
	{
		t->a = t->tail_a;
		if (median >= (t->a)->content)
			push_b(t);
		else if (median < (t->a)->content)
			rotate_a(t);
		t->a = (t->a)->prev;
		i++;
		t->a = t->head_a;
	}
	t->a = t->head_a;
	if (ft_lstsize(t->a) <= 3)
	{
		sort_stack_three_elems(t);
	}
}

void sort_median_b(t_tools *t, int median)
{
//	int median;
	int i;
	int len;

//	median = find_median_b(t);
	t->b = t->head_b;
	i = 0;
	len = ft_lstsize(t->b);
	t->b = t->tail_b;
	while (i < len && t->b)
	{
		t->b = t->tail_b;
		if (median <= (t->b)->content)
			push_a(t);
		else if (median > (t->b)->content)
			rotate_b(t);
		t->b = (t->b)->prev;
		i++;
	}
	t->b = t->head_b;
	if (ft_lstsize(t->b) <= 3)
	{
		sort_stack_three_elems_b(t);
		t->b = t->head_b;
		while (1) // some problem here
		{
			if (t->head_b)
				push_a(t);
			else
				break;
		}
	}
}

void swap_and_rotate_till_dead_b(t_tools *t)
{
	int flag_cycle = 0;
	t->b = t->head_b;
	int min = t->head_b->content;

	while (t->b->next)
	{
		if (min >= t->b->next->content)
		{
			min = t->b->next->content;
			flag_cycle = 1;
		}
		t->b = t->b->next;
	}
	while (1)
	{
		t->b = t->head_b;
		if (t->tail_b->prev && (t->tail_b->content < t->tail_b->prev->content && t->tail_b->content != min))
		{
			swap_b(t);
		}
		else if (t->tail_b->prev && ((t->tail_b->content > t->tail_b->prev->content) || (t->tail_b->content < t->tail_b->prev->content && t->tail_b->content == min)))
		{
			rotate_b(t);
		}
		t->b = t->head_b;
		while (t->b->next)
		{
			if (t->b->content != t->b->next->content - 1)
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
		else if (t->head_b->content == min)
			break ;
	}
}

void swap_and_rotate_till_dead_a(t_tools *t)
{
	int flag_cycle = 0;

		int index = t->head_a->content;
		while (1)
			{
				t->a = t->head_a;
				if (t->tail_a->prev && ((t->tail_a->content < t->tail_a->prev->content) || (t->tail_a->content > t->tail_a->prev->content && t->tail_a->content == index)))
				{
					rotate_a(t);
				}
				else if (t->tail_a->prev && ((t->tail_a->content == t->tail_a->prev->content + 1)
					|| (t->tail_a->content > t->tail_a->prev->content)))
				{
					swap_a(t);
				}
				t->a = t->head_a;
				while (t->a->next)
				{
					if (t->a->content != t->a->next->content + 1)
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
				else if (t->head_a->content == index)
					break ;
			}
}

void sort_median_b_cycle(t_tools *t)
{
	int median;
	int len;
	int i = 0;

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
			if (median < (t->b)->content)
				push_a(t);
			else if (median >= (t->b)->content)
				rotate_b(t);
			t->b = (t->b)->prev;
			i++;
		}
		t->b = t->head_b;
		if (ft_lstsize(t->b) <= 3)
		{
			sort_stack_three_elems_b(t);
			t->b = t->head_b;
			while (1)
			{
				if (t->head_b)
					push_a(t);
				else
					break;
			}
			break;
		}
	}
}

void sort_median_a_cycle(t_tools *t)
{
	int median;
	int len;
	int i = 0;

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
			else if (median < (t->a)->content)
				rotate_a(t);
			t->a = (t->a)->prev;
			i++;
			t->a = t->head_a;
		}
		t->a = t->head_a;
		if (ft_lstsize(t->a) <= 3)
		{
			sort_stack_three_elems(t);
			break ;
		}
	}
}

//void sort_five(t_tools *t)
//{
//	if (check_if_sorted_a(t))
//	{
//		sort_median_a(t);
//		//			print_stack_a(t);
//		//			print_stack_b(t);
//		if (check_if_sorted_a(t) || t->head_b != NULL)
//		{
//			sort_stack_three_elems(t);
//			sort_stack_three_elems_b(t);
//			t->b = t->head_b;
//			while (1)
//			{
//				if (t->head_b)
//					push_a(t);
//				else
//					break;
//			}
//			//				print_stack_a(t);
//			//				print_stack_b(t);
//		}
//		else
//			return ;
//	}
//	else
//		return ;
//}
//
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
//
void sort_all(t_tools *t)
{
//	int flag_cycle = 0;

//	print_stack_a(t);
//	print_stack_b(t);

	t->a = t->head_a;
//	if (ft_lstsize(t->a) <= 3)
//	{
//		sort_stack_three_elems(t);
//		return ;
//	}
//	else if (ft_lstsize(t->a) <= 5)
//	{
//		sort_five(t);
//	}
//	else if (ft_lstsize(t->a) <= 10)
//	{
//		sort_ten(t);
//	}
	if (ft_lstsize(t->a) <= 25)
	{
//		print_stack_a(t);
//		print_stack_b(t);
//		if (check_if_sorted_a(t))
//		{
////			sort_median_a(t);
//			sort_median_a_cycle(t);
//		}
//		print_stack_a(t);
//		print_stack_b(t);
//		if (check_if_sorted_b(t))
//		{
////			sort_median_b(t);
//			sort_median_b_cycle(t);
//		}
		print_stack_a(t);
		print_stack_b(t);
//		if (ft_lstsize(t->a) > 6)
//		{
//			sort_median_a(t);
//		}
//		int i = 0;
//		while (i < 3)
//		{
//			push_b(t);
//			i++;
//		}
//		if (check_if_sorted_a(t) && t->)
//		{
			int sum = find_median(t);
			int median = (sum) / 2;
			sort_median_a(t, median);
			print_stack_a(t);
			print_stack_b(t);
			median = find_median_b(t);
			sort_median_b(t, median);
			print_stack_a(t);
			print_stack_b(t);
			median = find_median_b(t);
			ft_putnbr_fd(median, 1);
			sort_median_b(t, median);
			print_stack_a(t);
			print_stack_b(t);
//			median = find_median_b(t);
//			sort_median_b(t, median);
//			print_stack_a(t);
//			print_stack_b(t);
//			sort_median_b(t, median);
//			print_stack_a(t);
//			print_stack_b(t);

//			sort_median_b(t, median);
//		}
//		if (check_if_sorted_a(t))
//		{
//			swap_and_rotate_till_dead_a(t);
//		}
//		print_stack_a(t);
//		print_stack_b(t);
//
//		if (check_if_sorted_a(t))
//		{
//			sort_median_a(t);
////		}
//		if (check_if_sorted_b(t))
//		{
//			sort_median_b(t);
//			sort_median_b(t);
////			sort_median_b(t);
////				sort_median_b_cycle(t);
//		}
//		if (ft_lstsize(t->head_b) < 6)
//		{
//			swap_and_rotate_till_dead_b(t);
//		}
		print_stack_a(t);
		print_stack_b(t);

//		if (check_if_sorted_a(t))
//		{
//			sort_median_a(t);
//			//			sort_median_b_cycle(t);
//		}
//		print_stack_a(t);
//		print_stack_b(t);
//		sort_ten(t);

//		if (check_if_sorted_b(t))
//		{
//			swap_and_rotate_till_dead_b(t);
//		}
//		if (check_if_sorted_a(t))
//		{
//			swap_and_rotate_till_dead_a(t);
//		}

//
//		if (check_if_sorted_a(t))
//		{
//			sort_median_a(t);
//			if (check_if_sorted_a(t))
//			{
//				if (check_if_sorted_b(t))
//					sort_median_b(t);
//				sort_median_a_cycle(t);
//				swap_and_rotate_till_dead_b(t);
////				swap_and_rotate_till_dead_b(t);
//				t->b = t->head_b;
//
//			}
//			else
//				return ;
//		}
//		else
//			return ;
	}

//	print_stack_a(t);
//	print_stack_b(t);

//	if (check_if_sorted_b(t))
//		sort_median_b(t);
//	else
//		return ;


//	print_stack_a(t);
//	print_stack_b(t);

//	sort_median_a(t);
//
//	sort_median_b(t);

//	print_stack_a(t);
//	print_stack_b(t);

//
//	print_stack_a(t);
//	print_stack_b(t);

//	if (check_if_sorted_b(t))
//		swap_and_rotate_till_dead_b(t);
//	else
//		return ;

//	print_stack_a(t);
//	print_stack_b(t);

//	t->b = t->head_b;
//	while (1)
//	{
//		if (t->head_b)
//			push_a(t);
//		else
//			break;
//	}

//	print_stack_a(t);
//	print_stack_b(t);

//	if (!check_if_sorted(t))
//		return ;

}