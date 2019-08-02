/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:06:35 by agym              #+#    #+#             */
/*   Updated: 2019/04/03 17:11:00 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*s2;
	int				len;

	s2 = (unsigned char *)s;
	i = 0;
	len = ft_strlen(s);
	while (s2[i] != '\0')
	{
		if (s2[i] == c)
			return ((char *)s);
		i++;
		s++;
	}
	if (s2[i] != c)
		return (NULL);
	else if (s2[i] == '\0')
		return ((char *)s2 + len);
	else
		return ((char *)s2);
	return (0);
}
