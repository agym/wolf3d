/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:00:00 by agym              #+#    #+#             */
/*   Updated: 2019/08/02 13:06:00 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	free_node(t_info *info)
{
	t_point2d *tmp;

	tmp = info->head;
    while (info->head)
    {
        tmp = info->head;
        info->head = info->head->next;
        free (tmp);
    }
}

int		ft_close_eve(void *param)
{
	t_info *info;

	info = (t_info *)param;
	free_node(info);
	mlx_destroy_image(info->mlx_f.mlx_ptr, info->mlx_f1.img_ptr);
	mlx_destroy_window(info->mlx_f.mlx_ptr, info->mlx_f1.win_ptr);
	free(info);
	exit(0);
}

void            clean_image(t_info *info)
{
	int i;

	i = 0;
	while (i++ < w_menue * h_menue)
		info->mlx_f1.map[i] = 0;
}

void			put_image_to_menue(t_info *info, int nb_texture)
{
	int k;
	int x;
	int j;
	int y;
	int cnt;

	x = 0;
	k = 0;
	cnt = 0;
	while (x < 64 * nb_texture)
	{
		if (cnt == 64)
		{
			cnt = 0;
			k++;
		}
		y = 0;
		while (y < 64)
		{
			if (j == 64)
				j = 0;
			info->mlx_f1.map[w_menue * x + y] =
			info->img[k].data[info->size[k].x * j + y];
			y++;
		}
		cnt++;
		j++;
		x++;
	}
}

t_point2d            *link_list(t_point2d *tmp, t_point2d *tmp1)
{
	t_point2d *tmp2;

	tmp2 = tmp;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp1;
	return (tmp);
}

t_point2d       *list_point(t_point2d *head, int x, int y)
{
	t_point2d *tmp;

	if (!(tmp = (t_point2d *)malloc(sizeof(t_point2d))))
		return (NULL);
	tmp->x = x;
	tmp->y = y;
	tmp->next = NULL;
	if (head == NULL)
		return (tmp);
	return (link_list(head, tmp));
}

/* calcule du ma et min des coordoner poure les entourer avec un careaux des coordoner*/

void				max_coordoner(t_info *info)
{
	t_point2d *tmp;

	tmp = info->head;
	while (tmp && tmp->next)
	{
		info->max_min.x = (tmp->x > tmp->next->x) ? tmp->x : tmp->next->x;
		tmp = tmp->next;
	}
}

void				min_coordoner(t_info *info)
{
	t_point2d *tmp;

	tmp = info->head;
	while (tmp && tmp->next)
	{
		info->max_min.y = (tmp->y < tmp->next->y) ? tmp->y : tmp->next->y;
		tmp = tmp->next;
	}
}

// void			generate_map(t_info *info)
// {

// }

int             key_press_menue_mose(int key, int x, int y, t_info *info)
{
	t_point2d *tmp;
	int i;
	int j;

	i = -5;
	if (key == 1 && info->indice == 0)
	{
		if (x > 64)
		{
			info->head = list_point(info->head, x, y);
			while (i < 5)
			{
				j = -5;
				while (j++ < 5)
					info->mlx_f1.map[w_menue * (y + i) + (x + j)] = 0xfffffff;
				i++;
			}
			
			mlx_put_image_to_window(info->mlx_f.mlx_ptr, info->mlx_f1.win_ptr
			, info->mlx_f1.img_ptr, 0, 0);
		}
	}
	if (key == 1 && info->indice == 1)
	{
		tmp = info->head;
		while (tmp)
		{
			if ((tmp->x >= x - 5 && tmp->x <= x + 5) &&
			(tmp->y >= y - 5 && tmp->y <= y + 5))
			{
				if (info->cnt == 1)
				{
					info->p[1].x = x;
					info->p[1].y = y;
					main_bresenham(info, info->p[0], info->p[1]);
					mlx_put_image_to_window(info->mlx_f.mlx_ptr, info->mlx_f1.win_ptr,
					info->mlx_f1.img_ptr, 0, 0);
					info->cnt = 0;
				}
				else
				{
					info->p[0].x = x;
					info->p[0].y = y;
					info->cnt++;
				}
				break ;
			}
			tmp = tmp->next;
		}
	}
	return (0);
}

int				key_press_menue_key(int key, t_info *info)
{
	if (key == 53)
		ft_close_eve(info);
	if (key == 49)
	{
		// t_point2d *tmp;

		info->indice = 1;
	}	
	return (0);
}

void            mlx_events_menue(t_info *info)
{
	mlx_hook(info->mlx_f1.win_ptr, 2, 17, key_press_menue_key, info);
	mlx_hook(info->mlx_f1.win_ptr, 4, 17, key_press_menue_mose, info);
	mlx_hook(info->mlx_f1.win_ptr, 17, 0, ft_close_eve, info);
}