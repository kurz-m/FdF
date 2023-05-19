/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:53:18 by makurz            #+#    #+#             */
/*   Updated: 2023/05/19 13:09:57 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// function to project the 3D points into 2D 
// and keeping the perspective of the isometric view
static t_point2D	isometric(t_point3D point, t_projection project)
{
	t_point2D	draw;
	// 45 = 0.785398
	// 35 = 0.615473

	draw.x = round((point.x - point.y) * cos(0.523599));
	// draw.x = round((point.x - point.y) * cos(0.785398));
	// draw.x = round((point.x - point.y) * cos(0.615473));
	draw.y = round((-point.z + (point.x + point.y)) * sin(0.523599));
	// draw.y = round((-point.z + (point.x + point.y)) * sin(0.615473));
	// draw.y = round((-point.z + (point.x + point.y)) * sin(0.785398));
	draw.x += WIDTH / 2 + project.x_offset;
	draw.y += HEIGHT / 2 + project.y_offset;
	// draw.x -= (project.x_offset * project.zoom) - (WIDTH / 2);
	// draw.y -= (project.y_offset * project.zoom) - (HEIGHT / 2);
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
	r_point = isometric(point, fdf.project);
	return (r_point);
}
