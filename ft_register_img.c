/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_register_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 02:19:52 by mafissie          #+#    #+#             */
/*   Updated: 2022/06/13 23:38:11 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

void	ft_register_img(t_window *win)
{
	int	size;

	size = 0;
	win->img.iplayer = NULL;
	win->img.iexit = NULL;
	win->img.icolect = NULL;
	win->img.imur = NULL;
	win->img.isol = NULL;
	win->img.x = 0;
	win->img.y = 0;
	win->img.iplayer = mlx_xpm_file_to_image(win->mlx, \
	"./img/joy.xpm", &size, &size);
	win->img.iexit = mlx_xpm_file_to_image(win->mlx, \
	"./img/os.xpm", &size, &size);
	win->img.icolect = mlx_xpm_file_to_image(win->mlx, \
	"./img/kirby.xpm", &size, &size);
	win->img.imur = mlx_xpm_file_to_image(win->mlx, \
	"./img/mur.xpm", &size, &size);
	win->img.isol = mlx_xpm_file_to_image(win->mlx, \
	"./img/sol.xpm", &size, &size);
}
