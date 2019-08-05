/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:36:27 by maboye            #+#    #+#             */
/*   Updated: 2019/08/05 19:25:46 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		mouse_menu(t_fractol *d)
{
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIDTH + 1, 200, 0xFFFFFF,
			"MOUSE");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIDTH + 1, 230, 0xFFFFFF,
			"zoom      : scroll up");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIDTH + 1, 250, 0xFFFFFF,
			"dezoom    : scroll down");
}

static void		keyboard_menu(t_fractol *d)
{
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIDTH + 1, 320, 0xFFFFFF,
			"KEYBOARD");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIDTH + 1, 350, 0xFFFFFF,
			"switch    : [<-], [->]");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIDTH + 1, 370, 0xFFFFFF,
			"color     : [up], [down]");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIDTH + 1, 390, 0xFFFFFF,
			"iteration : [+] , [-]");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIDTH + 1, 430, 0xFFFFFF,
			"quit      : ESC");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIDTH + 1, 450, 0xFFFFFF,
			"reset     : clear");
}

void			ft_menu(t_fractol *d)
{
	char	*buf;

	buf = NULL;
	mlx_clear_window(d->mlx_ptr, d->win_ptr);
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIDTH + 1, 10, 0xFFFFFF, "FRACTOL");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIDTH + 1, 30, 0xFFFFFF, "maboye");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIDTH + 1, 120, 0xFFFFFF,
			"Current fractal:");
	if (d->fractal == 1)
		buf = ft_strdup("Julia");
	else if (d->fractal == 2)
		buf = ft_strdup("Mandelbrot");
	else if (d->fractal == 3)
		buf = ft_strdup("Burningship");
	else
		buf = ft_strdup("error");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIDTH + 1, 140, 0xFFFFFF, buf);
	keyboard_menu(d);
	mouse_menu(d);
	ft_strdel(&buf);
}
