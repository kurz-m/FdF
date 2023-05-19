/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:07:28 by makurz            #+#    #+#             */
/*   Updated: 2023/05/19 13:37:14 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	move_inputs(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		move(MLX_KEY_UP, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		move(MLX_KEY_DOWN, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		move(MLX_KEY_LEFT, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		move(MLX_KEY_RIGHT, fdf);
}

static void	zoom_inputs(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
		zoom(MLX_KEY_I, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_O))
		zoom(MLX_KEY_O, fdf);
}

static void	rotate_inputs(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, 340) && mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		anti_rotate(MLX_KEY_A, fdf);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		rotate(MLX_KEY_A, fdf);
	if (mlx_is_key_down(fdf->mlx, 340) && mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		anti_rotate(MLX_KEY_S, fdf);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		rotate(MLX_KEY_S, fdf);
	if (mlx_is_key_down(fdf->mlx, 340) && mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		anti_rotate(MLX_KEY_D, fdf);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		rotate(MLX_KEY_D, fdf);
}

void	key_inputs(void *tmp)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) tmp;
	move_inputs(fdf);
	zoom_inputs(fdf);
	rotate_inputs(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		; ;
}
