/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:42:13 by makurz            #+#    #+#             */
/*   Updated: 2023/05/22 12:58:51 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	reset_position(t_fdf *fdf)
{
	fdf->project.x_offset = 0;
	fdf->project.y_offset = 0;
	draw_main(fdf->map, fdf);
}

static void	reset_angles(t_fdf *fdf, double alpha, double beta, double gamma)
{
		fdf->project.alpha = alpha;
		fdf->project.beta = beta;
		fdf->project.gamma = gamma;
}

void	change_projection(t_fdf *fdf, int key)
{
	if (key == MLX_KEY_J)
	{
		fdf->project.type = SPHERICAL;
		reset_angles(fdf, 45.0, 0.0, 0);
	}
	if (key == MLX_KEY_K)
	{
		fdf->project.type = ISOMETRIC;
		reset_angles(fdf, 0.0, 0.0, 0);
	}
	if (key == MLX_KEY_L)
	{
		fdf->project.type = OBLIQUE;
		reset_angles(fdf, 0.0, 0.0, 0);
	}
	draw_main(fdf->map, fdf);
}

// function for single key press input
void	static_keys(mlx_key_data_t keydata, void *tmp)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) tmp;
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		random_color(fdf);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		complete_random_color(fdf);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		clean_exit(fdf, SUCCESS);
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		change_projection(fdf, MLX_KEY_J);
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_PRESS)
		change_projection(fdf, MLX_KEY_K);
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_PRESS)
		change_projection(fdf, MLX_KEY_L);
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		reset_position(fdf);
}
