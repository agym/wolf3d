/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:37:42 by agym              #+#    #+#             */
/*   Updated: 2019/04/03 17:40:13 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;

	if ((s = (char *)malloc(len)))
	{
		s = ft_memcpy(s, src, len);
		dst = ft_memcpy(dst, s, len);
		free(s);
	}
	return (dst);
}
