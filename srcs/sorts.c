#include "../includes/push_swap.h"

void 	sort_stack_two_elems(t_list **tail_a)
{
	if ((*tail_a)->content > (*tail_a)->prev->content)
		swap_a(tail_a);
}

void 	sort_stack_three_elems(t_list **a, t_list **head_a, t_list **tail_a)
{
	a = head_a;

	sort_stack_two_elems(tail_a);
	if ((*a)->content < (*a)->next->next->content)
	{
		reverse_rotate_a(head_a, tail_a);
//		print_stack_a(*a, *head_a);
		sort_stack_two_elems(tail_a);
	}
	else if ((*a)->content > (*a)->next->next->content && (*a)->content < (*a)->next->content)
	{
		rotate_a(head_a, tail_a);
//		print_stack_a(*a, *head_a);
		sort_stack_two_elems(tail_a);
//		print_stack_a(*a, *head_a);
		reverse_rotate_a(head_a, tail_a);
	}
}

int	find_median(t_list *a, t_list *head_a)
{
	int	max;
	int	min;
	int	i;
	int median;
	int len;
//	int flag_median;
//	int index;

	i = 0;
	a = head_a;
	max = a->content;
//	flag_median = 0;
	len = ft_lstsize(a);
	while (i < len && a)
	{
		if (max < a->content)
			max = a->content;
		a = a->next;
		i++;
	}
//	ft_putnbr_fd(max, 1);
//	ft_putchar_fd('\n', 1);
	a = head_a;
	min = a->content;
	i = 0;
	while (i < len && a)
	{
		if (min > a->content)
			min = a->content;
		a = a->next;
		i++;
	}
//	ft_putnbr_fd(min, 1);
//	ft_putchar_fd('\n', 1);
//	a = head_a;
	median = (max - min) / 2;
//	ft_putnbr_fd(median, 1);
//	ft_putchar_fd('\n', 1);
//	i = 0;
//	while (i < len && a)
//	{
//		if (a->content == median)
//		{
//			flag_median = 1;
//			break ;
//		}
//		a = a->next;
//		i++;
//	}
//	if (!flag_median)
//	{
//		i = 0;
//		a = head_a;
//		index = a->content;
//		while (i < len && a)
//		{
//			if (abs(median - index) > abs(median - a->content))
//				index = a->content;
//			a = a->next;
//			i++;
//		}
//		median = index;
//	}
//printf("%d", median);
	return (median);
}

void sort_all(t_list **a, t_list **head_a, t_list **tail_b, t_list **head_b, t_list **tail_a)
{
	int median = find_median(*a, *head_a);
	int len;
	int i;

	a = head_a;
	i = 0;
	len = ft_lstsize(*a);
	a = tail_a;
	while (i < len && *a)
	{
		if (median <= (*a)->content)
			push_b(head_a, head_b, tail_a, tail_b);
		else if (median > (*a)->content)
			rotate_a(head_a, tail_a);
		print_stack_a(*a, *head_a);
		*a = (*a)->prev;
		i++;
	}
}