/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 13:15:07 by maboye            #+#    #+#             */
/*   Updated: 2019/07/31 17:19:44 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		    ft_putpixel(t_fractol *data, int x, int y, int color)
{
	long	pos;

	if (x < 0 || y < 0 || x > WIN_L - 1 || y > WIN_H)
		return ;
	pos = x + y * WIN_L;
	data->img->add[pos] = color;
}

void            ft_freestruct(t_fractol **data)
{
    if (data && *data)
    {
        if ((*data)->img)
        {
            if ((*data)->img->add)
				ft_memdel((void *)&(*data)->img->add);
			free((void *)(*data)->img);
			(*data)->img = NULL;
        }
        free((void *)*data);
		*data = NULL;
    }
}

void            ft_error(t_fractol *data, char *str, int fd)
{
    if (data)
    {
        if (data->mlx_ptr)
            mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        ft_freestruct(&data);
    }
    ft_putendl_fd(str, fd);
    exit(EXIT_SUCCESS);
}

char            *str_tolower(char *str)
{
    int i;

    i = -1;
    while (str && str[++i])
        str[i] = ft_tolower(str[i]);
    return (str);
}
