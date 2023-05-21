/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:55:42 by makurz            #+#    #+#             */
/*   Updated: 2023/05/21 02:09:38 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// t_point2D	mercator(t_point3D point, t_projection project, t_map map)
// {
// 	t_point2D	draw;
// 
// 	draw.x = map.radius * point.longitude / (2 * M_PI);
// 	draw.y = map.radius * log(tan((point.latitude / 2) + M_PI_4));
// 	draw.x += WIDTH / 2 + project.x_offset;
// 	draw.y += HEIGHT / 2 + project.y_offset;
// 	draw.z = (int) point.z;
// 	return (draw);
// }

t_point2D	mercator(t_point3D point, t_projection project, t_map map)
{
	t_point2D	draw;

	point.latitude = point.latitude * M_PI / 180.0;
	point.longitude = point.longitude * M_PI / 180.0;
	draw.x = map.radius * point.longitude * cos(point.latitude);
	draw.y = map.radius * point.latitude;
	draw.x += WIDTH / 2 + project.x_offset;
	draw.y += HEIGHT / 2 + project.y_offset;
	draw.z = (int) point.z;
	return (draw);
}

/*
t_point3D	spherize(t_map map, t_point3D point)
{
	point.latitude = point.latitude * M_PI / 180.0;
	point.longitude = point.longitude * M_PI / 180.0;
	point.x = (map.radius + point.z) * \
			  cos(point.longitude) * sin(point.latitude);
	point.y = (map.radius + point.z) * \
			  sin(point.longitude) * sin(point.latitude);
	point.z = (map.radius + point.z) * \
			  cos(point.longitude);
	return (point);
}*/

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
