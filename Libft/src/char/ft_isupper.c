/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:14:49 by makurz            #+#    #+#             */
/*   Updated: 2023/04/16 00:17:57 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks if character is uppercase
int	ft_isupper(int c)
{
	if (c > 90 || c < 65)
		return (0);
	return (1);
}
