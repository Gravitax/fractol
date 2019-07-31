/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 13:15:07 by maboye            #+#    #+#             */
/*   Updated: 2019/07/31 15:26:06 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void            ft_freestruct(t_fractol **data)
{
    if (data && *data)
    {
        // if ((*data)->img)
        // {
        //     if ((*data)->img->add)
		// 		ft_memdel((void *)&(*data)->img->add);
		// 	free((void *)(*data)->img);
		// 	(*data)->img = NULL;
        // }
        free((void *)*data);
		*data = NULL;
    }
}

void            ft_error(t_fractol *data, char *str, int fd)
{
    if (data)
        ft_freestruct(&data);
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
