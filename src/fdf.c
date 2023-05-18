/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:00:55 by makurz            #+#    #+#             */
/*   Updated: 2023/05/18 18:44:08 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	init_window(t_fdf *fdf)
// {
// 	int		i;
// 	int		j;
// 
// 	i = -1;
// 	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
// 	if (!fdf->mlx)
// 		exit(EXIT_FAILURE);
// 	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
// 	mlx_image_to_window(fdf->mlx, fdf->image, 0, 0);
// 	while (++i < 20)
// 	{
// 		j = -1;
// 		while (++j < 40)
// 			mlx_put_pixel(fdf->image, 20 + j, 20 + i, 0xFFFFFFFF);
// 	}
// }
// 
int32_t	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*file_name;

	// FIX: check if file is named *.fdf!!!
	if (argc != 2)
		error_handling(USAGE);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	draw_main(fdf->map, fdf);
	if(mlx_image_to_window(fdf->mlx, fdf->image, 0, 0) < 0)
		// TODO: clean up fdf etc.
		error_handling(IMG_INIT_ERROR);
	mlx_loop_hook(fdf->mlx, &key_inputs, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (EXIT_SUCCESS);
}
