/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:33:28 by makurz            #+#    #+#             */
/*   Updated: 2023/05/20 20:04:16 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(int key, t_fdf *fdf)
{
	if (key == MLX_KEY_UP)
		fdf->project.y_offset += 10;
	if (key == MLX_KEY_DOWN)
		fdf->project.y_offset -= 10;
	if (key == MLX_KEY_LEFT)
		fdf->project.x_offset += 10;
	if (key == MLX_KEY_RIGHT)
		fdf->project.x_offset -= 10;
	draw_main(fdf->map, fdf);
}

void	zoom(int key, t_fdf *fdf)
{
	if (key == MLX_KEY_I)
		fdf->project.zoom += 1;
	if (key == MLX_KEY_O && fdf->project.zoom > 1)
		fdf->project.zoom -= 1;
	draw_main(fdf->map, fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == MLX_KEY_A)
		fdf->project.alpha += 0.5;
	if (key == MLX_KEY_S)
		fdf->project.beta += 0.5;
	if (key == MLX_KEY_D)
		fdf->project.gamma += 0.5;
	draw_main(fdf->map, fdf);
}

void	anti_rotate(int key, t_fdf *fdf)
{
	if (key == MLX_KEY_A)
		fdf->project.alpha -= 1;
	if (key == MLX_KEY_S)
		fdf->project.beta -= 1;
	if (key == MLX_KEY_D)
		fdf->project.gamma -= 1;
	draw_main(fdf->map, fdf);
}
