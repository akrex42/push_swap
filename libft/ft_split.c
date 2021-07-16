/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:30:40 by akrex             #+#    #+#             */
/*   Updated: 2020/11/18 13:34:45 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wc(const char *s, char c)
{
	int	wordnumber;
	int	i;

	wordnumber = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			wordnumber++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (wordnumber);
}

static char	*ft_everyword(const char *s, char c)
{
	int		i;
	char	*word;
	int		j;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	j = i;
	while (s[j] && s[j] != c)
		j++;
	word = ft_substr(s, i, j);
	if (!word)
		return (NULL);
	return (word);
}

static char	*ft_free(char **splitted, int wordcount)
{
	while (wordcount--)
		free(splitted[wordcount]);
	free(splitted);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;

	i = 0;
	splitted = (char **)malloc((ft_wc(s, c) + 1) * sizeof(char *));
	if (!s || !splitted)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			splitted[i] = ft_everyword(s, c);
			if (!(splitted[i]))
				ft_free(splitted, i);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	splitted[i] = NULL;
	return (splitted);
}
