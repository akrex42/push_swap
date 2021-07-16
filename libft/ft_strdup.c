/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:55:13 by akrex             #+#    #+#             */
/*   Updated: 2020/11/18 12:56:32 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s;
	char	*buf;
	int		len;

	s = (char *)str;
	len = ft_strlen(str) + 1;
	buf = (char *)malloc(len * sizeof(char));
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, s, len);
	if (!buf)
		return (NULL);
	return (buf);
}
