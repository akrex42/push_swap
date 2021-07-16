/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:03:39 by akrex             #+#    #+#             */
/*   Updated: 2020/11/18 12:53:27 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *source, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < n && destination[i])
		i++;
	while (source[j] && (i + j + 1) < n)
	{
		destination[i + j] = source[j];
		j++;
		destination[i + j] = '\0';
	}
	return (i + ft_strlen(source));
}
