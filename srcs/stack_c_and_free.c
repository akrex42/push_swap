#include "../includes/push_swap.h"

void	free_items(t_tools *t, int argc)
{
	int		i;
	t_list	*to_free;

	t->a = t->head_a;
	i = argc - 1;
	while (i && t->a)
	{
		to_free = t->a;
		t->a = t->a->next;
		free(to_free);
		i--;
	}
	t->c = t->head_c;
	while (t->c)
	{
		to_free = t->c;
		t->c = t->c->next;
		free(to_free);
	}
	free(t->tab_original);
	free(t->tab_sorted);
}

void	change_stack_c(t_tools *t)
{
	t->c = t->head_c;
	while (t->c)
	{
		if (t->c->next)
		{
			check_pb_pa_1(t);
			check_pb_pa_2(t);
			if (check_rb_ra_1(t) == 0)
				check_rb_ra_2(t);
			else if (check_sb_sa_1(t) == 0)
				check_sb_sa_2(t);
			else if (check_ra_rra_1(t) == 0)
				check_ra_rra_2(t);
			else if (check_rb_rrb_1(t) == 0)
				check_rb_rrb_2(t);
		}
		t->c = t->c->next;
	}
	t->c = t->head_c;
}
