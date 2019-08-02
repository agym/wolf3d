
#include "prototypes.h"

void	ft_sdl_error(void)
{
	perror("Error SDL");
	perror(SDL_GetError());
	exit(EXIT_FAILURE);
}

void	ft_sdl_init(t_ptr *ptr, int w, int h, char *title)
{
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_sdl_error();                                                                       
	ptr->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	ptr->renderer = SDL_CreateRenderer(ptr->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	ptr->texture = SDL_CreateTexture(ptr->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, w, h);

}

void	ft_clear_pixels(Uint32 *pixels)
{
	int i = SCR_WIDTH * SCR_HEIGHT;

	while (--i >= 0)
	 pixels[i] = 0x00000;
}

void	ft_draw(t_ptr *ptr)
{
	SDL_RenderClear(ptr->renderer);
}

int		ft_update_renderer(t_ptr ptr, Uint32 *pixels)
{
	if (SDL_RenderClear(ptr.renderer))
	{
		ft_sdl_error();
		return (-1);
	}
	if (SDL_UpdateTexture(ptr.texture, NULL, pixels, SCR_WIDTH * sizeof(Uint32)))
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

void	ft_sdl_quit(t_ptr *ptr)
{
	if (ptr->renderer)
		SDL_DestroyRenderer(ptr->renderer);
	if (ptr->renderer)
		SDL_DestroyWindow(ptr->window);
	ptr->renderer = NULL;
	ptr->window = NULL;
} 
