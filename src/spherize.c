/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spherize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:55:42 by makurz            #+#    #+#             */
/*   Updated: 2023/05/21 16:56:04 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point3D	spherize(t_map map, t_point3D point)
{
	point.y = (map.radius + point.z) * \
			cos(point.longitude) * cos(point.latitude);
	point.x = (map.radius + point.z) * \
			sin(point.longitude) * cos(point.latitude);
	point.z = (map.radius + point.z) * \
			sin(point.latitude);
	return (point);
}

void	to_polar(t_map *map, int x, int y)
{
	float	steps_x;
	float	steps_y;

	steps_x = (M_PI * 2) / (map->width - 1);
	steps_y = M_PI / (map->height - 1);
	map->coords[x][y].longitude = -(map->coords[x][y].x) * steps_x;
	map->radius = map->width / (M_PI * 2);
	if (map->coords[x][y].y > 0)
		map->coords[x][y].latitude = ((map->coords[x][y].y) + \
				(map->height / 2)) * steps_y - 0.5 * steps_y;
	else
		map->coords[x][y].latitude = ((map->coords[x][y].y) + \
				(map->height / 2) - 1) * steps_y - 0.5 * steps_y;
}
