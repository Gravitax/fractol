/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:06:36 by maboye            #+#    #+#             */
/*   Updated: 2019/07/31 16:49:28 by maboye           ###   ########.fr       */
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

static int      is_correct_input(char *str)
{
    if (!ft_strcmp(str_tolower(str), "help"))
    {
        ft_printf(1, "List of available fractal:\nJulia\nMandelbrot\n");
        exit(EXIT_SUCCESS);
    }
    if (!ft_strcmp(str_tolower(str), "julia"))
        return (1);
    if (!ft_strcmp(str_tolower(str), "mandelbrot"))
        return (2);
    if (!ft_strcmp(str_tolower(str), "tamere"))
        return (3);
    return (0);
}

int             main(int ac, char **av)
{
    int     key;

    if (ac == 2 && (key = is_correct_input(av[1])))
    {
        fractol(key);
        return (my_putendl_fd("fractol: success", 1));
    }
    else
        return (my_putendl_fd("fractol: usage: ./fractol 'help'", 1));
}
