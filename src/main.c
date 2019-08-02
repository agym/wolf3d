/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:13:06 by agym              #+#    #+#             */
/*   Updated: 2019/08/02 00:05:58 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

/*
** flat plane
** square grid only
** untextured floor and ceiling
*/

// void	ft_print_map(int **m, int w, int h)
// {
// 	int		x, y;

// 	write(1, "-----------------------------------------\n", 42);
// 	y = -1;
// 	while (++y < h)
// 	{
// 		x = -1;
// 		while (++x < w)
// 		{
// 		 ft_putnbr(m[y][x]);
// 		 write(1, " ", 1);
// 		}
// 		 write(1, "\n", 1);
// 	}
// 	write(1, "-----------------------------------------\n", 42);
// }

int				main(int argc, char **argv)
{
	t_info		*info;
	int i = 1;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (0);
	info->map1 = no_file_map_error(info, argc, argv, 0);
	info->player.player_x = 18.0;
	info->player.player_y = 18.0;
	info->player.player_a = 0.0;
	info->ray.steps = 20;
	info->in[0] = 0;
	info->size[0].x = 512;
	info->size[0].y = 512;
	while (i < 6)
	{
		info->in[i] = 0;
		info->size[i].x = 64;
		info->size[i].y = 64;
		i++;
	}
	info->drow.speed = 0.5;
	info->head = NULL;
	info->indice = 0;
	info->player.len_map_x = 20;
	info->player.len_map_y = 20;
	info->cnt = 0;
	info->argv = argv;
	info->argc = argc;
	info->ray.fov = M_PI / 6;
	info->mlx_f.mlx_ptr = mlx_init();
	// info->mlx_f.win_ptr = mlx_new_window(info->mlx_f.mlx_ptr,
	// w_win, h_win, "wolf3d");
	load_image(info);
	/*-----------------------------------------------------------------------------*/
	info->mlx_f1.win_ptr = mlx_new_window(info->mlx_f.mlx_ptr,
	w_menue, h_menue, "Menue");
	info->mlx_f1.img_ptr = mlx_new_image(info->mlx_f.mlx_ptr, w_menue, h_menue);
	info->mlx_f1.map = (int *)mlx_get_data_addr(info->mlx_f1.img_ptr,
	&info->mlx_f1.bits_per_pixel, &info->mlx_f1.size_line, &info->mlx_f1.endian);
	// printf("|%p|--|%p|\n", mlx_f1.img_ptr, info->mlx_f.win_ptr, mlx_);
	put_image_to_menue(info, 6);
	mlx_put_image_to_window(info->mlx_f.mlx_ptr, info->mlx_f1.win_ptr,
    info->mlx_f1.img_ptr, 0, 0);
	mlx_events_menue(info);
	/*----------------------------------------------------------------------------*/
	info->size[2].x = 128;
	info->size[2].y = 128;
	info->size[6].x = 220;
	info->size[6].y = 300;
	// mlx_events(info);
	// new_img(info);
	// ray_casting(info);
	// mlx_loop_hook(info->mlx_f.mlx_ptr, ray_casting, info);
	mlx_loop(info->mlx_f.mlx_ptr);
}

void		load_image(t_info *info)
{
	info->img[0] = ft_mlx_load_image(info->mlx_f.mlx_ptr,
	"./texture/sky.xpm", info->size[0]);
	info->img[1] = ft_mlx_load_image(info->mlx_f.mlx_ptr,
	"./texture/mossy.xpm", info->size[1]);
	info->img[2] = ft_mlx_load_image(info->mlx_f.mlx_ptr,
	"./texture/sand.xpm", info->size[2]);
	info->img[3] = ft_mlx_load_image(info->mlx_f.mlx_ptr,
	"./texture/test1.xpm", info->size[3]);
	info->img[4] = ft_mlx_load_image(info->mlx_f.mlx_ptr,
	"./texture/tile41.xpm", info->size[4]);
	info->img[5] = ft_mlx_load_image(info->mlx_f.mlx_ptr,
	"./texture/wood.xpm", info->size[5]);
	info->img[6] = ft_mlx_load_image(info->mlx_f.mlx_ptr,
	"./texture/recardo/frame_00_delay-0.1s.XPM", info->size[6]);
}