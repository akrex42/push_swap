/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:27:36 by akrex             #+#    #+#             */
/*   Updated: 2020/11/18 12:54:50 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*ar1;
	unsigned char	*ar2;
	size_t			i;

	ar1 = (unsigned char *)arr1;
	ar2 = (unsigned char *)arr2;
	i = 0;
	while (i < n)
	{
		if (ar1 == ar2)
			return (0);
		else if (ar1[i] > ar2[i])
			return (ar1[i] - ar2[i]);
		else if (ar1[i] < ar2[i])
			return (ar1[i] - ar2[i]);
		i++;
	}
	return (0);
}
