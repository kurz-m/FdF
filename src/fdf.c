/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:00:55 by makurz            #+#    #+#             */
/*   Updated: 2023/05/20 15:47:09 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int32_t	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*file_name;

	srand(time(NULL));
	// FIX: check if file is named *.fdf!!!
	if (argc != 2)
		error_handling(USAGE);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	draw_main(fdf->map, fdf);
	if (mlx_image_to_window(fdf->mlx, fdf->image, 0, 0) < 0)
		clean_exit(fdf, IMG_INIT_ERROR);
	mlx_key_hook(fdf->mlx, &static_keys, fdf);
	mlx_loop_hook(fdf->mlx, &key_inputs, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (EXIT_SUCCESS);
}
