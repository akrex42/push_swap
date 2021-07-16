/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:03:32 by akrex             #+#    #+#             */
/*   Updated: 2020/11/18 13:10:27 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	j;
	char	*newstr;

	str = (char *)s;
	newstr = (char *)malloc(((sizeof(char) * len) + 1));
	j = 0;
	if (!str)
		return (NULL);
	if (!newstr)
		return (NULL);
	while (j < len && ft_strlen(s) > start && str)
	{
		newstr[j] = str[start + j];
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}
