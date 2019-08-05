/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:54:01 by maboye            #+#    #+#             */
/*   Updated: 2019/08/05 17:11:36 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		burningship_maker(t_fractol *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->i = 0;
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4
			&& data->i < data->max_i)
	{
		data->tmp = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i = fabs(2 * data->z_r * data->z_i) + data->c_i;
		data->z_r = data->tmp;
		++data->i;
	}
	ft_putpixel(data, data->x, data->y,
		(data->i == data->max_i ? 0x000000 : data->color * data->i));
}

static void		*burningship(void *tab)
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
			burningship_maker(data);
			++data->y;
		}
		++data->x;
	}
	return (tab);
}

void			burningship_pthread(t_fractol *data)
{
	t_fractol	tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void *)&tab[i], (void *)data, sizeof(t_fractol));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, burningship, &tab[i]);
		++i;
	}
	while (i--)
		pthread_join(t[i], NULL);
}
