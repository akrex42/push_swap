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

void sort_median_b(t_tools *t)
{
	int median;
	int i;
	int len;

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

void sort_b_three(t_tools *t)
{
	while (t->tail_b)
	{
		if (t->tail_b->prev && t->tail_b->prev->prev && t->tail_b->prev->prev->prev)
		{
			if (t->tail_b->content > t->tail_b->prev->content && t->tail_b->content > t->tail_b->prev->prev->content)
			{
				if (t->tail_a->content - t->tail_b->content == 1)
				{
					push_a(t);
				}
				else
					rotate_b(t);
			}
			else if (t->tail_b->content > t->tail_b->prev->content && t->tail_b->content < t->tail_b->prev->prev->content)
			{
				if (t->tail_a->content - t->tail_b->prev->prev->content == 1)
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
			else if (t->tail_b->content < t->tail_b->prev->content && t->tail_b->content > t->tail_b->prev->prev->content)
			{
				swap_b(t);
				if (t->tail_a->content - t->tail_b->content == 1)
				{
					push_a(t);
				}
				else
				{
					swap_b(t);
					rotate_b(t);
				}
			}
			else if (t->tail_b->content < t->tail_b->prev->content && t->tail_b->content < t->tail_b->prev->prev->content)
			{
				if (t->tail_b->prev->prev->content < t->tail_b->prev->content)
				{
					swap_b(t);
					if (t->tail_a->content - t->tail_b->content == 1)
						push_a(t);
					else
						rotate_b(t);
				}
				else if (t->tail_b->prev->prev->content > t->tail_b->prev->content)
				{
					swap_b(t);
					rotate_b(t);
					if (t->tail_a->content - t->tail_b->content == 1)
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

void sort_five(t_tools *t)
{
	if (check_if_sorted_a(t))
	{
		sort_median_a(t);
		//			print_stack_a(t);
		//			print_stack_b(t);
		if (check_if_sorted_a(t) || t->head_b != NULL)
		{
			sort_stack_three_elems(t);
			sort_stack_three_elems_b(t);
			t->b = t->head_b;
			while (1)
			{
				if (t->head_b)
					push_a(t);
				else
					break;
			}
			//				print_stack_a(t);
			//				print_stack_b(t);
		}
		else
			return ;
	}
	else
		return ;
}

void sort_ten(t_tools *t)
{
	//		print_stack_a(t);
	//		print_stack_b(t);

	sort_median_a_cycle(t);
	sort_median_b_cycle(t);
	//
	//		print_stack_a(t);
	//		print_stack_b(t);
	if (check_if_sorted_a(t))
	{
		sort_median_a(t);
		//	//			print_stack_a(t);
		//	//			print_stack_b(t);
//		sort_five(t);
		print_stack_a(t);
		print_stack_b(t);
		if (check_if_sorted_a(t))
		{
			swap_and_rotate_till_dead_a(t);
			if (check_if_sorted_b(t))
				swap_and_rotate_till_dead_b(t);
			t->b = t->head_b;
			while (1)
			{
				if (t->head_b)
					push_a(t);
				else
					break;
			}
			print_stack_a(t);
			print_stack_b(t);
		}
		else
			return ;
	}
	else
		return ;
}

void prepare_b(t_tools *t)
{
	int len1 = 0;

	int i = 0;
	int len = ft_lstsize(t->head_b);
	t->b = t->head_b;
	int max = t->b->content;
	while (i < len && t->b)
	{
		if (max < t->b->content)
			max = t->b->content;
		i++;
		t->b = t->b->next;
	}
	t->b = t->head_b;
	while (t->b)
	{
		if (t->b->content == max)
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

void sort_all(t_tools *t)
{
//	int flag_cycle = 0;


	t->a = t->head_a;
	if (ft_lstsize(t->a) <= 3)
	{
		sort_stack_three_elems(t);
		return ;
	}
	else if (ft_lstsize(t->a) <= 5)
	{
		sort_five(t);
	}
	else if (ft_lstsize(t->a) <= 10)
	{
		sort_ten(t);
	}
	else if (ft_lstsize(t->a) <= 25)
	{
//		print_stack_a(t);
//		print_stack_b(t);
		if (check_if_sorted_a(t))
		{
			sort_median_a_cycle(t);
		}
		while (t->tail_b)
		{
			if (t->tail_b->prev && t->tail_b->prev->prev && t->tail_b->prev->prev->prev)
			{
				if (t->tail_b->content > t->tail_b->prev->content && t->tail_b->content > t->tail_b->prev->prev->content)
				{
					if (t->tail_a->content - t->tail_b->content == 1)
					{
						push_a(t);
					}
					else
						rotate_b(t);
				}
				else if (t->tail_b->content > t->tail_b->prev->content && t->tail_b->content < t->tail_b->prev->prev->content)
				{
					if (t->tail_a->content - t->tail_b->prev->prev->content == 1)
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
				else if (t->tail_b->content < t->tail_b->prev->content && t->tail_b->content > t->tail_b->prev->prev->content)
				{
					swap_b(t);
					if (t->tail_a->content - t->tail_b->content == 1)
					{
						push_a(t);
					}
					else
					{
						swap_b(t);
						rotate_b(t);
					}
				}
				else if (t->tail_b->content < t->tail_b->prev->content && t->tail_b->content < t->tail_b->prev->prev->content)
				{
					if (t->tail_b->prev->prev->content < t->tail_b->prev->content)
					{
						swap_b(t);
						if (t->tail_a->content - t->tail_b->content == 1)
							push_a(t);
						else
							rotate_b(t);
					}
					else if (t->tail_b->prev->prev->content > t->tail_b->prev->content)
					{
						swap_b(t);
						rotate_b(t);
						if (t->tail_a->content - t->tail_b->content == 1)
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
//		print_stack_a(t);
//		print_stack_b(t);
	}
	else if (ft_lstsize(t->a) <= 71)
	{
		int len_gen = ft_lstsize(t->a);
		int i = 0;

		if (check_if_sorted_a(t))
		{
			sort_median_a_cycle(t);
		}
		if (check_if_sorted_b(t))
		{
			sort_median_b(t);
		}
//		print_stack_a(t);
//		print_stack_b(t);
//		if (check_if_sorted_b(t))
//		{
//			sort_median_b(t);
//		}
//		print_stack_a(t);
//		print_stack_b(t);
		prepare_b(t);
		int len = ft_lstsize(t->head_b);
		sort_b_three(t);

		i = len + 1;
		while (i)
		{
			rotate_a(t);
			i--;
		}
		int rest = len_gen - len - 3;
		i = rest;
		while (i)
		{
			push_b(t);
			i--;
		}
//		print_stack_a(t);
//		print_stack_b(t);
		if (check_if_sorted_b(t))
		{
			sort_median_b(t);
		}
//		print_stack_a(t);
//		print_stack_b(t);
//		if (check_if_sorted_b(t))
//		{
//			sort_median_b(t);
//		}
//		print_stack_a(t);
//		print_stack_b(t);
		prepare_b(t);
		len = ft_lstsize(t->head_b);
		sort_b_three(t);
		i = len + 1;
		while (i)
		{
			rotate_a(t);
			i--;
		}
		rest = len_gen - (len - 1 + len_gen - rest);
		i = rest;
		while (i)
		{
			push_b(t);
			i--;
		}
//		print_stack_a(t);
//		print_stack_b(t);
		if (check_if_sorted_b(t))
		{
			sort_median_b(t);
		}
//		print_stack_a(t);
//		print_stack_b(t);
//		if (check_if_sorted_b(t))
//		{
//			sort_median_b(t);
//		}
//		print_stack_a(t);
//		print_stack_b(t);
		prepare_b(t);
		len = ft_lstsize(t->head_b);
		sort_b_three(t);
//		print_stack_a(t);
//		print_stack_b(t);
		i = len + 1;
		while (i)
		{
			rotate_a(t);
			i--;
		}
//		print_stack_a(t);
//		print_stack_b(t);
		rest = len_gen - (len + 1 + len_gen - rest);
		while (rest)
		{
			push_b(t);
			rest--;
		}

//		print_stack_a(t);
//		print_stack_b(t);
		prepare_b(t);
		len = ft_lstsize(t->head_b);
		sort_b_three(t);
		i = len + 1;
		while (i)
		{
			rotate_a(t);
			i--;
		}
//		prepare_b(t);
//		len = ft_lstsize(t->head_b);
//		sort_b_three(t);
//		i = len + 1;
//		while (i)
//		{
//			rotate_a(t);
//			i--;
//		}
//		print_stack_a(t);
//		print_stack_b(t);
//		if (check_if_sorted_b(t))
//		{
//			sort_median_b(t);
//		}
		print_stack_a(t);
		print_stack_b(t);
	}
}