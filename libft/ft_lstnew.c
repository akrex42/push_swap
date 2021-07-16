/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:43:07 by akrex             #+#    #+#             */
/*   Updated: 2020/11/21 19:43:31 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(t_list **head, t_list **tail)
{
	t_list	*lstnew;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (!lstnew)
		return (NULL);
	lstnew->prev = *tail;
	lstnew->next = NULL;
	if (*tail)
	{
		(*tail)->next = lstnew;
	}
	else if (*head == NULL)
	{
		*head = lstnew;
	}
	*tail = lstnew;
	return (lstnew);
}
