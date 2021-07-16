/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:13:29 by akrex             #+#    #+#             */
/*   Updated: 2020/11/18 14:03:20 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long long n)
{
	int	nbrlen;

	nbrlen = 1;
	while (n)
	{
		nbrlen++;
		n /= 10;
	}
	return (nbrlen);
}

static void	ft_tostring(long long n, char *number, int i)
{
	if (n == 0)
		number[0] = '0';
	else if (n < 0)
	{
		n = n * (-1);
		number[0] = '-';
	}
	number[i - 1] = '\0';
	i--;
	while (n > 0)
	{
		number[i - 1] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int			len;
	long long	nn;
	char		*number;

	nn = n;
	len = 0;
	if (nn < 0)
		len = ft_nbrlen(nn) + 2;
	else
		len = ft_nbrlen(nn) + 1;
	number = (char *)malloc(len * sizeof(char));
	if (!number)
		return (NULL);
	ft_tostring(nn, number, len);
	return (number);
}
