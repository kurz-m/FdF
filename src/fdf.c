/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:00:55 by makurz            #+#    #+#             */
/*   Updated: 2023/05/19 15:51:18 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	random_color(t_fdf *fdf)
// {
// 	int		choice;
// 
// 	choice = rand() % 10;
// 	fdf->project.color = fdf->project.color_array[choice];
// 	draw_main(fdf->map, fdf);
// }
// 
// void	static_keys(mlx_key_data_t keydata, void *tmp)
// {
// 	t_fdf	*fdf;
// 
// 	fdf = (t_fdf *) tmp;
// 	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
// 		random_color(fdf);
// }

int32_t	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*file_name;

	// srand(time(NULL));
	// FIX: check if file is named *.fdf!!!
	if (argc != 2)
		error_handling(USAGE);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	draw_main(fdf->map, fdf);
	if(mlx_image_to_window(fdf->mlx, fdf->image, 0, 0) < 0)
		// TODO: clean up fdf etc.
		error_handling(IMG_INIT_ERROR);
	// mlx_key_hook(fdf->mlx, &static_keys, fdf);
	mlx_loop_hook(fdf->mlx, &key_inputs, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (EXIT_SUCCESS);
}
