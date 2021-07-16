/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:26:00 by akrex             #+#    #+#             */
/*   Updated: 2020/11/18 13:26:53 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		i;
	int		slen;

	if (!s1 || !set)
		return (NULL);
	slen = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (slen == 0 || i == slen)
		return (ft_strdup(""));
	while (slen > 0 && ft_strchr(set, s1[slen]))
		slen--;
	newstr = ft_substr(s1, i, slen - i + 1);
	return (newstr);
}
