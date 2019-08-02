/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 00:39:28 by agym              #+#    #+#             */
/*   Updated: 2019/04/02 01:05:24 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*p;

	s = (unsigned char *)s1;
	p = (unsigned char *)s2;
	i = 0;
	while ((s[i] || p[i]) && (i < n))
	{
		if (s[i] != p[i])
			return (s[i] - p[i]);
		i++;
	}
	return (0);
}
