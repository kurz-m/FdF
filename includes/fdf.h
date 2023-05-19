/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:24:38 by makurz            #+#    #+#             */
/*   Updated: 2023/05/19 13:38:02 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Include basic libraries for all allowed functions
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

// Include the MLX42 library
# include "MLX42.h"

// Include my own library
# include "libft.h"

// Define width and height of the window
# define WIDTH 1920
# define HEIGHT 1080

// define angles for different projections
# define ISO_PROJECTION 30.0

// define rotation angles for different views
# define ISO_ALPHA 45.0
# define ISO_BETA 35.264

/*****************************************************************************/
/*****************************************************************************/
/***********                                               *******************/
/***********            SOME COLOR VALUES                  *******************/
/***********                                               *******************/
/*****************************************************************************/
/*****************************************************************************/

# define C_TEAL 0x87CBB9FF
# define C_BURNT 0xFF6000FF
# define C_WHITE 0xFFFFFFFF
# define C_RED 0xD63447FF
# define C_GREEN 0x446A46FF
//
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
	MLX_INIT_ERROR,
	IMG_INIT_ERROR,
	INIT_ERROR,
	MAP_ERROR,
	COORDS_ERROR,
	SIZE_ERROR,
};

typedef struct s_bresenham
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		error;
	int		e2;
	int		pixels;
}	t_bresenham;

// define a struct for the coordinates of a single point 3D
typedef struct s_point3D
{
	double		x;
	double		y;
	double		z;
	uint32_t	color;
}	t_point3D;

// define a struct for the coordinates of a single point 2D
typedef struct s_point2D
{
	int		x;
	int		y;
	int		z;
}	t_point2D;


// define a struct for all points of a map
typedef struct s_map
{
	t_point3D	**coords;
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
	int		x_offset;
	int		y_offset;
	double	alpha;
	double	beta;
	double	gamma;
}	t_projection;

typedef struct s_fdf
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_map			map;
	t_list			*map_lines;
	t_projection	project;
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
void	free_coords(t_point3D **coords, int count);

// rotation functions in rotate.c
t_point3D	rotate_x(t_point3D point, double angle);
t_point3D	rotate_y(t_point3D point, double angle);
t_point3D	rotate_z(t_point3D point, double angle);

// projection functions in project.c
t_point2D	projection(t_fdf fdf, t_point3D point);

// drawing functions in draw.c
void	draw_main(t_map map, t_fdf *fdf);

// hook functions in key_inputs.c
void	key_inputs(void *tmp);

// util functions for input in input_utils.c
void	move(int key, t_fdf *fdf);
void	zoom(int key, t_fdf *fdf);
void	rotate(int key, t_fdf *fdf);
void	anti_rotate(int key, t_fdf *fdf);

// WARNING: ONLY TESTFUNCTIONS!!!! REMOVE LATER
void	print_test(t_fdf * fdf);

#endif
