/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 21:31:26 by agym              #+#    #+#             */
/*   Updated: 2019/04/08 21:56:26 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)src;
	dest1 = (unsigned char *)dst;
	while (i < n)
	{
		dest1[i] = str[i];
		i++;
	}
	return (dst);
}
