/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:23:40 by akrex             #+#    #+#             */
/*   Updated: 2020/11/21 19:23:55 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	t_list	*elem;

	elem = lst;
	if (lst == NULL)
		return ;
	if (f)
	{
		while (elem)
		{
			f(elem->content);
			elem = elem->next;
		}
	}
}
