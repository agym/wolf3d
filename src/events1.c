/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:28:55 by agym              #+#    #+#             */
/*   Updated: 2019/07/31 13:24:47 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

t_img			ft_mlx_load_image(void *mlx_ptr, char *filename, t_point size)
{
	t_img		img;

	img.img_ptr = mlx_xpm_file_to_image(mlx_ptr, filename, &size.x, &size.y);
	if (!img.img_ptr)
	{
		ft_putendl("File !!");
		ft_putendl(filename);
		ft_error();
	}
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_len,
	&img.endian);
	return (img);
}

void		initial_tex(t_info *info)
{
	int i;

	i = 0;
	while (i < 7)
		info->in[i++] = 0;
}

void		textur(t_info *info, int k, int i, int xx)
{
	if (info->in[k] == info->size[k].x)
		info->in[k] = 0;
	info->mlx_f.map[w_win * i + xx] =
	info->img[k].data[info->size[k].x * info->in[k] + (xx  % info->size[k].y)];
	info->in[k]++;
}

void		img(t_info *info, int xx, int x, int y)
{
	int		i;

	i = 0;
	while (i <= x)
	{
		textur(info, 0, i, xx);
		// info->mlx_f.map[w_win * i + xx] = 0xa2a8bb;
		i++;
	}
	while (i < y)
	{
		if (info->map1[info->ray.test_x][info->ray.test_y] == 1)
			textur(info, 1, i, xx);
		if (info->map1[info->ray.test_x][info->ray.test_y] == 2)
			textur(info, 3, i, xx);
		if (info->map1[info->ray.test_x][info->ray.test_y] == 3)
			textur(info, 4, i, xx);
		if (info->map1[info->ray.test_x][info->ray.test_y] == 5)
			textur(info, 5, i, xx);
		// if (info->map1[info->pl_p.xold / 64][info->pl_p.yold / 64] == 5)
		// 	textur(info, 0, i, xx);
		i++;
	}
	while (i < h_win)
	{
		textur(info, 2, i, xx);
		i++;
	}
	initial_tex(info);
}
