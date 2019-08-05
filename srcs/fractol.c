/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:59:23 by maboye            #+#    #+#             */
/*   Updated: 2019/08/05 16:07:55 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_img	*ft_new_image(t_fractol *data)
{
	t_img	*img;

	if (!(img = (t_img *)ft_memalloc(sizeof(t_img))))
		return (NULL);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, WIDTH);
	img->add = (int *)mlx_get_data_addr(data->img_ptr,
			&(img->bpp), &(img->size_line), &(img->endian));
	return (img);
}

void			fractol(int key)
{
	t_fractol	*data;

	if (!(data = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		return (ft_putendl_fd("fractol: error", 2));
	if (!(data->mlx_ptr = mlx_init()))
		return (ft_error(data, "fractol: mlx error", 2));
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr,
					WIN_M, WIDTH, "maboye fractol")))
		return (ft_error(data, "fractol: mlx error", 2));
	if (!(data->img = ft_new_image(data)))
		return (ft_error(data, "fractol: mlx error", 2));
	data->fractal = key;
	ft_maker(data, 0);
	mlx_hook(data->win_ptr, 2, 0, key_event, data);
	mlx_hook(data->win_ptr, 4, 0, mouse_event, data);
	mlx_hook(data->win_ptr, 6, 0, julia_event, data);
	mlx_loop(data->mlx_ptr);
}
