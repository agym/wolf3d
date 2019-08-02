/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 04:08:36 by agym              #+#    #+#             */
/*   Updated: 2019/04/08 23:39:23 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*chaine;

	if (!(chaine = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero((void *)chaine, size + 1);
	return (chaine);
}
