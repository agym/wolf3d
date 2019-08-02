/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:18:05 by agym              #+#    #+#             */
/*   Updated: 2019/04/08 21:47:46 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst1;
	t_list	*temp;

	if (lst)
	{
		lst1 = (*f)(lst);
		temp = lst1;
		lst = lst->next;
		while (lst)
		{
			temp->next = (*f)(lst);
			lst = lst->next;
			temp = temp->next;
		}
		return (lst1);
	}
	return (NULL);
}
