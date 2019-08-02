/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:01:28 by agym              #+#    #+#             */
/*   Updated: 2019/04/03 22:00:05 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	lens;
	unsigned int	i;
	char			*s1;

	i = 0;
	if (s)
	{
		lens = ft_strlen(s);
		s1 = (char *)malloc(sizeof(char) * (lens + 1));
		if (s1)
		{
			while (s[i])
			{
				s1[i] = (*f)(i, s[i]);
				i++;
			}
			s1[i] = '\0';
			return (s1);
		}
	}
	return (NULL);
}
