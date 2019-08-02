/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:40:05 by agym              #+#    #+#             */
/*   Updated: 2019/04/08 21:46:02 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	while (*alst)
	{
		temp = *alst;
		(*del)((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(temp);
	}
	alst = NULL;
}
