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