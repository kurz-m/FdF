/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:24:38 by makurz            #+#    #+#             */
/*   Updated: 2023/05/02 21:39:09 by makurz           ###   ########.fr       */
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

// Define width and height of the window
# define WIDTH 1920
# define HEIGHT 1080

// Defines for axis of the points
# define X 0
# define Y 1
# define Z 2

/*****************************************************************************/
/*****************************************************************************/
/***********                                               *******************/
/***********            SOME COLOR VALUES                  *******************/
/***********                                               *******************/
/*****************************************************************************/
/*****************************************************************************/

# define C_TEAL 0x87CBB9
# define C_BURNT 0xFF6000
# define C_WHITE 0xFFFFFF
# define C_RED 0xD63447
# define C_GREEN 0x446A46

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

// define enum for error handling
enum e_errors
{
	SUCCESS,
	USAGE,
	INIT_ERROR,
	MAP_ERROR,
	COORDS_ERROR,
	SIZE_ERROR,
};

// define a struct for all points of a map
typedef struct s_map
{
	t_point		**coords;
	int			width;
	int			height;
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
	int				x_offset;
	int				y_offset;
}	t_fdf;

/*****************************************************************************/
/*****************************************************************************/
/***********                                               *******************/
/***********            FUNCTIONS START HERE               *******************/
/***********                                               *******************/
/*****************************************************************************/
/*****************************************************************************/

// Initialize functions
// Function to initialize the main struct of fdf
t_fdf	*init_fdf(char *file_name);
void	init_map(t_map *map);

// Utils for the fdf program
void	parse_map(char *file_name, t_fdf *fdf);

// error handling
// Function for different error handling codes
void	error_handling(int exit_code);
void	free_coords(t_point **coords, int count);

#endif
