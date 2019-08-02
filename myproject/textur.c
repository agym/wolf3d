/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:03:54 by agym              #+#    #+#             */
/*   Updated: 2019/07/31 18:35:58 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/* SDL_RENDERER_ACCELERATED = Le renderer utilise l’accélération matérielle.
** Les données sont en mémoire vidéo, plus rapide que la mémoire vive.
** SDL_RENDERER_SOFTWARE  = Le renderer est logiciel, le rendu sera effectué
** par le CPU et les données seront stockées en mémoire vive (RAM).
** SDL_PIXELFORMAT_RGBA8888 =  
**SDL_Texture* SDL_CreateTexture(SDL_Renderer* renderer,
**                               Uint32        format,
**                               int           access,
**                               int           w,
**                               int           h);
** format :  qui represente les 4 valeure R / G / B / A
** access : correspond aux restrictions d’accès de notre structure on peux le
** donner 3 valeure : 1= SDL_TEXTUREACCESS_STATIC / 2= SDL_TEXTUREACCESS_STREAMING
** 3= SDL_TEXTUREACCESS_TARGET;
** 
*/

void	ft_sdl_quit(t_sdl_f *ptr)
{
	if (ptr->renderer)
		SDL_DestroyRenderer(ptr->renderer);
	if (ptr->renderer)
		SDL_DestroyWindow(ptr->window);
	if (ptr->texture)
		SDL_DestroyTexture(ptr->texture);
	ptr->renderer = NULL;
	ptr->window = NULL;
	ptr->texture = NULL;
}

void		ft_sdl_init(t_sdl_f *ptr, int w, int h, char *tile)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_sdl_error();
	ptr->window = SDL_CreateWindow(tile, SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
	if (ptr->window == NULL)
		ft_sdl_error();
	ptr->renderer = SDL_CreateRenderer(ptr->window, -1,
	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ptr->renderer == NULL)
		ft_sdl_error();
	ptr->texture = SDL_CreateTexture(ptr->renderer, SDL_PIXELFORMAT_RGBA8888,
	SDL_TEXTUREACCESS_STATIC, w, h);
	if (ptr->texture == NULL)
		ft_sdl_error();
}

void	ft_draw(t_sdl_f *ptr)
{
	SDL_RenderClear(ptr->renderer);
}

int		ft_update_renderer(t_sdl_f ptr, Uint32 *pixels)
{
	if (SDL_RenderClear(ptr.renderer))
	{
		ft_sdl_error();
		return (-1);
	}
	if (SDL_UpdateTexture(ptr.texture, NULL, pixels, wide * sizeof(Uint32)))
	{
		ft_sdl_error();
		return (-1);
	}
	if (SDL_RenderCopy(ptr.renderer, ptr.texture, NULL, NULL))
	{
		ft_sdl_error();
		return (-1);
	}
	SDL_RenderPresent(ptr.renderer);
	return (0);
}

/* Seul le format BMP est géré nativement par la SDL. */
/*pour charger une image on utilise la fonction : SDL_Surface* SDL_LoadBMP(const char* file) */

/*
** Charger notre image.
** Créer une texture à partir de notre image.
** Créer une autre texture de même dimension que la surface.
** Placer cette dernière texture en tant que cible de rendu.
** Copier la première texture sur la deuxième (avec SDL_RenderCopy).*/

int                sdl_img(t_sdl_f *ptr, t_img *img, char *file)
{
	img->tmp = SDL_LoadBMP(file);
	if (NULL == img->tmp)
		return (-1);
	img->texture = SDL_CreateTextureFromSurface(ptr->renderer, img->tmp);
	SDL_FreeSurface(img->tmp); /* On libère la surface, on n’en a plus besoin */
	if (NULL == img->texture)
		return (-1);
	return (0);
}

/*---------------------------------------------------------------------------------------*/

/* Dessiner sur une texture */

/* Nous avons précédemment dit que si l’on utilisait la valeur SDL_TEXTUREACCESS_TARGET, c’était pour
** pouvoir utiliser notre texture comme un renderer. Pour être plus précis, c’est pour pouvoir
** utiliser notre texture comme cible (« target ») de rendu. En fait, nous allons utiliser les
** fonctions de dessin vu au chapitre précédent, mais la cible du rendu ne sera plus le renderer
** mais la texture. Pour changer la cible de rendu, nous allons utiliser la fonction SDL_SetRenderTarget 
** Son prototype :
**
** int SDL_SetRenderTarget(SDL_Renderer* renderer,
**                        SDL_Texture*  texture)
*/

/* Afficher une texture */

/* Afficher une texture consiste à copier la texture sur le renderer puis à mettre à jour le renderer.
** Ainsi, on verra bien la texture à l’écran. La copie de la texture se fait avec la
** fonction SDL_RenderCopy dont le prototype est :
** int SDL_RenderCopy(SDL_Renderer*   renderer,
**                   SDL_Texture*    texture,
**                   const SDL_Rect* srcrect,
**                   const SDL_Rect* dstrect)
** srcrect : un pointeur sur un rectangle qui correspond à la
** partie de la texture à copier (en passant NULL, on copie toute la texture) ;
*/

/* s'avoir les dimentions de la texture SDL_QueryTexture : 
** SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
** int SDL_QueryTexture(SDL_Texture* texture,
**                     Uint32*      format,
**                     int*         access,
**                     int*         w,
**                     int*         h)
*/

/* Les pixels sont donc codés sur 32 bits dans ce format. Nous allons coder ces pixels avec le type
** Uint32 (il s’agit d’un type de 32 bits permettant de représenter des entiers) et chacune de ses
** composantes avec le type Uint8. Dans ce format, l’octet de poids
** fort représente le rouge et celui de poids faible représente le canal alpha.
*/