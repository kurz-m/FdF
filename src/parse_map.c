/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:14:59 by makurz            #+#    #+#             */
/*   Updated: 2023/05/02 20:07:38 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_width(char *file_name)
{
	int		width;
	char	*new_line;
	char	**split_line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd  == -1)
		error_handling(MAP_ERROR);

	new_line = get_next_line(fd);
	split_line = ft_split(new_line, ' ');
	width = ft_arrlen((const char **)split_line);
	ft_arrfree(split_line);
	free(new_line);
	new_line = NULL;
	close(fd);
	return (width);
}

static int	get_height(char *file_name)
{
	int		height;
	char	*new_line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd  == -1)
		error_handling(MAP_ERROR);

	height = 0;
	while (((new_line = get_next_line(fd)) != NULL))
	{
		free(new_line);
		++height;
	}
	new_line = NULL;
	close(fd);
	return (height);
}

#include <stdio.h>
static void	put_point(t_map *map, int x, int y, int z)
{
	printf("y: %i, x: %i, z: %i\n", y, x, z);
	map->coords[x][y].axis[X] = (float) x;
	map->coords[x][y].axis[Y] = (float) y;
	map->coords[x][y].axis[Z] = (float) z;
	map->coords[x][y].color = 0;
}

static void	get_points(t_map *map, char *file_name)
{
	char	*rows;
	char	**columns;
	int		x;
	int		y;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd  == -1)
		error_handling(MAP_ERROR);
	y = 1;
	while (((rows = get_next_line(fd)) != NULL) && (map->height - y >= 0))
	{
		x = -1;
		columns = ft_split(rows, ' ');
		free(rows);
		// while (columns[++x] != NULL &&)
		while (++x < map->width)
		{
			put_point(map, x, map->height - y, ft_atoi(columns[x]));
		}
		ft_arrfree(columns);
		++y;
	}
}

void	parse_map(char *file_name, t_fdf *fdf)
{
	fdf->map.width = get_width(file_name);
	fdf->map.height = get_height(file_name);
	if (fdf->map.width == 0 || fdf->map.height == 0)
		error_handling(SIZE_ERROR);
	init_map(&fdf->map);
	get_points(&fdf->map, file_name);
}
