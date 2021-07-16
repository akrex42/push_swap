/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:13:13 by akrex             #+#    #+#             */
/*   Updated: 2020/11/02 19:13:15 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*c;
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)src;
	c = (unsigned char *)dest;
	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		c[i] = s[i];
		i++;
	}
	return (dest);
}
