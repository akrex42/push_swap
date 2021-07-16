/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:09:28 by akrex             #+#    #+#             */
/*   Updated: 2020/11/02 21:25:03 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*ar;
	size_t			i;

	ar = (unsigned char *)arr;
	i = 0;
	while (i < n)
	{
		if (ar[i] == ((unsigned char)c))
			return (&ar[i]);
		i++;
	}
	return (NULL);
}
