/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:45:10 by maboye            #+#    #+#             */
/*   Updated: 2019/08/01 16:57:51 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void     mandelbrot_maker(t_fractol *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->i = 0;
	while (data->i < data->max_i
        && data->z_r * data->z_r + data->z_i * data->z_i < 4)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r
            - data->z_i * data->z_i + data->c_r;
		data->z_i = 2 * data->z_i * data->tmp + data->c_i;
		++data->i;
	}
	if (data->i == data->max_i)
		ft_putpixel(data, data->x, data->y, 0x000000);
	else
		ft_putpixel(data, data->x, data->y, (data->color * data->i));
}

void            mandelbrot(t_fractol *data)
{
	data->x = 0;
	while (data->x < WIN_L)
	{
		data->y = 0;
		while (data->y < WIN_H)
		{
			mandelbrot_maker(data);
			data->y++;
		}
		data->x++;
	}
}
