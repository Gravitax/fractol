/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:49:17 by maboye            #+#    #+#             */
/*   Updated: 2019/08/01 19:31:18 by maboye           ###   ########.fr       */
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

# define PREV	1
# define NEXT	2
# define ZDOWN	4
# define ZUP	5

# define R		15
# define G		5
# define B		11

# define W		13
# define A		0
# define S		1
# define D		2
# define MORE	69
# define LESS	78
# define LEFT	123
# define RIGHT	124
# define DOWN	125
# define UP		126

# define ESC    53
# define CLEAR	71

typedef struct	s_img
{
	int			*add;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct  s_fractol
{
	int			max_i;
	int			i;
	int			color;
	int			fractal;
	double		tmp;
	double		x;
	double		y;
    double      x1;
    double      y1;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		zoom;
    void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
    t_img       *img;
}               t_fractol;

void	        init(t_fractol *data);
void			burningship(t_fractol *data);
void            julia(t_fractol *data);
void            mandelbrot(t_fractol *data);

int				key_event(int key, void *param);
int				mouse_event(int button, int x, int y, void *param);
void            fractol(int key);
char            *str_tolower(char *str);

void            ft_error(t_fractol *data, char *str, int fd);
void            ft_freestruct(t_fractol **data);
void	        ft_maker(t_fractol *data, int choose);
void		    ft_putpixel(t_fractol *data, int x, int y, int color);

#endif
