/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:02:54 by agym              #+#    #+#             */
/*   Updated: 2019/06/24 19:11:55 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# define BUFF_SIZE 1000

typedef struct		s_liste
{
	char			*ls;
	int				nfd;
	struct s_liste	*next;
}					t_liste;

int					get_next_line(const int fd, char **line);
#endif
