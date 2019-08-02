/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:41:25 by agym              #+#    #+#             */
/*   Updated: 2019/08/01 13:02:08 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

int			ft_clamp(int min, int max, int value)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	return (value);
}

int			ray_casting(t_info *info)
{
	int x = 0;
	int i;

	while (x < w_win)
	{
		info->ray.beta = (info->player.player_a - info->ray.fov / 2) +
		((double)x / (double)w_win) * info->ray.fov;
		/*for each colum , calculate the projected ray angle into wold space*/
		info->ray.distancetowall = 0.0;
		info->ray.hit = 0;
		/* unit vector of the deraction the player is looking at */
		info->player.unit_vect_x = sin(info->ray.beta);
		info->player.unit_vect_y = cos(info->ray.beta);
		while (info->ray.hit != 1 && info->ray.distancetowall < info->ray.steps)
		{
			info->ray.distancetowall += 0.001;
			info->ray.test_x = (int)(info->player.player_x +
			info->player.unit_vect_x * info->ray.distancetowall);
			info->ray.test_y = (int)(info->player.player_y +
			info->player.unit_vect_y * info->ray.distancetowall);
			if (info->ray.test_x < 0 || info->ray.test_x > info->player.len_map_x ||
			info->ray.test_y < 0 || info->ray.test_y > info->player.len_map_y)
			{
				info->ray.hit = 1;
				info->ray.distancetowall = info->ray.steps;
			}
			else
			{
				if (info->map1[info->ray.test_x][info->ray.test_y] != 0)
					info->ray.hit = 1;
			}
		}
		info->ray.distancetowall *= (rayfacing_left_right(info) == 1) ? cos(deg2rad(30)) : cos(deg2rad(-30));
		// ft_clamp il borne les valeure du cealing et floor pour que ne soit pas negative
		info->drow.cealing = ft_clamp(0, h_win / 2, (double)(h_win / 2.0) - h_win /
		(double)(info->ray.distancetowall));
		info->drow.floor = ft_clamp(h_win / 2, h_win, h_win - info->drow.cealing);
		// printf("|%d|--|%d|\n", info->drow.cealing, info->drow.floor);
		img(info, x, info->drow.cealing, info->drow.floor);
		i = 0;
		//  info->ray.beta += info->ray.alpha;
		x++;
	}
	mlx_put_image_to_window(info->mlx_f.mlx_ptr, info->mlx_f.win_ptr,
	info->mlx_f.img_ptr, 0, 0);
	return (0);
}

void		new_img(t_info *info)
{
	info->mlx_f.img_ptr = mlx_new_image(info->mlx_f.mlx_ptr, w_win, h_win);
	info->mlx_f.map = (int *)mlx_get_data_addr(info->mlx_f.img_ptr,
	&info->mlx_f.bits_per_pixel, &info->mlx_f.size_line, &info->mlx_f.endian);
}
