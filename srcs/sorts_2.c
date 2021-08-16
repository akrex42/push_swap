#include "../includes/push_swap.h"

void  check_tail_ab(t_tools *t, int len)
{
	int flag = 0;

	while (t->tail_a && t->tail_a->order == t->next && ((check_if_sorted_a(t) != 0) || (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
	{
		rotate_a(t);
		t->head_a->flag = 1000; // change to int_min
		t->next++;
	}
	while (t->tail_a->prev && t->tail_a->prev->order == t->next && ((check_if_sorted_a(t) != 0) || (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
	{
		if (t->tail_b && t->tail_b->prev && t->tail_b->prev->order < t->tail_b->order)
		{
			swap_ab(t);
		}
		else
			swap_a(t);
		rotate_a(t);
		t->head_a->flag = 1000; // change to int_min
		t->next++;
	}
	if (t->tail_b)
	{
		while (t->tail_b && t->tail_b->order == t->next)
		{
			if (t->tail_b->prev && t->tail_b->prev->order == t->next && t->tail_a && t->tail_a->prev && t->tail_a->prev->order < t->tail_a->order)
			{
				swap_ab(t);
				while (t->tail_a && t->tail_a->order == t->next && ((check_if_sorted_a(t) != 0) || (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
				{
					rotate_a(t);
					t->head_a->flag = 1000; // change to int_min
					t->next++;
				}
			}
			else if (t->tail_b->prev && t->tail_b->prev->order == t->next)
			{
				swap_b(t);
			}
			push_a(t);
			rotate_a(t);
			t->head_a->flag = 1000;
			t->next++;
		}
	}
	if (t->head_b)
	{
		while (t->head_b && t->head_b->order == t->next)
		{
			if (t->head_b->next && t->head_b->next->order == t->next)
			{
				reverse_rotate_b(t);
				flag = 1;
			}
			reverse_rotate_b(t);
			push_a(t);
			if (flag)
				rotate_ab(t);
			else
				rotate_a(t);
			t->head_a->flag = 1000;
			t->next++;
		}
	}
	t->a = t->head_a;
	t->b = t->head_b;
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
				if (t->flag == 0)
					break ;
				t->flag--;
			}
			check_tail_ab(t, len);
			if (t->flag != 0 && ((check_if_sorted_a(t) != 0) || (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
			{
				check_tail_ab(t, len);
				while (t->tail_a->flag == t->flag)
				{
					push_b(t);
					check_tail_ab(t, len);
					check_tail_ab(t, len);
					check_tail_ab(t, len);
				}
				check_tail_ab(t, len);
				while (t->head_b)
				{
					check_tail_ab(t, len);
					sort_median_b(t);
					check_tail_ab(t, len);
				}
			}
			else if (t->tail_a->flag == 0 && t->flag == 0 && ((check_if_sorted_a(t) != 0) || (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
			{
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
					if (median >= (t->a)->order)
						push_b(t);
					else if ((t->a)->order && (t->a)->order == t->next)
					{
						rotate_a(t);
						t->head_a->flag = 1000;
						t->next++;
					}
					else if (median < (t->a)->order && t->a->prev->flag == t->flag)
						rotate_a(t);
					else if (median < (t->a)->order && t->a->prev->flag != t->flag)
						break ;
					t->a = (t->a)->prev;
				}
				while (t->head_a && t->head_a->flag != 1000)
				{
					if (t->tail_b && t->tail_b->order != t->next)
						reverse_rotate_ab(t);
					else
						reverse_rotate_a(t);
					t->tail_a->flag = 0;
				}
				check_tail_ab(t, len);
				while (t->head_b)
				{
					check_tail_ab(t, len);
					check_tail_ab(t, len);
					sort_median_b(t);
					check_tail_ab(t, len);
					check_tail_ab(t, len);
				}
			}
			check_tail_ab(t, len);
		}
		check_tail_ab(t, len);
	}
	check_tail_ab(t, len);
//	print_stack_a(t);
//	print_stack_b(t);
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
	else if (ft_lstsize(t->a) <= 1000)
	{
//		t->head_c = (t_list *)malloc(sizeof(t_list));
//		t->head_c->content = "fuck";
//		t->tail_c = (t_list *)malloc(sizeof(t_list));

		int len = ft_lstsize(t->a);
		if (check_if_sorted_a(t) == 0)
			return ;
		sort_median_a(t);
		check_tail_ab(t, len);
		while (t->head_b)
		{
			check_tail_ab(t, len);
			check_tail_ab(t, len);
			sort_median_b(t);
			check_tail_ab(t, len);
			check_tail_ab(t, len);
		}
		if (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) == len)
			return ;
		while (t->next != len + 1)
		{
			if (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) == len)
				break ;
			check_tail_ab(t, len);
			if (((check_if_sorted_a(t) == 1) || (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
			{
				check_tail_ab(t, len);
				sort(t, len);
				check_tail_ab(t, len);
			}
			check_tail_ab(t, len);
		}
	}
//	print_stack_a(t);
//	print_stack_b(t);
}