/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 00:15:19 by agym              #+#    #+#             */
/*   Updated: 2019/04/03 17:14:15 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	lens1;
	size_t	lens2;

	if (s1 && s2)
	{
		lens1 = ft_strlen(s1);
		lens2 = ft_strlen(s2);
		s3 = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
		if (s3)
		{
			return (ft_strcat(ft_strcpy((char *)s3, s1), s2));
		}
		return (NULL);
	}
	return (NULL);
}
