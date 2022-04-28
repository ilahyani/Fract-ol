/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:47:36 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/28 19:02:32 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_image
{
	void		*ptr;
	t_vector	size;
	char		*pxls;
	int			bpp;
	int			l_size;
	int			endian;
}	t_image;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct vars
{
	double		min_r;
	double		min_i;
	double		max_r;
	double		max_i;
	void		*mlx_ptr;
	void		*window;
	int			itr;
	t_vector	pnt;
	t_image		img;
	t_complex	c;
}	t_vars;

void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
int		multibrot(t_vars *vars);
void	draw_multibrot(t_vars *vars);
int		mouse_mvmnt(int x, int y, t_vars *vars);
int		ft_zoom(int x, int y, int keycode, t_vars *vars);
int		mouse_hook(int keycode, int x, int y, t_vars *vars);
int		close_window(void *param);
int		escape(int keycode, void *param);
int		trgb(int t, int r, int g, int b);
void	ft_init(t_vars *vars);
void	error_message(int i);

#endif