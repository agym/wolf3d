#include "prototypes.h"

void	ft_setrgb_color(SDL_Color *col, Uint32 color)
{
	col->b = color % 256;
	col->g = (color / 256) % 256;
	col->r = (color / (256 * 256));
	col->a = 255;
}

int	main(int argc, char *argv[])
{
	t_map	map;
	int	h;
	int	 w;
	Uint32	time1;
	Uint32	time2;
	float	frame_time;
	t_point	 s;
	t_point	 d;
	t_input	in;
	Uint32	*pixels;
	t_player p = {12.0, 12.0, 0.0f};
	float	fov = M_PI / 4.0;
	float	max_dist = 24.0f;
	t_ptr ptr;

	(void)argc;
	time1 = 0;
	ft_read_file(&map, argv[1]);
	ft_sdl_init(&ptr, SCR_WIDTH, SCR_HEIGHT, "Hello");
	if (!(pixels = (Uint32 *)malloc(sizeof(Uint32) * SCR_WIDTH * SCR_HEIGHT)))
	{
		perror("Error Malloc pixels");
	}
	memset(pixels, 0, sizeof(Uint32) * SCR_WIDTH * SCR_HEIGHT);
	memset(&in, SDL_FALSE, sizeof(t_input));
	w = SCR_WIDTH;
	h = SCR_HEIGHT;
	time2 = SDL_GetTicks();
	while (!in.quit)
	{
	ft_update_event(&in);
		for (int x = 0; x < w; x++)
	{
		int	hit = 0;
		float	ray_angle = (p.angle - fov / 2) + ((float)x / (float)w) * fov;
		float	distance = 0.0;
		float	cam_x = sinf(ray_angle);
		float	cam_y = cosf(ray_angle);

		s.x = x;
		d.x = x;
		while (!hit && distance < max_dist)
		{
			distance += 0.1f;
			int	map_posx = (int)(p.x + cam_x * distance);
			int	map_posy = (int)(p.y + cam_y * distance);

			if (map_posx < 0 || map_posx >= map.w || map_posy < 0 || map_posy >= map.h)
			{
			 hit = 1;
			 distance = max_dist;
			}
			else
			{
			 if (map.tab[map_posy][map_posx] != 0)
			 hit = 1;
			}
		}

		int ceiling = ((float)(h / 2.0f)) - (h / ((float)distance));
		int floor = h - ceiling;
		for (int y = 0; y < h ; y++)
		{
		 if (y < ceiling)
		   pixels[y * SCR_WIDTH + x] = 0x000000;
		   else if (y >= ceiling && y <= floor)
		   pixels[y * SCR_WIDTH + x] = 0xFFFF00;
		   else
		   pixels[y * SCR_WIDTH + x] = 0x000000;
		}
	}
	ft_update_renderer(ptr, pixels);
	time1 = time2;
	time2 = GetTicks();
	frame_time = (float)(time2 - time1) / 100.0f;
	if (in.keys[SDL_SCANCODE_RIGHT])
	 p.angle -= 0.2f * frame_time;
	 if (in.keys[SDL_SCANCODE_LEFT])
	 {
	 p.angle += 0.2f * frame_time;
	}
	if (in.keys[SDL_SCANCODE_UP])
	{
	 p.x += 2.0f * sinf(p.angle) * frame_time;
	 p.y += 2.0f * cosf(p.angle) * frame_time;
	 if (map.tab[(int)p.y][(int)p.x])
	 {
	 p.x -= 2.0f * sinf(p.angle) * frame_time;
	 p.y -= 2.0f * cosf(p.angle) * frame_time;
	 }
	 }
	 if (in.keys[SDL_SCANCODE_DOWN])
	 {
	 p.x -= 2.0f * sinf(p.angle) * frame_time;
	 p.y -= 2.0f * cosf(p.angle) * frame_time;
	 if (map.tab[(int)p.y][(int)p.x])
	 {
	 p.x += 2.0f * sinf(p.angle) * frame_time;
	 p.y += 2.0f * cosf(p.angle) * frame_time;
	 }
	 }

	ft_clear_pixels(pixels);
	}
	ft_sdl_quit(&ptr);
 	return (0);
}	
