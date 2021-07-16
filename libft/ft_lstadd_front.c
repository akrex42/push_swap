/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:38:55 by akrex             #+#    #+#             */
/*   Updated: 2020/11/21 19:40:28 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_front(t_list **head, t_list **tail)
{
	t_list	*lstnew;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (!lstnew)
		return (NULL);
	lstnew->prev = NULL;
	lstnew->next = *head;
	if (*head)
	{
		(*head)->next = lstnew;
	}
	else if (*tail == NULL)
	{
		*tail = lstnew;
	}
	*head = lstnew;
	return (lstnew);
}
