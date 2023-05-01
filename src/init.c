/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:34:23 by makurz            #+#    #+#             */
/*   Updated: 2023/05/01 15:44:31 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Initializes the main struct for fdf
t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;
	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		error_handling(2);
}
