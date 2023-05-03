/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 07:17:51 by makurz            #+#    #+#             */
/*   Updated: 2023/05/03 12:16:15 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_test(t_fdf * fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			printf("x: %f, y: %f, z: %f\n", \
					fdf->map.coords[x][y].axis[X], \
					fdf->map.coords[x][y].axis[Y], \
					fdf->map.coords[x][y].axis[Z]);
			++x;
		}
		printf("\n");
		++y;
	}
}
