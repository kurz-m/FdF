/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 07:17:51 by makurz            #+#    #+#             */
/*   Updated: 2023/05/16 13:55:19 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_pixel(t_fdf *fdf, t_point2D point, uint32_t color)
{
	if (point.x < WIDTH && point.x > 0 && point.y < HEIGHT && point.y > 0)
		mlx_put_pixel(fdf->image, round(point.x), round(point.y), color);
}

static void	init_bresenham(t_bresenham *bresen, t_point2D p1, t_point2D p2)
{
	bresen->dx = p2.x - p1.x;
	bresen->dy = p2.y - p1.y;
	// bresen->dx = abs((int) round(p2.x) - (int) round(p1.x));
	// bresen->dy = -abs((int) round(p2.y) - (int) round(p1.y));
	if (bresen->dx < 0)
		bresen->sx = -1;
	else
		bresen->sx = 1;
	if (bresen->dy < 0)
		bresen->sy = -1;
	else
		bresen->sy = 1;
	bresen->dx = abs((int) round(bresen->dx));
	bresen->dy = abs((int) round(bresen->dy));
	// if (p1.x < p2.x)
	// 	bresen->sx = 1;
	// else
	// 	bresen->sx = -1;
	// if (p1.y < p2.y)
	// 	bresen->sx = 1;
	// else
	// 	bresen->sx = -1;
	// bresen->error = bresen->dx + bresen->dy;
	bresen->error = 2 * bresen->dy - bresen->dx;
}

static void	bresenham(t_fdf *fdf, t_point2D p1, t_point2D p2)
{
	t_bresenham		bresen;
	int		i;

	i = 0;
	init_bresenham(&bresen, p1, p2);
	while (p1.x != p2.x && p1.y != p2.y)
	{
		draw_pixel(fdf, p1, C_WHITE);
		if (bresen.error > 0)
		{
			p1.y += bresen.sy;
			bresen.error -= 2 * bresen.dx;
		}
		p1.x += bresen.sx;
		bresen.error += 2 * bresen.dy;
		// if (p1.x == p2.x && p1.y == p2.y)
		// 	break ;
		// if (bresen.e2 >= bresen.dy)
		// {
		// 	bresen.error += bresen.dy;
		// 	p1.x += bresen.sx;
		// }
		// if (bresen.e2 <= bresen.dx)
		// {
		// 	bresen.error += bresen.dx;
		// 	p1.x += bresen.sy;
		// }
	}
}

void	draw_main(t_map map, t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	// ft_memset(fdf->image->pixels, 0xFFFFFFFF, WIDTH * HEIGHT * 4);
	ft_bzero(fdf->image->pixels, WIDTH * HEIGHT * 4);
	while (++y < map.height)
	// while (++y < map.height - 1)
	{
		x = -1;
		// while (++x < map.width - 1)
		while (++x < map.width)
		{
			// bresenham(fdf, projection(*fdf, map.coords[x][y]),
			// 	projection(*fdf, map.coords[x + 1][y]));
			// bresenham(fdf, projection(*fdf, map.coords[x][y]),
			// 	projection(*fdf, map.coords[x][y + 1]));
			draw_pixel(fdf, projection(*fdf, map.coords[x][y]), C_WHITE);
		}
	}
}
