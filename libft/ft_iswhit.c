/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:58:48 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/08/08 17:00:01 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhit(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}