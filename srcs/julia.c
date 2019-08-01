/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:15:12 by maboye            #+#    #+#             */
/*   Updated: 2019/08/01 19:35:04 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// int		mouse_julia(int x, int y, t_fractol *data)
// {
// 	if (data->fract == 1 && data->julia_mouse == 1)
// 	{
// 		data->c_r = x * 2;
// 		data->c_i = y * 2 - 800;
// 		fract_calc(data);
// 	}
// 	return (0);
// }

static void     julia_maker(t_fractol *data)
{
	data->c_r = 0.285;
	data->c_i = 0.01;
	data->z_r = data->x / data->zoom + data->x1;
	data->z_i = data->y / data->zoom + data->y1;
	data->i = 0;
	while (data->z_r * data->z_r + data->z_i
			* data->z_i < 4 && data->i < data->max_i)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r -
			data->z_i * data->z_i + data->c_r;
		data->z_i = 2 * data->z_i * data->tmp + data->c_i;
		++data->i;
	}
	if (data->i == data->max_i)
		ft_putpixel(data, data->x, data->y, 0x008000);
	else
		ft_putpixel(data, data->x, data->y, (data->color * data->i));
}

void            julia(t_fractol *data)
{
	data->x = 0;
	while (data->x < WIN_L)
	{
		data->y = 0;
		while (data->y < WIN_H)
		{
			julia_maker(data);
			++data->y;
		}
		++data->x;
	}
}
