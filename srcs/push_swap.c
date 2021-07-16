#include "../includes/push_swap.h"


//void 	pop_back(t_list **tail_a)
//{
//
//}

int		main(int argc, char **argv)
{
	t_list		*head_a = NULL;
	t_list		*a = NULL;
	t_list 		*tail_a = NULL;
	int			i;
	int 		j;
	int			*tab_sorted;
	int			*tab_original;
	int			min;
//	int 		len_stack = 0;

	tab_sorted = malloc(sizeof(tab_sorted) * (argc - 2));
	tab_original = malloc(sizeof(tab_sorted) * (argc - 2));
	j = 0;
	i = 1;

	// copy values to two tabs

	while (argv[i] != NULL)
	{
		tab_sorted[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		tab_original[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}

	// sort one tab_sorted

	j = 0;
	int index;

	while (j < argc - 1)
	{
		i = j;
		min = tab_sorted[j];
		index = j;
		while (i < argc - 1)
		{
			if (tab_sorted[i] < min)
			{
				min = tab_sorted[i];
				index = i;
			}
			i++;
		}
		int tmp = tab_sorted[j];
		tab_sorted[j] = min;
		tab_sorted[index] = tmp;
		j++;
	}

	// print tabs

//	i = 0;
//	while (i < argc - 1)
//	{
//		ft_putnbr_fd(tab_sorted[i], 1);
//		ft_putchar_fd(' ', 1);
//		i++;
//	}
//	ft_putchar_fd('\n', 1);
//
//	i = 0;
//	while (i < argc - 1)
//	{
//		ft_putnbr_fd(tab_original[i], 1);
//		ft_putchar_fd(' ', 1);
//		i++;
//	}
//	ft_putchar_fd('\n', 1);

	// add indexes to the list

	i = 0;

	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (tab_original[i] == tab_sorted[j])
			{
				a = ft_lstadd_back(&head_a, &tail_a);
				a->content = j;
			}
			j++;
		}
		i++;
	}

	// print list -> and <- STACK A

	a = head_a;

	while (a)
	{
		ft_putnbr_fd(a->content, 1);
		ft_putchar_fd(' ', 1);
		a = a->next;
	}
	ft_putchar_fd('\n', 1);

	//	a = tail_a;
//
//	while (a)
//	{
//		ft_putnbr_fd(a->content, 1);
//		ft_putchar_fd(' ', 1);
//		a = a->prev;
//	}
//	ft_putchar_fd('\n', 1);

	// create same size STACK B

//	a = head_a;
//	len_stack = ft_lstsize(a);

	t_list *head_b = NULL;
	t_list *tail_b = NULL;
	t_list *b = NULL;

//	while (len_stack)
//	{
//		b = ft_lstadd_back(&head_b, &tail_b);
//		b->content = 1;
//		len_stack--;
//	}
//
//	b = head_b;
//
//	while (b)
//	{
//		ft_putnbr_fd(b->content, 1);
//		ft_putchar_fd(' ', 1);
//		b = b->next;
//	}
//	ft_putchar_fd('\n', 1);

//	pop_back(&tail_a);
	push_b(&head_a, &head_b, &tail_a, &tail_b);
	push_b(&head_a, &head_b, &tail_a, &tail_b);
	push_b(&head_a, &head_b, &tail_a, &tail_b);
	push_b(&head_a, &head_b, &tail_a, &tail_b);

//	b = head_b;

//	while (b)
//	{
//		ft_putnbr_fd(b->content, 1);
//		ft_putchar_fd(' ', 1);
//		b = b->next;
//	}
//	ft_putchar_fd('\n', 1);
//
//	a = head_a;
//
//	while (a)
//	{
//		ft_putnbr_fd(a->content, 1);
//		ft_putchar_fd(' ', 1);
//		a = a->next;
//	}
//	ft_putchar_fd('\n', 1);

//	push_a(&head_a, &head_b, &tail_a, &tail_b);
//	swap_a(&tail_a);
//	swap_b(&tail_b);

//	a = head_a;
//
//	while (a)
//	{
//		ft_putnbr_fd(a->content, 1);
//		ft_putchar_fd(' ', 1);
//		a = a->next;
//	}
//	ft_putchar_fd('\n', 1);
//
//	b = head_b;
//
//	while (b)
//	{
//		ft_putnbr_fd(b->content, 1);
//		ft_putchar_fd(' ', 1);
//		b = b->next;
//	}
//	ft_putchar_fd('\n', 1);

//	swap_ab(&tail_a, &tail_b);
	rotate_b(&head_b, &tail_b);

//	a = head_a;
//
//	while (a)
//	{
//		ft_putnbr_fd(a->content, 1);
//		ft_putchar_fd(' ', 1);
//		a = a->next;
//	}
//	ft_putchar_fd('\n', 1);

	b = head_b;

	while (b)
	{
		ft_putnbr_fd(b->content, 1);
		ft_putchar_fd(' ', 1);
		b = b->next;
	}
	ft_putchar_fd('\n', 1);

	// TODO circular list
	// TODO free

	return (0);
}