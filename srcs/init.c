/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:55:16 by maboye            #+#    #+#             */
/*   Updated: 2019/08/01 19:37:28 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void     burningship_init(t_fractol *data)
{
	data->zoom = 200;
	data->max_i = 200;
	data->x1 = -2.2;
	data->y1 = -2.0;
	data->color = 0x0000FF + 1;
}

static void     julia_init(t_fractol *data)
{
    data->zoom = 200;
	data->max_i = 200;
	data->x1 = -2;
	data->y1 = -1.5;
	data->color = 0x0000FF + 2;
}

static void     mandelbrot_init(t_fractol *data)
{
	data->zoom = 200;
	data->max_i = 50;
	data->x1 = -2.1;
	data->y1 = -1.2;
	data->color = 0x0000FF + 3;
}

void            init(t_fractol *data)
{
    if (data->fractal == 1)
        julia_init(data);
    else if (data->fractal == 2)
        mandelbrot_init(data);
    else if (data->fractal == 3)
        burningship_init(data);
    else
        ;
}
