/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:15:49 by akrex             #+#    #+#             */
/*   Updated: 2020/11/06 21:25:07 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)destination;
	s = (unsigned char *)source;
	i = 0;
	while (s < d && i < n)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
	while (s > d && i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (destination);
}
