/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:00:55 by makurz            #+#    #+#             */
/*   Updated: 2023/05/22 18:11:20 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void cleanup() {
// 	char command[100];
// 	pid_t pid = getpid();
// 	sprintf(command, "leaks %d", pid);
// 	system(command);
// }

// add atexit(cleanup) for leak checking
int32_t	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*file_name;

	srand(time(NULL));
	if (argc != 2 || ft_strstr(argv[1], ".fdf") == NULL)
		error_handling(USAGE);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	draw_menu_main(fdf);
	draw_main(fdf->map, fdf);
	if (mlx_image_to_window(fdf->mlx, fdf->image, 0, 0) < 0)
		clean_exit(fdf, IMG_INIT_ERROR);
	mlx_key_hook(fdf->mlx, &static_keys, fdf);
	mlx_loop_hook(fdf->mlx, &key_inputs, fdf);
	mlx_loop(fdf->mlx);
	clean_exit(fdf, SUCCESS);
	return (EXIT_SUCCESS);
}
