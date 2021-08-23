/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:19:53 by akrex             #+#    #+#             */
/*   Updated: 2020/11/18 12:54:01 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_str(const char *str)
{
	int	i;

	i = 0;
	if (!ft_strncmp(str, "", 1) || !ft_strncmp(str, "+", ft_strlen(str))
		|| !ft_strncmp(str, "-", ft_strlen(str)))
	{
		ft_putendl_fd("Error", 2);
		exit (-1);
	}
	while (str[i])
	{
		if (!(ft_isdigit(str[i])) && str[i] != '-' && str[i] != '+')
		{
			ft_putendl_fd("Error", 2);
			exit (-1);
		}
		i++;
	}
}

long	check_number(const char *str, int i, long res)
{
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - '0');
		if (res > INT_MAX)
		{
			ft_putendl_fd("Error", 2);
			exit (-1);
		}
		i++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int			i;
	long		res;
	int			minus;

	minus = 1;
	res = 0;
	i = 0;
	check_str(str);
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	res = check_number(str, i, res);
	return (res * minus);
}
