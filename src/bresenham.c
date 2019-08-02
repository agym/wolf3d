/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:41:48 by agym              #+#    #+#             */
/*   Updated: 2019/08/01 18:55:20 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void            line(t_info *info, t_bre_h_l   ln)
{
    if (ln.x < w_menue && ln.x > 0 && ln.y > 0 && ln.y < h_menue)
    info->mlx_f1.map[w_menue * ln.y + ln.x] = 0xffffff;
}

void            bresenham_low(t_point2d point0, t_point2d point1,
         t_info *info)
{
     t_bre_h_l   ln;

     ln.dx = point1.x - point0.x;
     ln.dy = point1.y - point0.y;
     ln.yi = 1;
     if (ln.dy < 0)
     {
         ln.yi = -1;
         ln.dy = -ln.dy;
     }
     ln.p = 2 * ln.dy - ln.dx;
     ln.y = point0.y;
     ln.x = point0.x;
     while (ln.x++ < point1.x)
     {
         line(info, ln);
         if (ln.p > 0)
         {
             ln.y = ln.y + ln.yi;
             ln.p = ln.p - 2 * ln.dx;
         }
         ln.p = ln.p + 2 * ln.dy;
     }
 }

 void            bresenham_high(t_point2d point0, t_point2d point1,
         t_info *info)
 {
     t_bre_h_l   ln;

     ln.dx = point1.x - point0.x;
     ln.dy = point1.y - point0.y;
     ln.xi = 1;
     if (ln.dx < 0)
     {
         ln.xi = -1;
         ln.dx = -ln.dx;
     }
     ln.p = 2 * ln.dx - ln.dy;
     ln.x = point0.x;
     ln.y = point0.y;
     while (ln.y++ < point1.y)
     {
         line(info, ln);
         if (ln.p > 0)
         {
             ln.x = ln.x + ln.xi;
             ln.p = ln.p - 2 * ln.dy;
         }
         ln.p = ln.p + 2 * ln.dx;
     }
 }

void            main_bresenham(t_info *info, t_point2d p1, t_point2d p2)
{
    if (abs(p2.y - p1.y) < abs(p2.x - p1.x))
    {
        if (p1.x > p2.x)
            bresenham_low(p2, p1, info);
        else
            bresenham_low(p1, p2, info);
    }
    else
    {
        if (p1.y > p2.y)
            bresenham_high(p2, p1, info);
        else
            bresenham_high(p1, p2, info);
    }
}