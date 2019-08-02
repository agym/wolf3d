#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include <SDL2/SDL.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"

# define MAX_SIZE 500

# define SCR_WIDTH 1200
# define SCR_HEIGHT 649

typedef struct	s_ptr
{
	SDL_Window	*window;
	SDL_Renderer 	*renderer;
	SDL_Texture	*texture;
}		t_ptr;

typedef struct	s_vect2d
{
	double	x;
	double	y;
}		t_vect2d;

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;


typedef struct	s_player
{
	float	x;
	float	y;
	float	angle;
}		t_player;

typedef struct	s_map
{
	int	w;
	int	h;
	int	tab[MAX_SIZE][MAX_SIZE];
}		t_map;

typedef struct		s_input
{
	int		quit;
	int		mousex;
	int		mousey;
	int		xwheel;
	int		ywheel;
	int		mousexrel;
	int		mouseyrel;
	int		mouse[6];
	int		keys[SDL_NUM_SCANCODES];
}					t_input;



void	ft_clear_pixels(Uint32 *pixels);
void		ft_update_event(t_input *in);

int		ft_update_renderer(t_ptr ptr, Uint32 *pixels);
void		ft_sdl_draw_line(Uint32 *pixels, t_point p1, t_point p2, Uint32 color);

void		ft_sdl_draw_disc(Uint32 *pixels, t_point co, int radius, Uint32 color);
t_vect2d	ft_vector(double x, double y);
t_point		ft_point(int x, int y);
void		ft_setvector(t_vect2d *v, double x, double y);

void		ft_sdl_quit(t_ptr *ptr);
void		ft_sdl_error(void);
void		ft_sdl_init(t_ptr *ptr, int w, int h, char *title);
void		ft_draw(t_ptr *ptr);

void		ft_error(void);
void		ft_fill_map(t_map *m, char *line, int y);
void		ft_read_file(t_map *m, char *file_name);
#endif

