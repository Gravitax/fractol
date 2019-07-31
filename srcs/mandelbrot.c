/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:45:10 by maboye            #+#    #+#             */
/*   Updated: 2019/07/31 16:48:00 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void            mandelbrot(t_fractol *data)
{
    double  zoomx;
    double  zoomy;
    int     max_i;

    data->x1 = -2.1;
    data->x2 = 0.6;
    data->y1 = -1.2;
    data->y2 = 1.2;
    max_i = 50;

    zoomx = WIN_L / (data->x2 - data->x1);
    zoomy = WIN_H / (data->y2 - data->y1);
    int     x = -1;
    int     y;
    double  tmp;
    while (++x < WIN_L)
    {
        y = -1;
        while (++y < WIN_H)
        {
            double  c_r = x / zoomx + data->x1;
            double  c_i = y / zoomy + data->y1;
            double  z_r = 0;
            double  z_i = 0;
            int i = 0;

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
