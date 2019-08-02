/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:05:31 by agym              #+#    #+#             */
/*   Updated: 2019/04/08 18:15:46 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*p;

	if ((p = (t_list *)malloc(sizeof(t_list))) != NULL)
	{
		if (content == NULL)
		{
			p->content = NULL;
			p->content_size = 0;
		}
		else
		{
			if (!(p->content = (void *)malloc(content_size)))
				return (NULL);
			ft_memcpy(p->content, content, content_size);
			p->content_size = content_size;
		}
		p->next = NULL;
		return (p);
	}
	return (NULL);
}
