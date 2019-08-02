/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:46:05 by agym              #+#    #+#             */
/*   Updated: 2019/07/31 18:35:06 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WOLF_H
# define WOLF_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
# define STATUSS  EXIT_SUCCESS
# define STATUSF  EXIT_FAILURE
# define wide 2080
# define hight 1080

typedef struct s_sdl_f
{
	SDL_Window *window;
	SDL_Renderer *renderer; /*permet de dessiner dans window*/
	SDL_Texture *texture;
}				t_sdl_f;

typedef	struct s_img
{
	SDL_Surface *tmp; 
	SDL_Texture *texture;
}				t_img;


typedef struct  s_wolf
{
	SDL_Surface *surface;
}               t_info;

void			ft_sdl_error();
void	ft_sdl_quit(t_sdl_f *ptr);
SDL_bool	ft_test_aparition_rectangle(SDL_Point point2, SDL_Rect point1);
int		ft_set_render_color(t_sdl_f *ptr, SDL_Color color);
int		ft_put_point_to_window(t_sdl_f *ptr, SDL_Color color, SDL_Point point);
int		ft_sdl_draw_line(t_sdl_f *ptr, SDL_Point p1, SDL_Point p2, SDL_Color color);
void		ft_sdl_init(t_sdl_f *ptr, int w, int h, char *tile);
void	ft_draw(t_sdl_f *ptr);
int		ft_update_renderer(t_sdl_f ptr, Uint32 *pixels);
int		sdl_img(t_sdl_f *ptr, t_img *img, char *file);

#endif