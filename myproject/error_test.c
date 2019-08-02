/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:15:21 by agym              #+#    #+#             */
/*   Updated: 2019/07/31 17:15:56 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			ft_sdl_error()
{
	perror("Error in Sdl");
	perror(SDL_GetError());
	exit(STATUSF);
}

/* tester l'aparition d'une point dan un rectangle */
/* SDL_rect et une structu re definie par SDl il port 4 entier 
** x / y / h / w
** SDL_Point contient les compossents d'une point x et y
** 1 = On dessine à l’aide du renderer.
** 2 = On met à jour l’écran avec le renderer.
*/

SDL_bool	ft_test_aparition_rectangle(SDL_Point point2, SDL_Rect point1)
{
	if (point2.x >= point1.x && point2.x <= (point1.x + point1.w)
	&& point2.y >= point1.y && point2.y <= (point1.y + point1.h))
		return(SDL_TRUE);
	else
		return(SDL_FALSE);
}

/* SDL_SetRenderDrawColor : Choisir la couleur de dessin */
/* SDL_RenderClear :  Changer la couleur en nettoyont le renderer */
/* SDL_RenderPresent: Mise à jour de l’affichage*/
/* */

int		ft_set_render_color(t_sdl_f *ptr, SDL_Color color)
{
	if (0 != SDL_SetRenderDrawColor(ptr->renderer, color.r, color.g, color.b, color.a))
		return (-1);
    if (0 != SDL_RenderClear(ptr->renderer))
		return (-1);
	return (0);
}