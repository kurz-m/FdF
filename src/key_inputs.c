/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:07:28 by makurz            #+#    #+#             */
/*   Updated: 2023/05/18 18:42:14 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(int key, t_fdf *fdf)
{
	if (key == MLX_KEY_UP)
		fdf->project.y_offset -= 10;
	if (key == MLX_KEY_DOWN)
		fdf->project.y_offset += 10;
	if (key == MLX_KEY_LEFT)
		fdf->project.x_offset -= 10;
	if (key == MLX_KEY_RIGHT)
		fdf->project.x_offset += 10;
	draw_main(fdf->map, fdf);
}

void	key_inputs(void *tmp)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) tmp;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		; ;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		move(MLX_KEY_UP, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		move(MLX_KEY_DOWN, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		move(MLX_KEY_LEFT, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		move(MLX_KEY_RIGHT, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
		; ;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_O))
		; ;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		; ;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		; ;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		; ;

}
