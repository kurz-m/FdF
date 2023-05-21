/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 07:17:51 by makurz            #+#    #+#             */
/*   Updated: 2023/05/21 02:22:20 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_pixel(t_fdf *fdf, t_point2D point, uint32_t color)
{
	if (point.x < WIDTH && point.x > 0 && point.y < HEIGHT && point.y > 0)
		mlx_put_pixel(fdf->image, point.x, point.y, color);
}

static void	init_bresenham(t_bresenham *bresen, t_point2D p1, t_point2D p2)
{
	bresen->dx = abs(p2.x - p1.x);
	bresen->dy = -abs(p2.y - p1.y);
	if (p1.x < p2.x)
		bresen->sx = 1;
	else
		bresen->sx = -1;
	if (p1.y < p2.y)
		bresen->sy = 1;
	else
		bresen->sy = -1;
	bresen->error = bresen->dx + bresen->dy;
}

static void	bresenham(t_fdf *fdf, t_point2D p1, t_point2D p2)
{
	t_bresenham		bresen;

	init_bresenham(&bresen, p1, p2);
	while (1)
	{
		draw_pixel(fdf, p1, fdf->project.color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		bresen.e2 = 2 * bresen.error;
		if (bresen.e2 >= bresen.dy)
		{
			if (p1.x == p2.x)
				break ;
			bresen.error += bresen.dy;
			p1.x += bresen.sx;
		}
		if (bresen.e2 <= bresen.dx)
		{
			if (p1.y == p2.y)
				break ;
			bresen.error += bresen.dx;
			p1.y += bresen.sy;
		}
	}
}

void	draw_main(t_map map, t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	ft_bzero(fdf->image->pixels, WIDTH * HEIGHT * 4);
	while (++y < map.height)
	{
		x = -1;
		while (++x < map.width)
		{
			if (x < map.width - 1)
				bresenham(fdf, projection(*fdf, map.coords[x][y]),
					projection(*fdf, map.coords[x + 1][y]));
			if (y < map.height - 1)
				bresenham(fdf, projection(*fdf, map.coords[x][y]),
					projection(*fdf, map.coords[x][y + 1]));
		}
	}
}
