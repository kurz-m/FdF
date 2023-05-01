/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:24:38 by makurz            #+#    #+#             */
/*   Updated: 2023/05/01 13:22:51 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Include basic libraries for all allowed functions
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

// Include the MLX42 library
# include "MLX42.h"

// Include my own library
# include "libft.h"

// Include color library for easier color coding
# include "colors.h"
# include "functions.h"

// Define width and height of the window
# define WIDTH 1920
# define HEIGHT 1080

// Defines for axis of the points
# define X 0
# define Y 1
# define Z 2

// define a struct for the coordinates of a single point
typedef struct s_point
{
	float	axis[3];
	int		color;
}	t_point;

// define enum for projection type
enum e_project
{
	ISOMETRIC,
	PARALLEL,
};

// define a struct for all points of a map
typedef struct s_map
{
	t_point		**coordinates;
	int			max_x;
	int			max_y;
	int			max_z;
	int			min_z;
}	t_map;

// define a struct for the projection
typedef struct s_projection
{
	int		type;
	int		zoom;
	float	move_x;
	float	move_y;
	double	alpha;
	double	beta;
	double	gamma;
}	t_projection;

typedef struct s_fdf
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_map			map;
	t_projection	projection;
	int				height;
	int				x_offset;
	int				y_offset;
}	t_fdf;

#endif
