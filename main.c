/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:16:33 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/09/19 19:02:56 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_mlx_init(t_p *p)
{
	int b_p;
	int s_l;
	int endian;

	p->init = mlx_init();
	p->win = mlx_new_window(p->init, WIDTH, HEIGTH, "WOLF");
	p->img = mlx_new_image(p->init, WIDTH, HEIGTH);
	p->data = (unsigned int *)mlx_get_data_addr(p->img, &b_p, &s_l, &endian);
}
/////////////////////vect rot/////////////////////
t_vf	vec_rot(t_vf v, float a)
{
	t_vf	v1;
	v1.x = v.x * cos(a) - v.y * sin(a);
	v1.y = v.x * sin(a) + v.y * cos(a);
	return (v1);
}

t_vf	vec_sub(t_vf v1, t_vf v2)
{
	t_vf v0;

	v0.x = v1.x - v2.x;
	v0.y = v1.y - v2.y;
	return v0;
}

t_vf	vec_mult(t_vf v1, float a)
{
	t_vf v0;

	v0.x = v1.x * a;
	v0.y = v1.y * a;
	return v0;
}

t_vf	vec_add(t_vf v1, t_vf v2)
{
	t_vf v0;

	v0.x = v1.x + v2.x;
	v0.y = v1.y + v2.y;
	return v0;
}

void		ft_error(void)
{
	ft_putstr("texture not been fond");
	exit(0);
}

/////////////////////********/////////////////////

float	ft_rad(float a)
{
	return ((a * M_PI) / 180);
}
//////////////////////////////////////////////////

t_vf	vec_normalise(t_vf v)
{
	t_vf v1;
	float a;

	a = sqrtf(v.x * v.x + (v.y * v.y));
	v1.x = v1.x / a;
	v1.y = v1.y / a;
	return v1;
}

float	vec_dot(t_vf v, t_vf v1)
{
	float a;

	a = v.x * v1.x + (v.y * v1.y);
	return a;
}
/////////////////hit check//////////////////////

/////////////////////////////////////////////////
double	ft_alpha(t_vf dir)
{
	t_vf v;
	float alpha;

	if (dir.x < 0)
		v = (t_vf){-1, 0};
	else if (dir.x >= 0)
		v = (t_vf){1, 0};
	alpha = acosf(vec_dot(dir, v));
	return alpha;
}

void	ft_setvertical_variable(t_player player,t_vf *grid_point, t_vf *step, float alpha)
{
	t_vf dir;
	float x;

	dir = player.dir_colum;
	if (dir.x >= 0)
	{
		(*grid_point).x =  (int)(player.pos.x / 64) * 64 + 64;
		x = grid_point->x;
		(*step).x = 64;
	}
	else
	{
		(*grid_point).x = (int)(player.pos.x / 64) * 64 - 1;
		x = grid_point->x + 1;
		if ((*grid_point).x < 0)
			(*grid_point).x = 0;
		(*step).x = -64;
	}
	if (dir.y >= 0)
	{
		(*grid_point).y = player.pos.y + (fabsf(player.pos.x - x) * tan(alpha));
		(*step).y = 64 * tan(alpha);
	}
	else
	{
		(*grid_point).y = player.pos.y - (fabsf(player.pos.x - x) * tan(alpha));
		(*step).y = - 64 * tan(alpha);
	}
	if (grid_point->x < 0)
		grid_point->x = 0;
	if (grid_point->y < 0)
		grid_point->y = 0;
}

void	ft_sethorizontal_variable(t_player player,t_vf *grid_point, t_vf *step, float alpha)
{
	t_vf	dir;
	float	y;

	dir = player.dir_colum;
	if (dir.y >= 0)
	{
		grid_point->y = (int)(player.pos.y /64) * 64 + 64;
		y = grid_point->y;
		step->y = 64;
	}
	else
	{
		grid_point->y = (int)(player.pos.y / 64) * 64 - 1;
		y = grid_point->y + 1;
		step->y = -64;
	}
	if (dir.x >= 0)
	{
		grid_point->x = player.pos.x + (fabsf(player.pos.y - y) / tan(alpha));
		step->x = 64 / tan(alpha);
	}
	else
	{
		grid_point->x = player.pos.x - (fabsf(player.pos.y - y) / tan(alpha));
		step->x = - 64 / tan(alpha);
	}
	if (grid_point->x < 0)
		grid_point->x = 0;
	if (grid_point->y < 0)
		grid_point->y = 0;
}

t_hit	ft_vertical_check(t_player player, float alpha, t_map map, double xx)
{
	t_vf	grid_point;
	t_vf	step;
	int hit;
	t_hit	v_info;
	double x;
	double y;

	hit = 0;
	ft_setvertical_variable(player, &grid_point, &step,alpha);
	v_info.distance = 1e30;
	while (hit == 0 && grid_point.y > 0 && grid_point.y < map.dim.y * 64)
	{
		if ((int)xx == WIDTH /2)
		printf("point A = x %f, y %f\n", grid_point.x, grid_point.y);
		x = (grid_point.x / 64);
		y = (grid_point.y / 64);
		if (map.map[(int)y][(int)x] != 0)
		{
			hit = 1;
			v_info.distance = fabsf(player.pos.y - grid_point.y) / sin(alpha);
			v_info.x = x;
			v_info.y = y;
			break ;
		}
		grid_point = vec_add(grid_point, step);
	}
	return v_info;
}

t_hit	ft_horizontal_check(t_player player, float alpha, t_map map, double xx)
{
	t_vf	grid_point;
	t_vf	step;
	int		hit;
	t_hit	h_info;
	double x;
	double y;

	hit = 0;
	ft_sethorizontal_variable(player, &grid_point, &step,alpha);
	h_info.distance = 1e30;
	while (hit == 0 && grid_point.x > 0 && grid_point.x < map.dim.x * 64)
	{
		if ((int)xx == WIDTH /2)
		printf("point A = x %f, y %f\n", grid_point.x, grid_point.y);
		x = (grid_point.x / 64);
		y = (grid_point.y / 64);
		if (map.map[(int)y][(int)x] != 0)
		{
			hit = 1;
			h_info.distance = fabsf(player.pos.x - grid_point.x) / cos(alpha);
			h_info.x = x;
			h_info.y = y;
			break ;
		}
		grid_point = vec_add(grid_point, step);
	}
	return h_info;
}

//////////////////////texture/////////////

t_img			ft_mlx_load_image(void *mlx_ptr, char *filename, t_vi size)
{
	t_img		img;

	img.img_ptr = mlx_xpm_file_to_image(mlx_ptr, filename, &size.x, &size.y);
	if (!img.img_ptr)
	{
		ft_putendl("File !!");
		ft_putendl(filename);
		ft_error();
	}
	img.data = (unsigned int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_len,
	&img.endian);
	return (img);
}

void		load_image(t_p *info)
{
	t_vi	size;

	size.x = 64;
	size.y = 64;
	info->text[0] = ft_mlx_load_image(info->init,
	"./textures/stone.xpm", size);
	info->text[1] = ft_mlx_load_image(info->init,
	"./textures/sky.xpm", size);
	info->text[2] = ft_mlx_load_image(info->init,
	"./textures/sand.xpm", size);
	info->text[3] = ft_mlx_load_image(info->init,
	"./textures/redbrick.xpm", size);
	info->text[4] = ft_mlx_load_image(info->init,
	"./textures/wood.xpm", size);
}

double	ft_min_value(double t1, double t2)
{
	if (t1 > t2)
		t1 = t2;
	if (t1 < 0)
		t1 = 0;
	return t1;
}

int		hit_vertical_horizontal(double t1, double t2)
{
	if (ft_min_value(t1, t2) == t1)
		return (1);
	return (0);
}

void	ft_light_pixel(t_p *p, int x, int y, t_hit t1,
t_hit t2, double l)
{
	int i;
	int j;
	int g;
	t_vf temp;

	temp.x = (double)y / (2 * WIDTH);
	temp.y = (hit_vertical_horizontal(t1.distance, t2.distance) ?
	t1.y - (int)t1.y : t2.y - (int)t2.y);
	temp.x = temp.x * 64;
	temp.y = temp.y * 64;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGTH)
		return ;
	i = y * HEIGTH + x;
	p->data[i] = p->text[0].data[64 * (y % 64) + (int)temp.y];
}

void	ft_draw_colum(double distance, double plane_distance,
t_p *p, int x, t_hit t1, t_hit t2)
{
		int y;
		int y_max;
		double wall_height;
		double l;
		int k;

		wall_height = 64 / distance * plane_distance;
		y = HEIGTH / 2 - (wall_height / 2);
		y_max = HEIGTH / 2 + (wall_height / 2);
		l = y_max - y;
		while (y < y_max)
			ft_light_pixel(p, x, y++, t1, t2, l);
}

////////////////////////////******/////////////////

double 	ft_true_distance(double distance, double ang_column, int x)
{
	distance = distance * cos(0.523599 - (x * ang_column));
	return distance;
}

void	ft_loop(t_player player, t_map map, t_p *param)
{
	int x;
	t_hit t1, t2;
	double	true_1, true_2;
	t_vf dir;
	double ang_colum;
	double i;
	double	alpha;
	double	p_dist;
	static t_vf player_check;
	double xx;
	double yy;

	load_image(param);
	yy = (player.pos.y / 64);
	xx = (player.pos.x / 64);
	if (map.map[(int)yy][(int)xx] == 0)
		player_check = player.pos;
	else
		player.pos = player_check;
	param->player = player;
	ang_colum = 60 / (double)WIDTH;
	ang_colum = ft_rad(ang_colum);
	p_dist = (int)((WIDTH / 2) / tan(ft_rad(30)));
	x = 0;
	i = 0;
	while (x < WIDTH)
	{
		if (x == WIDTH / 2)
			system("clear");
		player.dir_colum = vec_rot(player.dir, -0.523599 + i);
		alpha = ft_alpha(player.dir_colum);
		t1 = ft_vertical_check(player, alpha, map, x);
		true_1 = ft_true_distance(t1.distance, ang_colum, x);
		if (x == WIDTH / 2)
			printf("distance *t1*: %f\n", t1.distance);
		t2 = ft_horizontal_check(player, alpha, map,x);
		true_2 = ft_true_distance(t2.distance, ang_colum, x);
		if (x == WIDTH / 2)
			printf("distance *t2*: %f\n", t2.distance);
		true_1 = ft_min_value(true_1, true_2);
		ft_draw_colum(true_1, p_dist, param, x, t1, t2);
		i += ang_colum;
		x++;
	}
	mlx_put_image_to_window(param->init, param->win, param->img, 0, 0);
	x = 0;
	while (x < WIDTH)
		mlx_pixel_put(param->init, param->win, x++, HEIGTH / 2, 0xff0000);
	x = 0;
	while (x < WIDTH)
		mlx_pixel_put(param->init, param->win, WIDTH / 2, x++, 0xff0000);
}
void	ft_init(t_p *p, t_map map)
{
	t_player ply;

	ply.pos = (t_vf){1,1};
	ply.pos.x *= 64 + 32;
	ply.pos.y *= 64 + 32;
	ply.dir = (t_vf){0, -1};
	ft_loop(ply, map, p);
}

int ft_close(void *param)
{
	t_p *p;
	
	p = (t_p *)param;
	mlx_destroy_image(p->init, p->img);
	mlx_destroy_window(p->init, p->win);
	free(p);
	puts("-----------------------------");
    exit(0);
}

int		t_kees(int key, t_p *p)
{
	int step;

	step = 3;
	if (key == 53)
		ft_close(p);
	if (key == 126 || key == 13)
		p->player.pos = vec_add(p->player.pos, vec_mult(p->player.dir, step));
	if (key == 125 || key == 1)
		p->player.pos = vec_sub(p->player.pos, vec_mult(p->player.dir, step));
	if (key == 123 || key == 0)
		p->player.pos = vec_add(p->player.pos, vec_mult(vec_rot(p->player.dir, 1.5708), -step));
	if (key == 14)
	{
		p->player.pos = vec_add(p->player.pos, vec_mult(vec_rot(p->player.dir, 0.523599), step));
	}
	if (key == 12)
	{
		p->player.pos = vec_add(p->player.pos, vec_mult(vec_rot(p->player.dir, -0.523599), step));
	}
	if (key == 124 || key == 2)
		p->player.pos = vec_add(p->player.pos, vec_mult(vec_rot(p->player.dir, 1.5708), step));
	if (key == 40)
		p->player.dir = vec_rot(p->player.dir, 0.1);
	if (key == 38)
		p->player.dir = vec_rot(p->player.dir, -0.1);
	if (key == 53)
		exit(0);
	ft_bzero(p->data, WIDTH * HEIGTH * 4);
	ft_loop(p->player, p->map, p);
	return (1);
}

int			mlx_events(t_p *p)
{
	mlx_hook(p->win, 2, 17, t_kees, p);
	mlx_hook(p->win, 17, 0, ft_close, p);
	return (0);
}

int main(int ac, char **av)
{
	t_p *p;
	t_map map;

	if (!(p = (t_p *)malloc(sizeof(t_p))))
		return 0;
	ft_mlx_init(p);
	p->map = ft_read_file(av[1]);
	ft_init(p, p->map);
	mlx_events(p);
	mlx_hook(p->win, 2, 1, t_kees, p);
	mlx_loop(p->init);
}