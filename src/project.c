/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:53:18 by makurz            #+#    #+#             */
/*   Updated: 2023/05/21 02:11:45 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point2D	orthographic(t_point3D point, t_projection project)
{
	t_point2D	draw;

	draw.x = point.x;
	draw.y = point.y;
	draw.x += WIDTH / 2 + project.x_offset;
	draw.y += HEIGHT / 2 + project.y_offset;
	draw.z = (int) point.z;
	return (draw);
}

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

static t_point2D	oblique(t_point3D point, t_projection project)
{
	t_point2D	draw;
	float		lambda;

	lambda = 1.0 * cos(M_PI_4);
	draw.x = point.x + lambda * point.z;
	draw.y = point.y + lambda * point.z;
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
	if (fdf.project.type == ISOMETRIC)
		r_point = isometric(point, fdf.project);
	else if (fdf.project.type == OBLIQUE)
		r_point = oblique(point, fdf.project);
	else if (fdf.project.type == SPHERICAL)
	{
		point.z /= 5;
		r_point = orthographic(spherize(fdf.map, point), fdf.project);
	}
	return (r_point);
}
