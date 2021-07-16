/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:30:02 by akrex             #+#    #+#             */
/*   Updated: 2020/11/17 21:19:29 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *destination, const char *source, size_t n)
{
	size_t	len;

	if (!source && !destination)
		return (0);
	len = ft_strlen(source);
	if (len + 1 < n)
	{
		ft_memcpy(destination, source, len + 1);
	}
	else if (n != 0)
	{
		ft_memcpy(destination, source, n - 1);
		destination[n - 1] = '\0';
	}
	return (len);
}
