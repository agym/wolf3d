/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:59:47 by agym              #+#    #+#             */
/*   Updated: 2019/04/22 23:29:39 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_liste			*newlist(int fd, t_liste *head)
{
	t_liste		*temp;
	t_liste		*new;

	temp = head;
	new = (t_liste *)malloc(sizeof(t_liste));
	new->ls = ft_strnew(0);
	new->nfd = fd;
	new->next = NULL;
	if (head == NULL)
		return (new);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return (new);
}

t_liste			*find_fd(int fd, t_liste *head)
{
	t_liste		*tmp;

	tmp = head;
	while (tmp && tmp->nfd != fd)
		tmp = tmp->next;
	return (tmp);
}

int				get_the_line(t_liste *temp, char **line)
{
	int			i;
	char		*tnp;

	i = 0;
	while (temp->ls[i] != '\n' && temp->ls[i] != '\0')
		i++;
	if (ft_strlen(temp->ls) != 0)
	{
		*line = ft_strsub(temp->ls, 0, i);
		tnp = temp->ls;
		i = temp->ls[i] == '\n' ? i + 1 : i;
		temp->ls = ft_strdup(&(temp->ls[i]));
		free(tnp);
		return (1);
	}
	*line = NULL;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_liste	*lst;
	t_liste			*temp;
	int				read1;
	char			*tmp;
	char			red[BUFF_SIZE + 1];

	temp = lst;
	if (fd < 0 || read(fd, red, 0) < 0 || !line)
		return (-1);
	if (lst == NULL)
		lst = newlist(fd, lst);
	if ((temp = find_fd(fd, lst)) == NULL)
		temp = newlist(fd, lst);
	while ((read1 = read(fd, red, BUFF_SIZE)) > 0)
	{
		red[read1] = '\0';
		tmp = temp->ls;
		temp->ls = ft_strjoin(temp->ls, red);
		free(tmp);
		if (ft_strchr(temp->ls, '\n'))
			break ;
	}
	return (get_the_line(temp, line));
}
