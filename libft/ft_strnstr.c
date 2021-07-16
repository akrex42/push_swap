/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:23:03 by akrex             #+#    #+#             */
/*   Updated: 2020/11/18 13:25:43 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*bg;
	char	*lit;
	size_t	i;
	size_t	lenbg;
	size_t	lenlit;

	bg = (char *)big;
	lit = (char *)little;
	i = 0;
	lenbg = ft_strlen(bg);
	lenlit = ft_strlen(lit);
	if (lenlit == 0)
		return (bg);
	if (lenlit > lenbg || lenlit > len)
		return (NULL);
	while (i <= len - lenlit)
	{
		if (ft_strncmp(&bg[i], lit, lenlit) == 0)
			return (&bg[i]);
		i++;
	}
	return (NULL);
}
