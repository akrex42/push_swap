#include "../includes/push_swap.h"

void check_tail_ab(t_tools *t, int len)
{
//	t->a = t->head_a;
//	if (ft_lstsize(t->a) <= 3)
//	{
//		sort_stack_three_elems(t);
//	}
	while (t->tail_a && t->tail_a->order == t->next && ((check_if_sorted_a(t) != 0) || (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
	{
		rotate_a(t);
		t->head_a->flag = 1000;
		ft_putnbr_fd(t->head_a->flag, 1);
		t->next++;
	}
//	while (t->head_a && t->head_a->order == t->next && ((check_if_sorted_a(t) != 0) || (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
//	{
//		t->head_a->flag = 1000;
//		t->next++;
//	}
	while (t->tail_b && t->tail_b->order == t->next)
	{
		push_a(t);
		rotate_a(t);
		t->head_a->flag = 1000;
		ft_putnbr_fd(t->head_a->flag, 1);
		t->next++;
	}
	while (t->head_b && t->head_b->order == t->next)
	{
		reverse_rotate_b(t);
		while (t->tail_b && t->tail_b->order == t->next)
		{
			push_a(t);
			rotate_a(t);
			t->head_a->flag = 1000;
			ft_putnbr_fd(t->head_a->flag, 1);
			t->next++;
		}
	}
//	print_stack_a(t);
//	print_stack_b(t);
}

void   sort(t_tools *t, int len)
{
	check_tail_ab(t, len);
	if ((check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len) || (check_if_sorted_a(t) != 0))
	{
		if (t->tail_a && ((check_if_sorted_a(t) != 0) || (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
		{
			check_tail_ab(t, len);
			while (t->tail_a->flag != t->flag)
			{
				if (t->tail_a->flag == 1000)
					break ;
//				if (t->flag == 0)
//					break ;
				t->flag--;
			}
			ft_putstr_fd("Final flag:", 1);
			ft_putnbr_fd(t->flag, 1);
			ft_putnbr_fd(t->next, 1);
			print_stack_a(t);
			print_stack_b(t);
			check_tail_ab(t, len);
			if (t->flag != 0 && ((check_if_sorted_a(t) != 0) || (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
			{
				while (t->tail_a->flag == t->flag)
				{
					check_tail_ab(t, len);
					push_b(t);
					check_tail_ab(t, len);
					print_stack_a(t);
					print_stack_b(t);
				}
			}
			else if (t->tail_a->flag == 0 && t->flag == 0 && ((check_if_sorted_a(t) != 0) || (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
			{
					ft_putstr_fd("AAAAAAA", 1);
					print_stack_a(t);
					print_stack_b(t);
					t->a = t->tail_a;
					int max = t->a->order;
					int min = t->a->order;
					while (t->a->flag == t->flag)
					{
						if (max < t->a->order)
							max = t->a->order;
						if (min > t->a->order)
							min = t->a->order;
						t->a = t->a->prev;
					}
					int median = (max + min) / 2;
					t->a = t->tail_a;
					while (t->a->flag == t->flag)
					{
						ft_putnbr_fd(t->a->flag, 1);
						check_tail_ab(t, len);
						if (median >= (t->a)->order)
							push_b(t);
						else if (median < (t->a)->order)
							rotate_a(t);
						check_tail_ab(t, len);
						t->a = (t->a)->prev;
						print_stack_a(t);
						print_stack_b(t);
					}
					t->a = t->head_a;

			}
			else if (t->tail_a->flag == 1000 && ((check_if_sorted_a(t) != 0) || (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
			{
					while (t->head_b)
					{
						check_tail_ab(t, len);
						sort_median_b(t);
						check_tail_ab(t, len);
						t->b = t->head_b;
					}
			}
			while (t->head_a->flag != 1000)
			{
				//						check_tail_ab(t, len);
				reverse_rotate_a(t);
				//							print_stack_a(t);
				//							print_stack_b(t);
				//						check_tail_ab(t, len);
			}
			while (t->head_b)
			{
				check_tail_ab(t, len);
				sort_median_b(t);
				check_tail_ab(t, len);
			}
		}
	}
	check_tail_ab(t, len);
}

void sort_all(t_tools *t)
{
	t->a = t->head_a;
	if (ft_lstsize(t->a) <= 3)
	{
		sort_stack_three_elems(t);
		return ;
	}
	else if (ft_lstsize(t->a) <= 5)
	{
		if (check_if_sorted_a(t) == 0)
			return ;
		sort_median_a(t);
		t->b = t->head_b;
		if (ft_lstsize(t->b) <= 3)
		{
			sort_stack_three_elems_b(t);
			while (t->head_b)
			{
				push_a(t);
			}
//			print_stack_a(t);
//			print_stack_b(t);
			return ;
		}
	}
	else if (ft_lstsize(t->a) <= 502)
	{
		int len = ft_lstsize(t->a);
		if (check_if_sorted_a(t) == 0)
			return ;
		check_tail_ab(t, len);
		sort_median_a(t);
		check_tail_ab(t, len);
		while (t->head_b)
		{
			check_tail_ab(t, len);
			sort_median_b(t);
			check_tail_ab(t, len);
		}
		while (t->next != len + 1)
		{
			t->a = t->head_a;
			t->b = t->head_b;
			if (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) == len)
				break ;
			check_tail_ab(t, len);
			if (((check_if_sorted_a(t) == 1) || (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
			{
//				print_stack_a(t);
//				print_stack_b(t);
				check_tail_ab(t, len);
				sort(t, len);
				check_tail_ab(t, len);
			}
		}
		check_tail_ab(t, len);
	}
	print_stack_a(t);
	print_stack_b(t);
}