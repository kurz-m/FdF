/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:09:02 by makurz            #+#    #+#             */
/*   Updated: 2023/05/01 15:45:57 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "fdf.h"

// Initialize functions
// Function to initialize the main struct of fdf
t_fdf	*init_fdf(char *file_name);

// Utils for the fdf program

// error handling
// Function for different error handling codes
void	error_handling(int exit_code);

#endif
