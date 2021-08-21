#include "../includes/push_swap.h"

void	sort(t_tools *t, int len)
{
	check_tail_ab(t, len);
	if ((check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)
		|| (check_if_sorted_a(t) != 0))
	{
		if (t->tail_a && ((check_if_sorted_a(t) != 0)
				|| (check_if_sorted_a(t) == 0 && ft_lstsize(t->head_a) != len)))
			still_to_sort(t, len);
		check_tail_ab(t, len);
	}
	check_tail_ab(t, len);
}
