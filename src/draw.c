/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 07:17:51 by makurz            #+#    #+#             */
/*   Updated: 2023/05/16 16:15:36 by makurz           ###   ########.fr       */
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
	bresen->dx = p2.x - p1.x;
	bresen->dy = p2.y - p1.y;
	bresen->pixels = sqrt((bresen->dx * bresen->dx) + \
			(bresen->dy * bresen->dy));
	// printf("delta x: %i  delta y: %i\n", bresen->dx, bresen->dx);
	bresen->dx /= bresen->pixels;
	bresen->dy /= bresen->pixels;
	// printf("pixels: %i  x: %i, y: %i\n", bresen->pixels, p1.x, p1.y);
}

static void	bresenham(t_fdf *fdf, t_point2D p1, t_point2D p2)
{
	t_bresenham		bresen;
	int				pixels;

	pixels = 0;
	init_bresenham(&bresen, p1, p2);
	while (bresen.pixels)
	{
		draw_pixel(fdf, p1, C_WHITE);
		p1.x += bresen.dx;
		p1.y += bresen.dy;
		--bresen.pixels;
	}
}

void	draw_main(t_map map, t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	ft_bzero(fdf->image->pixels, WIDTH * HEIGHT * 4);
	// while (++y < map.height)
	while (++y < map.height - 1)
	{
		x = -1;
		while (++x < map.width - 1)
		// while (++x < map.width)
		{
			bresenham(fdf, projection(*fdf, map.coords[x][y]),
				projection(*fdf, map.coords[x + 1][y]));
			bresenham(fdf, projection(*fdf, map.coords[x][y]),
				projection(*fdf, map.coords[x][y + 1]));
			// draw_pixel(fdf, projection(*fdf, map.coords[x][y]), C_WHITE);
		}
	}
}
