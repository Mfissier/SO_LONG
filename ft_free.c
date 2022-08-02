/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:48:57 by mafissie          #+#    #+#             */
/*   Updated: 2022/06/18 00:47:04 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (*(map + i) != NULL)
		free(*(map + i++));
	free(*(map + i));
	free(map);
	return (-1);
}

int	ft_free_img(t_window *win)
{
	win->img.x = 0;
	win->img.y = 0;
	mlx_destroy_image(win->mlx, win->img.iexit);
	mlx_destroy_image(win->mlx, win->img.iplayer);
	mlx_destroy_image(win->mlx, win->img.imur);
	mlx_destroy_image(win->mlx, win->img.isol);
	mlx_destroy_image(win->mlx, win->img.icolect);
	win->img.iexit = NULL;
	win->img.iplayer = NULL;
	win->img.imur = NULL;
	win->img.isol = NULL;
	win->img.icolect = NULL;
	return (0);
}
