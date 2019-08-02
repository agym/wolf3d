/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:13:14 by agym              #+#    #+#             */
/*   Updated: 2019/08/02 01:47:07 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
#define WOLF_H
#include "mlx.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include "math.h"
# define w_win 1900
# define h_win 1080
# define w_menue 1080
# define h_menue 540

typedef struct	s_point2d1
{
	int		x;
	int		y;
}				t_point2d1;

typedef struct	s_vec2
{
	double	x;
	double	y;
}				t_vec2;

typedef struct	s_point2d
{
	int		x;
	int		y;
	struct s_point2d *next;
}				t_point2d;


typedef struct	s_point
{
	int			len_map_x;
	int			len_map_y;
	double		player_x;
	double		player_y;
	double		player_a;
	double		unit_vect_x;
	double		unit_vect_y;
	int			x;
	int			y;
}				t_point;

typedef struct  s_bresenhame
{
    int         dx;
    int         dy;
    int         xi;
    int         yi;
    int         p;
    int         x;
    int         y;
    int         collor;
}               t_bre_h_l;

typedef struct	s_ray
{
	double		fov;
	double		beta;
	double		distancetowall;
	double		steps;
	int			hit;
	int			test_x;
	int			test_y;
	int			nb[10];
}				t_ray;

typedef	struct	s_drow
{
	int			cealing;
	int			floor;
	double			speed;
}				t_drow;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			*map;
}				t_mlx;

typedef struct	s_textur
{
	void		*img_ptr;
	int			bpp;
	int			size_len;
	int			endian;
	int			*data;
}				t_img;

typedef struct	s_info
{
	int			**map1;
	int			argc;
	char		**argv;
	t_mlx		mlx_f;
	t_mlx		mlx_f1;
	t_ray		ray;
	t_point		player;
	t_drow		drow;
	t_point		size[13];
	t_img		img[8];
	t_point2d	p[2];
	int			cnt;
	int			in[8];
	t_point2d	*head;
	int			indice;
	t_point2d1 max_min;
}				t_info;

// read of the file

int			nb_of_lines(char **argv);
int			*tab_cara_to_int(char **lines, int i);
int			nb_cara_in_line1(char *line);
int			len(char **line);
int			**no_file_map_error(t_info *info, int argc, char **argv, int j);
void		free_tab(char **lines);
// end of the read
void		initial(t_info *info);
int		ray_casting(t_info *info);
void		new_img(t_info *info);
void		img(t_info *info, int xx, int x, int y);
void		ft_error(void);
void		free_tab1(int **lines, char **argv);
void		mlx_events(t_info *info);
double		deg2rad(int deg);
void		load_image(t_info *info);
t_img		ft_mlx_load_image(void *mlx_ptr, char *filename, t_point size);
void		map_pl(t_info *info);
int     	rayfacing_left_right(t_info *info);
/*---------------------------------------------------------------------------*/
/* MENUE */
void			put_image_to_menue(t_info *info, int nb_texture);
void            mlx_events_menue(t_info *info);
int             key_press_menue_mose(int key, int x, int y, t_info *info);
int				key_press_menue_key(int key, t_info *info);
void            main_bresenham(t_info *info, t_point2d p1, t_point2d p2);
#endif