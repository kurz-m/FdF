/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:53:18 by makurz            #+#    #+#             */
/*   Updated: 2023/05/20 17:27:23 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float latitude1 = 30.0 * M_PI / 180.0;  // First standard parallel in radians
float latitude2 = 60.0 * M_PI / 180.0;  // Second standard parallel in radians
float longitude0 = 0.0 * M_PI / 180.0;  // Central meridian in radians

// function to project the 3D points into 2D 
// and keeping the perspective of the isometric view
static t_point2D	isometric(t_point3D point, t_projection project)
{
	t_point2D	draw;

	draw.x = round((point.x - point.y) * cos(0.523599));
	draw.y = round((-point.z + (point.x + point.y)) * sin(0.523599));
	draw.x += WIDTH / 2 + project.x_offset;
	draw.y += HEIGHT / 2 + project.y_offset;
	draw.z = (int) point.z;
	return (draw);
}

static t_point2D	parallel(t_point3D point, t_projection project)
{
	t_point2D	draw;
	//float		lambda;

	float n = log(cos(latitude1) * (1 / cos(latitude2))) / log(tan(M_PI_4 + latitude2 / 2) * (1 / tan(M_PI_4 + latitude1 / 2)));
    float F = cos(latitude1) * pow(tan(M_PI_4 + latitude1 / 2), n) / n;
    float rho = F * pow(tan(M_PI_4 + point.y / 2), n);
    float theta = n * (point.x - longitude0);
	draw.x = rho * sin(theta);
    draw.y = F - rho * cos(theta);
	// lambda = cos(M_PI_4);
	// draw.x = point.x + lambda * point.z;
	// draw.y = point.y + lambda * point.z;

	// draw.x = point.x;
	// draw.y = point.y;
	draw.x += WIDTH / 2 + project.x_offset;
	draw.y += HEIGHT / 2 + project.y_offset;
	draw.z = (int) point.z;
	return (draw);
}

t_point2D	projection(t_fdf fdf, t_point3D point)
{
	t_point2D	r_point;

	point.x *= fdf.project.zoom;
	point.y *= fdf.project.zoom;
	point.z *= fdf.project.zoom;
	point = rotate_y(point, fdf.project.alpha);
	point = rotate_x(point, fdf.project.beta);
	point = rotate_z(point, fdf.project.gamma);
	// r_point = conic(point, fdf.project);
	if (fdf.project.type == ISOMETRIC)
		r_point = isometric(point, fdf.project);
	else if (fdf.project.type == PARALLEL)
		r_point = parallel(point, fdf.project);
	return (r_point);
}
