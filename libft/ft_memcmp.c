/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:53:36 by agym              #+#    #+#             */
/*   Updated: 2019/04/03 17:06:09 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s;
	unsigned char	*p;
	size_t			i;

	s = (unsigned char *)s1;
	p = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s[i] != p[i])
			return (s[i] - p[i]);
		i++;
	}
	return (0);
}
