/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:28:21 by akrex             #+#    #+#             */
/*   Updated: 2020/11/21 19:28:57 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*tmp;
	t_list	*tmp1;

	if (lst == NULL)
		return ;
	tmp = *lst;
	while (tmp)
	{
		tmp1 = tmp;
		free(tmp1);
		del(tmp->content);
		tmp = tmp->next;
	}
	*lst = NULL;
}
