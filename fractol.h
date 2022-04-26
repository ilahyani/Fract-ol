/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:34:48 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/24 18:50:26 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include <stdio.h>

typedef struct	s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_vector
{
	int	x;
	int	y;
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

void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	manderlbrot(t_image *img);

# endif