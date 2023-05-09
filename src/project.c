/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:53:18 by makurz            #+#    #+#             */
/*   Updated: 2023/05/09 06:09:50 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// function to project the 3D points into 2D 
// and keeping the perspective of the isometric view
static t_point2D	isometric(t_point3D point, t_map map, t_projection project)
{
	t_point2D	draw;
	double		rad;
	double		rad_2;

	// printf("X: %f ", point.x);
	// printf("Y: %f ", point.y);
	// printf("Z: %f\n", point.z);
	
	rad = ISO_PROJECTION * M_PI / 180.0;
	// rad_2 = 35.624 * M_PI / 180.0;
	// draw.x = point.x * cos(rad) - point.z * cos(rad);
	// draw.y = point.x * sin(rad_2) + point.y * cos(rad_2) - point.z * sin(rad_2);
	// draw.x = round((point.x - point.y) * cos(rad));
	// draw.y = round((-point.z + point.x + point.y) * sin(rad));
	draw.x = (point.x - point.y) * cos(0.523599);
	draw.y = (-point.z + (point.x + point.y)) * sin(0.523599);
	// draw.x = sqrt(3) * point.x;
	// draw.y = sqrt(3) * point.y - sqrt(3) * point.z;
	// double iso_matrix[3][3] = {
    //     {0.707107, -0.408248, 0},
    //     {0, 0.816497, 0},
    //     {0.707107, 0.408248, 0}
    // };
	// draw.x = iso_matrix[0][0] * point.x + iso_matrix[0][1] * point.y + iso_matrix[0][2] * point.z;
    // draw.y = iso_matrix[1][0] * point.x + iso_matrix[1][1] * point.y + iso_matrix[1][2] * point.z;
	// draw.x = (point.x / point.z) * 25 + (map.width * project.zoom) / 2.0;
	// draw.y = (point.y / point.z) * 25 + (map.height * project.zoom) / 2.0;
	// draw.x = point.x;
	// draw.y = point.y;
	// printf("offset_x: %f, width: %i, WIDTH: %i\n", round(project.x_offset * project.zoom), map.width * project.zoom, WIDTH);
	draw.x -= (project.x_offset * project.zoom)
		- (round((map.width * project.zoom) / 2))
		- (WIDTH / 2);
	// printf("offset_y: %f, width: %i, HEIGHT: %i\n", round(project.y_offset * project.zoom), map.height * project.zoom, HEIGHT);
	draw.y -= (project.y_offset * project.zoom)
		- (round((map.height * project.zoom) / 2))
		- (HEIGHT / 2);
	// printf("X: %f ", draw.x);
	// printf("Y: %f\n", draw.y);
	return (draw);
}

t_point2D	projection(t_fdf fdf, t_point3D point)
{
	t_point2D	r_point;

	point.x *= fdf.project.zoom;
	point.y *= fdf.project.zoom;
	point.z *= fdf.project.zoom;
	// TODO: initiate projection values according to view
	// point = rotate_y(point, -46);
	// point = rotate_x(point, 180);
	// point = rotate_y(point, -fdf.project.alpha);
	// point = rotate_x(point, fdf.project.beta);
	// point = rotate_x(point, 180);
	// printf("X: %f ", point.x);
	// printf("Y: %f ", point.y);
	// printf("Z: %f\n", point.z);
	// point = rotate_z(point, fdf.project.gamma);
	r_point = isometric(point, fdf.map, fdf.project);
	// printf("X: %f ", r_point.x);
	// printf("Y: %f\n", r_point.y);
	return (r_point);
}
