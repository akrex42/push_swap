/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:04:54 by akrex             #+#    #+#             */
/*   Updated: 2020/11/02 19:10:31 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char	*dest;

	dest = (unsigned char *)destination;
	while (n)
	{
		dest[n - 1] = c;
		n--;
	}
	return (destination);
}
