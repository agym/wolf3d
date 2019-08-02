/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:41:57 by agym              #+#    #+#             */
/*   Updated: 2019/04/08 22:45:54 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		long_words(const char *s, char c, char **tab)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	j = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c)
			len++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			tab[j++] = (char *)malloc(sizeof(char) * (len + 1));
			len = 0;
		}
		i++;
	}
}

static char		**ft_strcppi(const char *s, char c, char **tab)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	j = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c)
			tab[len][j++] = s[i];
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			tab[len][j] = '\0';
			j = 0;
			len++;
		}
		i++;
	}
	return (tab);
}

char			**ft_strsplit(const char *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
				j++;
			i++;
		}
		if (!(tab = (char **)malloc(sizeof(char *) * (j + 1))))
			return (NULL);
		tab[j] = NULL;
		long_words(s, c, tab);
		ft_strcppi(s, c, tab);
		return (tab);
	}
	return (NULL);
}
