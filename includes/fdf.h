/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:33:24 by makurz            #+#    #+#             */
/*   Updated: 2023/04/30 14:31:14 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// NOTE: change to regular paths and include path into Makefile
# include "MLX42.h"
# include "libft.h"
# include <stdint.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 512
# define HEIGHT 256

typedef struct s_image
{
	uint32_t	width;
	uint32_t	height;
}	t_image;

typedef struct s_fdf
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_image		canvas;;
}	t_fdf;

#endif // !FDF_H
