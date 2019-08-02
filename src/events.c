/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:00:54 by agym              #+#    #+#             */
/*   Updated: 2019/08/01 22:34:59 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

int		ft_close(void *param)
{
	t_info *info;

	info = (t_info *)param;
	mlx_destroy_image(info->mlx_f.mlx_ptr, info->mlx_f.img_ptr);
	mlx_destroy_window(info->mlx_f.mlx_ptr, info->mlx_f.win_ptr);
	free_tab1(info->map1, info->argv);
	free(info);
	exit(0);
}

int				key_press(int key, t_info *info)
{
	if (key == 53)
		ft_close(info);
	if (key == 123)
		info->player.player_a -= deg2rad(1);
	if (key == 124)
		info->player.player_a += deg2rad(1);
	if (key == 126)
	{
		t_vec2	dp = {sin(info->player.player_a) * info->drow.speed,  cos(info->player.player_a) * info->drow.speed};
		t_point2d1	pos = { info->player.player_x + dp.x, info->player.player_y + dp.y};
		// printf("Next  Position : x = %d\t y = %d\n", pos.x, pos.y);
		if (pos.x >= 0 && pos.x <= info->player.len_map_x && pos.y >= 0 && pos.y <= info->player.len_map_y 
				&& info->map1[pos.x][pos.y] == 0)
		{
			info->player.player_x += dp.x;
			info->player.player_y += dp.y;
		}
		// else
		// {
		// 	puts("Could not move Because : ");
		// 	if (pos.x < 0 || pos.x > info->player.len_map_x || pos.y < 0 || pos.y > info->player.len_map_y)
		// 		puts("Dimensions");
		// 	else
		// 		puts("a wall");
		// }
		// ray_casting(info);
	}
	if (key == 125)
	{
		t_vec2	dp = {sin(info->player.player_a) * info->drow.speed,  cos(info->player.player_a) * info->drow.speed};
		t_point2d1	pos = { info->player.player_x - dp.x, info->player.player_y - dp.y};
		if (pos.x >= 0 && pos.x <= info->player.len_map_x && pos.y >= 0 && pos.y <= info->player.len_map_y
		&& info->map1[pos.x][pos.y] == 0)
		{
			info->player.player_x -= dp.x;
			info->player.player_y -= dp.y;
		}
		// else
		// {
		// 	puts("Could not move Because : ");
		// 	if (pos.x < 0 || pos.x > info->player.len_map_x || pos.y < 0 || pos.y > info->player.len_map_y)
		// 		puts("Dimensions");
		// 	else
		// 		puts("a wall");
		// }
		// printf(" Next Position : x = %d\t y = %d\n", pos.x, pos.y);
		// ray_casting(info);
	}
	return (0);
}

void			mlx_events(t_info *info)
{
	mlx_hook(info->mlx_f.win_ptr, 2, 17, key_press, info);
	mlx_hook(info->mlx_f.win_ptr, 17, 0, ft_close, info);
}

void			free_tab1(int **lines, char **argv)
{
	int			i;

	i = 0;
	while (i < nb_of_lines(argv))
		free(lines[i++]);
	free(lines);
}
