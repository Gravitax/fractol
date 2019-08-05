/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:15:12 by maboye            #+#    #+#             */
/*   Updated: 2019/08/05 18:35:20 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				julia_event(int x, int y, void *param)
{
	t_fractol	*data;

	data = (t_fractol *)param;
	if (data->fractal == 1 && data->julia == 1)
	{
		data->c_r = x;
		data->c_i = y;
		ft_maker(data, 1);
	}
	return (1);
}

static void		julia_maker(t_fractol *data)
{
	data->z_r = data->x / data->zoom + data->x1;
	data->z_i = data->y / data->zoom + data->y1;
	data->i = 0;
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4
			&& data->i < data->max_i)
	{
		data->tmp = data->z_r * data->z_r - data->z_i * data->z_i - 0.8
			+ data->c_r / WIDTH;
		data->z_i = data->z_r * data->z_i + data->z_r * data->z_i
			+ data->c_i / WIDTH;
		data->z_r = data->tmp;
		++data->i;
	}
	ft_putpixel(data, data->x, data->y,
		(data->i == data->max_i ? 0x000000 : data->color * data->i));
}

static void		*julia(void *tab)
{
	t_fractol	*data;
	int			tmp;

	data = (t_fractol *)tab;
	tmp = data->y;
	data->x = 0;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			julia_maker(data);
			++data->y;
		}
		++data->x;
	}
	return (tab);
}

void			julia_pthread(t_fractol *data)
{
	t_fractol	tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = -1;
	while (++i < THREAD_NUMBER)
	{
		ft_memcpy((void *)&tab[i], (void *)data, sizeof(t_fractol));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, julia, &tab[i]);
	}
	while (i--)
		pthread_join(t[i], NULL);
}
