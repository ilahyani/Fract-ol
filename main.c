/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:53:51 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/16 18:15:58 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	void	*mlx_pointer;
	void	*window;
	int		i;
	
	mlx_pointer = mlx_init();
	window = mlx_new_window(mlx_pointer, 500, 500, "what do you call a black widow? a window!");
	for (i = 0; i < 500; i++)
	 	mlx_pixel_put(mlx_pointer, window, i, i, 0x0000FF);
	mlx_loop(mlx_pointer);
}