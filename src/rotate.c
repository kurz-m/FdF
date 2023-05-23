/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:53:37 by makurz            #+#    #+#             */
/*   Updated: 2023/05/24 00:56:43 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_rotation
{
	double	r[3][3];
}	t_rotation;

t_rotation	init_r_x(double angle)
{
	t_rotation	matrix;

	matrix.r[0][0] = 1;
	matrix.r[0][1] = 0;
	matrix.r[0][2] = 0;
	matrix.r[1][0] = 0;
	matrix.r[1][1] = cos(angle);
	matrix.r[1][2] = -sin(angle);
	matrix.r[2][0] = 0;
	matrix.r[2][1] = sin(angle);
	matrix.r[2][2] = cos(angle);
	return (matrix);
}

t_rotation	init_r_y(double angle)
{
	t_rotation	matrix;

	matrix.r[0][0] = cos(angle);
	matrix.r[0][1] = 0;
	matrix.r[0][2] = sin(angle);
	matrix.r[1][0] = 0;
	matrix.r[1][1] = 1;
	matrix.r[1][2] = 0;
	matrix.r[2][0] = -sin(angle);
	matrix.r[2][1] = 0;
	matrix.r[2][2] = cos(angle);
	return (matrix);
}

t_rotation	init_r_z(double angle)
{
	t_rotation	matrix;

	matrix.r[0][0] = cos(angle);
	matrix.r[0][1] = -sin(angle);
	matrix.r[0][2] = 0;
	matrix.r[1][0] = sin(angle);
	matrix.r[1][1] = cos(angle);
	matrix.r[1][2] = 0;
	matrix.r[2][0] = 0;
	matrix.r[2][1] = 0;
	matrix.r[2][2] = 1;
	return (matrix);
}


t_point3D	rotate_point3d(t_point3D point, t_rotation mat)
{
	t_point3D	result;

	result.x = mat.r[0][0] * point.x + \
			  mat.r[0][1] * point.y + \
			  mat.r[0][2] * point.z;
	result.y = mat.r[1][0] * point.x + \
			  mat.r[1][1] * point.y + \
			  mat.r[1][2] * point.z;
	result.z = mat.r[2][0] * point.x + \
			  mat.r[2][1] * point.y + \
			  mat.r[2][2] * point.z;
	return (result);
}

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
