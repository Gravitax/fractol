/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:49:17 by maboye            #+#    #+#             */
/*   Updated: 2019/07/31 16:44:30 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "../libft/libft.h"

# define WIN_L  800
# define WIN_H  600
# define WIN_M  WIN_L + 300

# define ESC    53

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_point;

typedef struct	s_img
{
	int			*add;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct  s_fractol
{
    double      x1;
    double      y1;
    double      x2;
    double      y2;
    double      dx;
    double      dy;
    void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
    t_img       *img;
    t_point     **map;
}               t_fractol;

void            julia(t_fractol *data);
void            mandelbrot(t_fractol *data);

int				deal_key(int key, void *param);
void            fractol(int key);
char            *str_tolower(char *str);

void            ft_error(t_fractol *data, char *str, int fd);
void            ft_freestruct(t_fractol **data);
void		    ft_putpixel(t_fractol *data, int x, int y, int color);

#endif
