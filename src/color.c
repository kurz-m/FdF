/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:13:07 by makurz            #+#    #+#             */
/*   Updated: 2023/04/25 10:03:11 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
 
// Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
#define BPP sizeof(int32_t)

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	main(void)
{
	int32_t		color;

	color = 0;
	// Init mlx with a canvas size of 256x256 and the ability to resize the window.
	mlx_t* mlx = mlx_init(256, 256, "White window", true);

	if (!mlx) exit(EXIT_FAILURE);

	// Create a 128x128 image.
	mlx_image_t* img = mlx_new_image(mlx, 128, 128);

	// create a different color
	color = get_rgba(55, 183, 85, 150);

	// Set the channels of each pixel in our image to the maximum byte value of 255. 
	memset(img->pixels, color, img->width * img->height * BPP);

	// Draw the image at coordinate (0, 0).
	mlx_image_to_window(mlx, img, 0, 0);

	// Run the main loop and terminate on quit.  
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}
