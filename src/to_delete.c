/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:16:38 by makurz            #+#    #+#             */
/*   Updated: 2023/05/03 15:16:58 by makurz           ###   ########.fr       */
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
					fdf->map.coords[x][y].x, \
					fdf->map.coords[x][y].y, \
					fdf->map.coords[x][y].z);
			++x;
		}
		printf("\n");
		++y;
	}
}
