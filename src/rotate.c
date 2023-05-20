/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:53:37 by makurz            #+#    #+#             */
/*   Updated: 2023/05/20 16:09:14 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// function to rotate around the x-Axis of the image
t_point3D	rotate_x(t_point3D point, double angle)
{
	double		rad;
	double		y;
	double		z;

	rad = angle * M_PI / 180.0;
	y = point.y * cos(rad) + point.z * sin(rad);
	z = -point.y * sin(rad) + point.z * cos(rad);
	point.y = y;
	point.z = z;
	return (point);
}

// function to rotate around the y-Axis of the image
t_point3D	rotate_y(t_point3D point, double angle)
{
	double		rad;
	double		x;
	double		z;

	rad = angle * M_PI / 180.0;
	x = point.x * cos(rad) + point.z * sin(rad);
	z = -point.x * sin(rad) + point.z * cos(rad);
	point.x = x;
	point.z = z;
	return (point);
}

// function to rotate around the z-Axis of the image
t_point3D	rotate_z(t_point3D point, double angle)
{
	double		rad;
	double		x;
	double		y;

	rad = angle * M_PI / 180.0;
	x = point.x * cos(rad) - point.y * sin(rad);
	y = point.x * sin(rad) + point.y * cos(rad);
	point.x = x;
	point.y = y;
	return (point);
}
