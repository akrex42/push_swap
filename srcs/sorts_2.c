#include "../includes/push_swap.h"

void sort(t_tools *t)
{
	int flag = t->flag;

//	int i = 0;
	while (1)
	{
		ft_putnbr_fd(t->tail_a->flag, 1);
		ft_putnbr_fd(t->flag, 1);
		if (t->tail_b != NULL)
		{
			if (t->tail_b->order == t->next)
			{
				push_a(t);
				rotate_a(t);
				t->next++;
			}
			if (t->tail_b->prev != NULL)
			{
				if (t->tail_b->prev->order == t->next)
				{
					push_a(t);
					rotate_a(t);
					t->next++;
				}
			}
//			print_stack_a(t);
//			print_stack_b(t);
//			ft_putnbr_fd(t->next, 1);
		}
//		ft_putnbr_fd(t->next, 1);
//		ft_putchar_fd('\n', 1);
		if (check_if_sorted_a(t) != 0)
		{
//			ft_putnbr_fd(t->tail_a->flag, 1);
//			ft_putnbr_fd(t->flag, 1);
			while (1)
			{
				if (t->tail_a->flag == flag)
					break ;
				else
					flag--;
			}
			ft_putnbr_fd(t->tail_a->flag, 1);
			ft_putnbr_fd(t->flag, 1);
			while (1)
			{
				if (t->tail_a->flag == flag)
				{
					ft_putstr_fd("AAH", 1);
					push_b(t);
				}
				else
					break ;
			}
			if (t->head_b != NULL)
				sort_median_b(t);
			//			}
			flag--;
		}
		if (flag != 0)
		{
			ft_putnbr_fd(t->next, 1);
			flag--;
		}
		else
		{
			ft_putnbr_fd(t->next, 1);
			break ;
		}
		print_stack_a(t);
		print_stack_b(t);
	}
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
	else if (ft_lstsize(t->a) <= 101)
	{
//		print_stack_a(t);
//		print_stack_b(t);
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
			print_stack_a(t);
			print_stack_b(t);
			return ;
		}
		while (t->head_b)
		{
			sort_median_b(t);
			if (t->tail_b && t->tail_b->order == t->next)
			{
				print_stack_a(t);
				print_stack_b(t);
				push_a(t);
				rotate_a(t);
				t->next++;
				ft_putnbr_fd(t->next, 1);
				if (t->tail_b->prev && t->tail_b->prev->order == t->next)
				{
					push_a(t);
					rotate_a(t);
					t->next++;
				}
			}
		}
		print_stack_a(t);
		print_stack_b(t);
		int i = 0;
		while (1)
		{
			if (t->tail_a->order == t->next && check_if_sorted_a(t) != 0)
			{
				ft_putnbr_fd(t->next, 1);
				rotate_a(t);
				t->next++;
			}
			else if (check_if_sorted_a(t) == 1)
			{
				ft_putstr_fd("there", 1);
				sort(t);
			}
			else
				break;
			ft_putstr_fd("here", 1);
			i++;
		}
	}
	print_stack_a(t);
	print_stack_b(t);
}