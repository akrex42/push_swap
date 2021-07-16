/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:52:47 by akrex             #+#    #+#             */
/*   Updated: 2020/11/06 22:07:26 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*strr;

	strr = (char *)str;
	i = 0;
	while (strr[i] != '\0')
	{
		i++;
	}
	if (strr == '\0')
		return (strr);
	while (i >= 0)
	{
		if (strr[i] == (char)ch)
			return (&strr[i]);
		i--;
	}
	return (NULL);
}
