/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:45:36 by agym              #+#    #+#             */
/*   Updated: 2019/07/29 14:36:58 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void		free_tab(char **lines)
{
	int		i;

	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}

void		ft_error(void)
{
	ft_putstr("texture not been fond");
	exit(0);
}

double			deg2rad(int deg)
{
	return (deg * (M_PI / 180));
}

// int     rayfacing_up_down(t_info *info)
// {
    //  if (info->ray.beta > 0 && info->ray.beta < M_PI) /*facing up*/
        //  return (1);
    //  else
        //  return (0); /*facing down*/
// }

int     rayfacing_left_right(t_info *info)
{
     if (info->ray.beta > 1.5 * M_PI || info->ray.beta < 0.5 * M_PI) /*facing Right*/
         return (0);
     else
         return (1); /*facing left*/
}