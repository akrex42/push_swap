/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:35:17 by akrex             #+#    #+#             */
/*   Updated: 2020/11/18 13:35:42 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	unsigned char	*strr1;
	unsigned char	*strr2;
	size_t			i;

	strr1 = (unsigned char *)str1;
	strr2 = (unsigned char *)str2;
	i = 0;
	if (num == 0)
		return (0);
	while (i < num && strr1[i] == strr2[i] && strr1[i] && strr2[i])
		i++;
	if (i == num)
		return (strr1[i - 1] - strr2[i - 1]);
	else
		return (strr1[i] - strr2[i]);
}
