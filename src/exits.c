/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:06:43 by makurz            #+#    #+#             */
/*   Updated: 2023/05/20 16:08:30 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// function used for freeing the coordinates
// used during initialization and closing the program
void	free_coords(t_point3D **coords, int count)
{
	while (--count >= 0)
	{
		free(coords[count]);
		coords[count] = NULL;
	}
	free(coords);
}

// function to handle the different errors
void	error_handling(int exit_code)
{
	if (exit_code == SUCCESS)
		ft_putendl_fd("FDF ended and closed.", 1);
	else if (exit_code == USAGE)
		ft_putendl_fd("Use as following: ./FdF [mapname.fdf]", 2);
	else if (exit_code == MLX_INIT_ERROR)
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
	else if (exit_code == IMG_INIT_ERROR)
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
	else if (exit_code == INIT_ERROR)
		ft_putendl_fd("Could not initialize main struct.", 2);
	else if (exit_code == MAP_ERROR)
		ft_putendl_fd("Unable to locate the map.", 2);
	else if (exit_code == COORDS_ERROR)
		ft_putendl_fd("Unable to allocate memory for the points.", 2);
	else if (exit_code == SIZE_ERROR)
		ft_putendl_fd("Map has no height or width.", 2);
	exit(exit_code);
}

// function to free all my allocated memory
// and close the program in a clean manner
void	clean_exit(t_fdf *fdf, int exit_code)
{
	mlx_delete_image(fdf->mlx, fdf->image);
	mlx_close_window(fdf->mlx);
	mlx_terminate(fdf->mlx);
	free_coords(fdf->map.coords, fdf->map.width);
	free(fdf);
	error_handling(exit_code);
}
