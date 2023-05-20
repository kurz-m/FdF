/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:14:59 by makurz            #+#    #+#             */
/*   Updated: 2023/05/20 21:09:19 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Read the file and store it for later parsing into a linked list
static t_list	*read_file(char *file_name, t_fdf *fdf)
{
	char	*line;
	t_list	*head;
	int		fd;

	head = NULL;
	fdf->map.height = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_handling(MAP_ERROR);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		++fdf->map.height;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	line = NULL;
	return (head);
}

// Get the width of the map
static int	get_width(t_fdf *fdf)
{
	int		width;
	char	**split_line;

	width = 0;
	split_line = ft_split((char *) fdf->map_lines->content, ' ');
	width = ft_arrlen((const char **)split_line);
	ft_arrfree(split_line);
	return (width);
}

// Set the point into the map matrix
static void	set_point(t_map *map, int x, int y, int z)
{
	map->coords[x][y].x = (double) x;
	map->coords[x][y].y = (double) y;
	map->coords[x][y].z = (double) z;
	to_polar(map, x, y);
}

// Extract the points from the linked list
static void	get_points(t_fdf *fdf)
{
	t_list	*rows;
	char	**columns;
	int		x;
	int		y;

	y = -1;
	columns = NULL;
	rows = fdf->map_lines;
	while (++y < fdf->map.height)
	{
		if (rows == NULL)
			break ;
		x = -1;
		columns = ft_split((char *) rows->content, ' ');
		while (++x < fdf->map.width)
			set_point(&fdf->map, x, y, ft_atoi(columns[x]));
		rows = rows->next;
		ft_arrfree(columns);
		columns = NULL;
	}
	// ft_arrfree(columns);
}

// Parse the map that is loaded
void	parse_map(char *file_name, t_fdf *fdf)
{
	fdf->map_lines = read_file(file_name, fdf);
	fdf->map.width = get_width(fdf);
	if (fdf->map.width == 0 || fdf->map.height == 0)
		error_handling(SIZE_ERROR);
	init_map(&fdf->map);
	get_points(fdf);
	ft_lstclear(&fdf->map_lines, &free);
}
