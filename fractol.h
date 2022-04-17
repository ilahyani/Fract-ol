/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:34:48 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/17 15:05:19 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include <stdio.h>
#include <complex.h>

typedef struct s_color {
	int	r;
	int g;
	int b;
	int a;
}	t_color;

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

# endif