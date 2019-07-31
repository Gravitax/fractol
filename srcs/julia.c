/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:15:12 by maboye            #+#    #+#             */
/*   Updated: 2019/07/31 16:48:44 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void            julia(t_fractol *data)
{
    data->x1 = -1;
    data->x2 = 1;
    data->y1 = -1.2;
    data->y2 = 1.2;

    double  zoomx = WIN_L / (data->x2 - data->x1);
    double  zoomy = WIN_H / (data->y2 - data->y1);
    int     max_i = 150;
    int     x = -1;
    int     y;
    double  tmp;

    while (++x < WIN_L)
    {
        y = -1;
        while (++y < WIN_H)
        {
            double  c_r = 0.285;
            double  c_i = 0.01;
            double  z_r = x / zoomx + data->x1;
            double  z_i = y / zoomy + data->y1;
            int     i = 0;

            while (z_r * z_r + z_i * z_i < 4 && i < max_i)
            {
                tmp = z_r;
                z_r = z_r * z_r - z_i * z_i + c_r;
                z_i = 2 * z_i * tmp + c_i;
                ++i;
            }
            if (i == max_i)
                ft_putpixel(data, x, y, 0xFFFFFF);
        }
    }
}
