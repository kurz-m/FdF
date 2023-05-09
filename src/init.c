/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:34:23 by makurz            #+#    #+#             */
/*   Updated: 2023/05/09 08:45:21 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(t_map *map)
{
	int		width;

	width = -1;
	map->max_z = 0;
	map->min_z = 0;
	map->coords = (t_point3D **) malloc(sizeof(t_point3D *) * map->width);
	if (map->coords == NULL)
	{
		free(map->coords);
		map->coords = NULL;
		error_handling(COORDS_ERROR);
	}
	while (++width < map->width)
	{
		map->coords[width] = malloc(sizeof(t_point3D) * map->height);
		if ((map->coords[width]) == NULL)
		{
			free_coords(map->coords, width);
			error_handling(COORDS_ERROR);
		}
	}
}

static void	init_projection(t_fdf *fdf)
{
	fdf->project.type = ISOMETRIC;
	fdf->project.zoom = 20;
	fdf->project.x_offset = fdf->map.width / 2;
	fdf->project.y_offset = fdf->map.height / 2;
	fdf->project.alpha = 45;
	fdf->project.beta = -35.264;
	fdf->project.gamma = 0;
	fdf->project.move_x = 0;
	fdf->project.move_y = 0;
}

static void	init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "ALF", true);
	if (!fdf->mlx)
		error_handling(MLX_INIT_ERROR);
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->image)
		error_handling(IMG_INIT_ERROR);
}

// Initializes the main struct for FdF
t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	init_mlx(fdf);
	if (fdf == NULL)
		error_handling(INIT_ERROR);
	parse_map(file_name, fdf);
	init_projection(fdf);
	return (fdf);
}
