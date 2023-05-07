/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:53:18 by makurz            #+#    #+#             */
/*   Updated: 2023/05/07 16:51:31 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// function to project the 3D points into 2D 
// and keeping the perspective of the isometric view
t_point2D	isometric(t_point3D point)
{
	t_point2D	project;
	double		rad;

	rad = ISO_PROJECTION * M_PI / 180.0;
	project.x = (point.x - point.y) * cos(rad);
	project.y = (-point.z + point.x + point.y) * sin(rad);
	return (project);
}
