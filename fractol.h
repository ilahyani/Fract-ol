/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:34:48 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/27 10:28:55 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct	s_image
{
	void      *pointer;
	t_vector  size;
	char      *pixels;
	int       bits_per_pixel;
	int       line_size;
	int       endian;
}   t_image;

typedef struct vars
{
	double	min_re;
	double	min_im;
	double	max_re;
	double	max_im;
	int		itr;
	void	*mlx_pointer;
	void	*window;
	t_image img;
}	t_vars;


typedef struct	s_complex
{
	double	re;
	double	im;
}	t_complex;


void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
int		manderlbrot(t_vars *vars);
int		mouse_mvmnt(int x, int y, void *params);
int		ft_zoom(int	x, int y, int keycode, t_vars *vars);
int		mouse_hook(int keycode, int x, int y, t_vars *vars);
int 	close_window(void *param);
int 	escape(int keycode, void *param);

# endif