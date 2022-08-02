/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:06:52 by mafissie          #+#    #+#             */
/*   Updated: 2022/07/04 14:58:49 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_close(int keycode, t_window *win)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(win->mlx, win->pwin);
		mlx_destroy_display(win->mlx);
		ft_free_map(win->map);
		free(win->mlx);
		exit(0);
	}
	else if (keycode == A_KEY)
		ft_mouve_player_left(win);
	else if (keycode == W_KEY)
		ft_mouve_player_up(win);
	else if (keycode == S_KEY)
		ft_mouve_player_down(win);
	else if (keycode == D_KEY)
		ft_mouve_player_right(win);
	return (0);
}

int	ft_close_with_mouse(t_window *win)
{
	mlx_destroy_window(win->mlx, win->pwin);
	mlx_destroy_display(win->mlx);
	ft_free_map(win->map);
	free(win->mlx);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_window	win;

	if (ac != 2)
		exit(ft_error("2 args please !\n"));
	win.mlx = NULL;
	win.pwin = NULL;
	win.img.status_exit = 0;
	win.map = ft_get_map(av[1]);
	win.img.ncout = 0;
	if (ft_get_map_error(win.map) < 0)
	{
		ft_free_map(win.map);
		exit(-1);
	}
	if (win.map == NULL)
		return (-1);
	win.mlx = mlx_init();
	ft_construct_data(win.map, &win);
	win.pwin = mlx_new_window(win.mlx, 64 * win.x_map, 64 * win.y_map, \
	"so_long");
	ft_fill_img_data(&win, win.map);
	mlx_hook(win.pwin, 2, 1L << 0, ft_close, &win);
	mlx_hook(win.pwin, 17, 1L << 0, ft_close_with_mouse, &win);
	mlx_loop(win.mlx);
	return (0);
}
