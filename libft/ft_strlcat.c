/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:35:32 by agym              #+#    #+#             */
/*   Updated: 2019/04/02 21:53:13 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t ldest;
	size_t lsrc;
	size_t i;
	size_t a;

	i = 0;
	a = 0;
	ldest = ft_strlen((const char *)dst);
	lsrc = ft_strlen(src);
	if (ldest < size)
		a = ldest + lsrc;
	else
		a = lsrc + size;
	while (src[i] != '\0' && ldest + 1 < size)
	{
		dst[ldest] = src[i];
		i++;
		ldest++;
	}
	dst[ldest] = '\0';
	return (a);
}
