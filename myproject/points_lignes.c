/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_lignes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:10:15 by agym              #+#    #+#             */
/*   Updated: 2019/07/31 15:10:34 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/* Dessiner des points et des lignes : SDL_RenderDrawPoint / SDL_ */

int		ft_put_point_to_window(t_sdl_f *ptr, SDL_Color color, SDL_Point point)
{
	if (0 != SDL_SetRenderDrawColor(ptr->renderer, color.r, color.g, color.b, color.a))
		return (-1);
	if (0 != SDL_RenderDrawPoint(ptr->renderer, point.x, point.y))
		return (-1);
	return (0);
}

int		ft_sdl_draw_line(t_sdl_f *ptr, SDL_Point p1, SDL_Point p2, SDL_Color color)
{
	if (0 != SDL_SetRenderDrawColor(ptr->renderer, color.r, color.g, color.b, color.a))
		return (-1);
	if (0 != SDL_RenderDrawLine(ptr->renderer, p1.x, p1.y, p2.x, p2.y))
		return (-1);
	return (0);
}
/*------------------------------------------------------------------*/