/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:10:48 by akrex             #+#    #+#             */
/*   Updated: 2020/11/18 13:12:06 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	char	*newstr;

	str = (char *)s;
	i = 0;
	if (!str)
		return (NULL);
	newstr = (char *)malloc((ft_strlen(str) + 1) * (sizeof(char)));
	if (!newstr)
		return (NULL);
	while (str[i] != '\0')
	{
		newstr[i] = (*f)(i, str[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
