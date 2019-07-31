/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:59:23 by maboye            #+#    #+#             */
/*   Updated: 2019/07/31 16:55:32 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_img		*ft_new_image(t_fractol *data)
{
	t_img	*img;

	if (!(img = (t_img *)ft_memalloc(sizeof(t_img))))
		return (NULL);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_L, WIN_H);
	img->add = (int *)mlx_get_data_addr(data->img_ptr,
		&(img->bpp), &(img->size_line), &(img->endian));
	return (img);
}

void            ft_menu(t_fractol *d)
{
    mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 10, 0xFFFFFF, "FRACTOL");
    mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 30, 0xFFFFFF, "maboye");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 240, 0xFFFFFF, "+: Zoom");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 270, 0xFFFFFF, "-: Zoom");
	mlx_string_put(d->mlx_ptr, d->win_ptr, WIN_L + 1, 480, 0xFFFFFF, "esc");
}

void            ft_maker(t_fractol *data, int key)
{
    if (key == 1)
        julia(data);
    else
        mandelbrot(data);
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
    ft_maker(data, key);
    ft_menu(data);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_hook(data->win_ptr, 2, 0, deal_key, data);
    mlx_loop(data->mlx_ptr);
}
