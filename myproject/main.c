/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:46:26 by agym              #+#    #+#             */
/*   Updated: 2019/07/31 19:11:58 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			main()
{
	t_sdl_f ptr;
	SDL_Point point2;
	SDL_Point point1;
	SDL_Color color1 = {0, 0, 0, 255};
	t_img img;
	// SDL_Color color = {255, 50, 40, 255};

	point2.x = 500;
	point2.y = 500;
	point1.x = 1000;
	point1.y = 1000;
	ft_sdl_init(&ptr, wide, hight, "wolf3d");
	if (ft_set_render_color(&ptr, color1) == -1)
		ft_sdl_error();
	SDL_Rect dst = {50, 50, 100, 100};
	SDL_Rect src = {10, 10, 20, 30};
	if (ft_set_render_color(&ptr, color1) == -1)
		ft_sdl_error();
	if (0 != SDL_RenderCopy(ptr.renderer, ptr.texture, &src, &dst))
		ft_sdl_error();
	if (sdl_img(&ptr, &img, "/Users/agym/Desktop/images.bmp") != 0)
		printf("node a wa node \n");
	SDL_RenderCopy(ptr.renderer, img.texture, NULL, NULL);
	SDL_RenderPresent(ptr.renderer);
	SDL_Delay(6000);
	return (STATUSS);
}