/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:06:43 by makurz            #+#    #+#             */
/*   Updated: 2023/05/01 15:42:28 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_handling(int exit_code)
{
	if (exit_code == 0)
		ft_putendl_fd("FDF ended and closed", 1);
	else if (exit_code == 1)
		ft_putendl_fd("Use as following: ./fdf [mapname.fdf]", 2);
	else if (exit_code == 2)
		ft_putendl_fd("Could not initialize main struct", 2);
	exit(exit_code);
}
