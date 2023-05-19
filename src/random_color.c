/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:51:21 by makurz            #+#    #+#             */
/*   Updated: 2023/05/19 23:56:44 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	complete_random_color(t_fdf *fdf)
{
	fdf->project.color = get_rgba(rand() % 256,
			rand() % 256,
			rand() % 256,
			255);
	draw_main(fdf->map, fdf);
}

void	random_color(t_fdf *fdf)
{
	int		choice;

	choice = rand() % 10;
	fdf->project.color = fdf->project.color_array[choice];
	draw_main(fdf->map, fdf);
}

void	static_keys(mlx_key_data_t keydata, void *tmp)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) tmp;
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		random_color(fdf);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		complete_random_color(fdf);
}

