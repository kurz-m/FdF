/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:34:23 by makurz            #+#    #+#             */
/*   Updated: 2023/05/02 16:31:31 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(t_map *map)
{
	int		width;

	width = -1;
	map->max_z = 0;
	map->min_z = 0;
	map->coords = (t_point **) malloc(sizeof(t_point *) * map->width);
	if (map->coords == NULL)
	{
		free(map->coords);
		map->coords = NULL;
		error_handling(COORDS_ERROR);
	}
	while (++width < map->width)
	{
		if ((map->coords[width] = malloc(sizeof(t_point) * map->height)) == NULL)
		{
			free_coords(map->coords, width);
			error_handling(COORDS_ERROR);
		}
	}
}

// Initializes the main struct for fdf
t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		error_handling(INIT_ERROR);
	parse_map(file_name, fdf);
	return (fdf);
}
