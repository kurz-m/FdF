/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:21:24 by makurz            #+#    #+#             */
/*   Updated: 2023/05/08 07:34:32 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_fdf *fdf)
{
	int		i;
	int		j;

	i = -1;
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!fdf->mlx)
		exit(EXIT_FAILURE);
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fdf->mlx, fdf->image, 0, 0);
	while (++i < 20)
	{
		j = -1;
		while (++j < 40)
			mlx_put_pixel(fdf->image, 20 + j, 20 + i, 0xFFFFFFFF);
	}
}

int32_t	main(void)
{
	t_fdf	fdf;

	init_window(&fdf);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
