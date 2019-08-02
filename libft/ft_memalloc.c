/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 02:44:42 by agym              #+#    #+#             */
/*   Updated: 2019/04/09 17:04:50 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero((void *)s, size);
	return ((void *)s);
}
