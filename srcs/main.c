/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:06:36 by maboye            #+#    #+#             */
/*   Updated: 2019/08/05 19:19:31 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// bonus: 5 pts sur les fractales
// bonus: fork plusieurs fractales.

static int		is_correct_input(char *str)
{
	if (!ft_strcmp(str_tolower(str), "help"))
	{
		ft_putendl("List of available fractal:");
		ft_putendl("- Burningship");
		ft_putendl("- Julia");
		ft_putendl("- Mandelbrot");
		exit(EXIT_SUCCESS);
	}
	if (!ft_strcmp(str_tolower(str), "julia"))
		return (1);
	if (!ft_strcmp(str_tolower(str), "mandelbrot"))
		return (2);
	if (!ft_strcmp(str_tolower(str), "burningship"))
		return (3);
	return (0);
}

int				main(int ac, char **av)
{
	int		key;

	if (WIDTH < 600 || WIDTH > 1300)
		return (my_printf(1, "WIDTH %s\n", WIDTH < 600 ? "< 600" : "> 1300"));
	if (THREAD_WIDTH > 8)
		return (my_putendl_fd("fractol: error: THREAD_WIDTH > 8", 1));
	if (ac == 2 && (key = is_correct_input(av[1])))
	{
		fractol(key);
		return (0);
	}
	else
		return (my_putendl_fd("fractol: usage: ./fractol help", 1));
}
