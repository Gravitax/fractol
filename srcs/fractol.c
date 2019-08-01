/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:59:23 by maboye            #+#    #+#             */
/*   Updated: 2019/08/01 18:56:39 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_img    *ft_new_image(t_fractol *data)
{
	t_img	*img;

	if (!(img = (t_img *)ft_memalloc(sizeof(t_img))))
		return (NULL);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_L, WIN_H);
	img->add = (int *)mlx_get_data_addr(data->img_ptr,
		&(img->bpp), &(img->size_line), &(img->endian));
	return (img);
}

static void     keyboard_menu(t_fractol *d)
{
    mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 320, 0xFFFFFF, "KEYBOARD");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 350, 0xFFFFFF,
        "switch    : [<-], [->]");
    mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 370, 0xFFFFFF,
        "color     : [up], [down]");
    mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 390, 0xFFFFFF,
        "iteration : [+] , [-]");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 430, 0xFFFFFF,
        "ESC       : quit");
}

static void     ft_menu(t_fractol *d)
{
    char    *buf;

    buf = NULL;
    mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 10, 0xFFFFFF, "FRACTOL");
    mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 30, 0xFFFFFF, "maboye");
    mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 120, 0xFFFFFF,
        "Current fractal:");
    if (d->fractal == 1)
        buf = ft_strdup("Julia");
    else if (d->fractal == 2)
        buf = ft_strdup("Mandelbrot");
    else if (d->fractal == 3)
        buf = ft_strdup("Burningship");
    else
        buf = ft_strdup("Suce");
    mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 140, 0xFFFFFF, buf);
    keyboard_menu(d);
    mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 200, 0xFFFFFF, "MOUSE");
    mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 230, 0xFFFFFF,
        "scroll up   : zoom");
    mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 250, 0xFFFFFF,
        "scroll down : dezoom");
    ft_strdel(&buf);
}

void            ft_maker(t_fractol *data, int choose)
{
    if (!choose)
        init(data);
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    if (data->fractal == 1)
        julia(data);
    else if (data->fractal == 2)
        mandelbrot(data);
    else if (data->fractal == 3)
        burningship(data);
    else
        ;
    ft_menu(data);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

void            fractol(int key)
{
    t_fractol   *data;

    if (!(data = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
        return (ft_putendl_fd("fractol: error", 2));
    if (!(data->mlx_ptr = mlx_init()))
        return (ft_error(data, "fractol: mlx error", 2));
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr,
    WIN_M, WIN_H, "maboye fractol")))
        return (ft_error(data, "fractol: mlx error", 2));
	if (!(data->img = ft_new_image(data)))
        return (ft_error(data, "fractol: mlx error", 2));
    data->fractal = key;
    ft_maker(data, 0);
	mlx_hook(data->win_ptr, 2, 0, key_event, data);
    mlx_hook(data->win_ptr, 4, 0, mouse_event, data);
    mlx_loop(data->mlx_ptr);
}
