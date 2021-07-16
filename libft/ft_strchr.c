/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:46:56 by akrex             #+#    #+#             */
/*   Updated: 2020/11/17 21:18:16 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*strr;
	char	chr;

	i = 0;
	strr = (char *)str;
	chr = (char)ch;
	while (strr[i] != chr)
	{
		if (strr[i] == '\0')
			return (0);
		i++;
	}
	return (&strr[i]);
}
