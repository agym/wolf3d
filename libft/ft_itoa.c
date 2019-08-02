/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:01:49 by agym              #+#    #+#             */
/*   Updated: 2019/04/09 01:06:08 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			lentotal(int n)
{
	long			b;
	int				len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		b = n * -1;
	}
	else
		b = n;
	while (b != 0)
	{
		b = b / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	unsigned int	nb;
	char			*nb1;
	int				i;

	if ((nb1 = (char *)malloc(sizeof(char) * (lentotal(n) + 1))))
	{
		if (n < 0)
		{
			nb1[0] = '-';
			nb = n * -1;
		}
		else
			nb = n;
		if (nb == 0)
			nb1[0] = '0';
		nb1[lentotal(n)] = '\0';
		i = lentotal(n) - 1;
		while (nb != 0)
		{
			nb1[i--] = nb % 10 + '0';
			nb = nb / 10;
		}
		return (nb1);
	}
	return (NULL);
}
