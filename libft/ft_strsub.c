/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 23:22:01 by agym              #+#    #+#             */
/*   Updated: 2019/04/09 00:10:18 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	lens;
	size_t	i;
	size_t	j;

	i = 0;
	if (s)
	{
		lens = ft_strlen(s);
		if (start >= lens)
			return (NULL);
		else
		{
			j = start;
			if ((s1 = (char *)malloc(sizeof(char) * (len + 1))))
			{
				while (s[j] && j < start + len)
					s1[i++] = s[j++];
				s1[i] = '\0';
				return (s1);
			}
			return (NULL);
		}
	}
	return (NULL);
}
