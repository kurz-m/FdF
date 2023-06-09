/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:34:23 by makurz            #+#    #+#             */
/*   Updated: 2023/05/20 23:49:39 by makurz           ###   ########.fr       */
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

static void	init_color_array(t_projection *project)
{
	project->color_array[0] = C_TEAL;
	project->color_array[1] = C_BURNT;
	project->color_array[2] = C_WHITE;
	project->color_array[3] = C_RED;
	project->color_array[4] = C_GREEN;
	project->color_array[5] = C_VIOLET;
	project->color_array[6] = C_SKY;
	project->color_array[7] = C_BEIGE;
	project->color_array[8] = C_FOREST;
	project->color_array[9] = C_YELLOW;
}

static void	init_projection(t_fdf *fdf)
{
	fdf->project.type = ISOMETRIC;
	fdf->project.zoom = 10;
	fdf->project.x_offset = 0;
	fdf->project.y_offset = 0;
	fdf->project.alpha = 0;
	fdf->project.beta = 0;
	fdf->project.gamma = 0;
	fdf->project.color = C_WHITE;
	init_color_array(&fdf->project);
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

	fdf = NULL;
	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		error_handling(INIT_ERROR);
	init_mlx(fdf);
	parse_map(file_name, fdf);
	init_projection(fdf);
	return (fdf);
}
