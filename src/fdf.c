/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:00:55 by makurz            #+#    #+#             */
/*   Updated: 2023/05/02 15:07:38 by makurz           ###   ########.fr       */
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

	if (argc != 2)
		error_handling(USAGE);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (EXIT_SUCCESS);
}
