/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:10:12 by makurz            #+#    #+#             */
/*   Updated: 2023/05/21 16:51:38 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_movement_menu(t_fdf *fdf, int *line)
{
	mlx_put_string(fdf->mlx, "##### MOVEMENT #####", 30, *line);
	*line += LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "UP: Move view up", 30, *line);
	*line += LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "DOWN: Move view down", 30, *line);
	*line += LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "RIGHT: Move view right", 30, *line);
	*line += LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "LEFT: Move view left", 30, *line);
	*line += 2 * LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "##### ZOOM #####", 30, *line);
	*line += LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "I: Zoom view in", 30, *line);
	*line += LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "O: Zoom view out", 30, *line);
	*line += 2 * LINE_HEIGHT;
}

static void	draw_rotate_menu(t_fdf *fdf, int *line)
{
	mlx_put_string(fdf->mlx, "##### ROTATE #####", 30, *line);
	*line += LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "A: Rotate around x axis", 30, *line);
	*line += LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "S: Rotate around y axis", 30, *line);
	*line += LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "D: Rotate around z axis", 30, *line);
	*line += LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "SHIFT: Hold as modifier", 30, *line);
	*line += 2 * LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "##### PROJECTION #####", 30, *line);
	*line += LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "J: Spherize", 30, *line);
	*line += LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "K: Isometric", 30, *line);
	*line += LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "L: Oblique", 30, *line);
	*line += 2 * LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "##### COLOR #####", 30, *line);
	*line += LINE_HEIGHT;
	mlx_put_string(fdf->mlx, "R: Create random color", 30, *line);
}

void	draw_menu_main(t_fdf *fdf)
{
	int		line;

	line = 2 * LINE_HEIGHT;
	draw_movement_menu(fdf, &line);
	draw_rotate_menu(fdf, &line);
}
