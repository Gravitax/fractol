/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:04:56 by maboye            #+#    #+#             */
/*   Updated: 2019/08/05 18:44:09 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// if (a == e->i_max)
// 	return (e->color_max);
// r = (a * 5) * e->color_value;
// g = (255 - (a * 10)) * e->color_value;
// b = (255 - (a * 2)) * e->color_value;
// c = (r << 16) + (g << 8) + b;

static void		ft_color(t_fractol *data, int key)
{
	if (key == R || key == G)
		data->color = (key == R ? 0xFF0000 : 0x00FF00);
	if (key == B)
		data->color = 0x0000FF;
	if (key == UP || key == DOWN)
		data->color += (key == UP ? 10 : -10);
	if (data->color < 0)
		data->color = 0xFFFFFF;
}

static void		ft_switch(t_fractol *data, int key, int choose)
{
	if (choose == 1)
	{
		if (key == PREV || key == LEFT)
			--data->fractal;
		else
			++data->fractal;
		if (data->fractal > 3 || data->fractal < 1)
			data->fractal = data->fractal > 3 ? 1 : 3;
		init(data);
	}
	else if (choose == 2)
	{
		if (key == W || key == S)
			data->y1 += (key == W ? 0.1 : -0.1);
		else
			data->x1 += (key == A ? 0.1 : -0.1);
	}
	else
	{
		data->max_i += (key == MORE ? 25 : -25);
		if (data->max_i < 25 || data->max_i > 200)
			data->max_i = data->max_i < 25 ? 25 : 200;
	}
}

static void		ft_zoom(int button, int x, int y, t_fractol *data)
{
	double	zoom;

	zoom = (button == ZDOWN ? 1.5 : 0.66);
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * zoom));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * zoom));
	data->zoom *= zoom;
	data->max_i += (button == ZDOWN ? 1 : -1);
}

int				mouse_event(int button, int x, int y, void *param)
{
	t_fractol	*data;

	data = (t_fractol *)param;
	if (button == ZDOWN || button == ZUP)
		ft_zoom(button, x, y, data);
	if (button == PREV || button == NEXT)
		ft_switch(data, button, 1);
	ft_maker(data, 1);
	ft_printf(1, "button: %d\n x: %d, y: %d\n", button, x, y);
	return (1);
}

int				key_event(int key, void *param)
{
	t_fractol	*data;

	data = (t_fractol *)param;
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		ft_freestruct(&data);
		exit(EXIT_SUCCESS);
	}
	if (key == MORE || key == LESS)
		ft_switch(data, key, 0);
	if (key == LEFT || key == RIGHT)
		ft_switch(data, key, 1);
	if (key == W || key == A || key == S || key == D)
		ft_switch(data, key, 2);
	if (key == DOWN || key == UP || key == R || key == G || key == B)
		ft_color(data, key);
	if (key == SPC)
		data->julia = -data->julia;
	if (key == CLEAR)
		init(data);
	ft_maker(data, 1);
	ft_printf(1, "key: %d\n", key);
	return (1);
}
