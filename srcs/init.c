/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:55:16 by maboye            #+#    #+#             */
/*   Updated: 2019/08/05 19:43:19 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		burningship_init(t_fractol *data)
{
	data->max_i = 50;
	data->x1 = -2.2;
	data->y1 = -2.5;
	data->color = 265;
}

static void		julia_init(t_fractol *data)
{
	data->julia = 1;
	data->max_i = 50;
	data->x1 = -2.0;
	data->y1 = -2.0;
	data->color = 265;
	data->c_r = 0.285;
	data->c_i = 0.01;
}

static void		mandelbrot_init(t_fractol *data)
{
	data->max_i = 50;
	data->x1 = -2.5;
	data->y1 = -1.3;
	data->color = 265;
}

void			init(t_fractol *data)
{
	if (data->fractal == 1)
		julia_init(data);
	else if (data->fractal == 2)
		mandelbrot_init(data);
	else if (data->fractal == 3)
		burningship_init(data);
	else
		;
	data->zoom = WIDTH / (ft_absolute(data->x1) + ft_absolute(data->y1));
}
