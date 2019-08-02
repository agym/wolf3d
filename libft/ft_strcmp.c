/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 00:17:35 by agym              #+#    #+#             */
/*   Updated: 2019/04/02 00:43:52 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s;
	unsigned char	*p;
	int				j;

	s = (unsigned char *)s1;
	p = (unsigned char *)s2;
	i = 0;
	j = 0;
	while (s[i] != '\0' || p[j] != '\0')
	{
		if (s[i] != p[j])
			return (s[i] - p[j]);
		i++;
		j++;
	}
	return (0);
}
