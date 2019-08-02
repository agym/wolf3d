/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:07:48 by agym              #+#    #+#             */
/*   Updated: 2019/04/03 22:00:32 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*s1;

	i = 0;
	if (s)
	{
		len = ft_strlen(s);
		s1 = (char *)malloc(sizeof(char) * (len + 1));
		if (s1)
		{
			while (s[i])
			{
				s1[i] = (*f)((char)s[i]);
				i++;
			}
			s1[i] = '\0';
			return (s1);
		}
	}
	return (NULL);
}
