/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:27:56 by agym              #+#    #+#             */
/*   Updated: 2019/04/09 01:02:51 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s)
	{
		j = ft_strlen(s);
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
			i++;
		if (s[i] == '\0')
			return (ft_strdup(""));
		while ((s[j - 1] == ' ' || s[j - 1] == '\t' ||
					s[j - 1] == '\n') && s[i])
			j--;
		return (ft_strsub(s, i, (j - i)));
	}
	return (NULL);
}