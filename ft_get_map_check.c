/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:54:55 by mafissie          #+#    #+#             */
/*   Updated: 2022/06/27 20:43:04 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_error(char *str)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	return (-1);
}

int	ft_check_map_is_quadrilatere(char **map)
{
	t_error	error;
	int		i;
	int		j;

	ft_init_struct(&error);
	i = 0;
	j = -1;
	error.line = ft_strlen(map[0]);
	while (*(map + (++j)) != NULL)
	{
		while (*(*(map + j) + i))
		{
			if (j == 0 || i == 0 || (i == (ft_strlen(*(map + j)) - 1))
				|| ((*(map + j + 1) == NULL)))
				if (*(*(map + j) + i) != '1')
					return (-1);
			error.count++;
			i++;
		}
		if (error.count != error.line)
			return (-1);
		error.count = 0;
		i = 0;
	}
	return (1);
}

int	ft_check_config_map(char **map)
{
	t_error	error;
	int		i;
	int		j;

	ft_init_struct(&error);
	i = 0;
	j = -1;
	while (*(map + (++j)) != NULL)
	{
		while (*(*(map + j) + (i++)))
		{
			if (*(*(map + j) + i) == 'P')
				error.check_p = 1;
			if (*(*(map + j) + i) == 'E')
				error.check_e = 1;
			if (*(*(map + j) + i) == 'C')
				error.check_c = 1;
		}
		i = 0;
	}
	if (error.check_c == 1 && error.check_e == 1 && error.check_p == 1)
		return (1);
	else
		return (-1);
}

int	ft_len_map(char **map)
{
	t_error	error;
	int		i;
	int		j;

	ft_init_struct(&error);
	i = 0;
	j = -1;
	error.count = 0;
	while (*(map + (++j)) != NULL)
	{
		while (*(*(map + j) + i) != '\0')
		{
			if (!(*(*(map + j) + i) == '1' || *(*(map + j) + i) == 'P'
					|| *(*(map + j) + i) == 'E' || *(*(map + j) + i) == 'C'
					|| *(*(map + j) + i) == '0'))
				return (-1);
			error.count++;
			i++;
		}
		i = 0;
	}
	if (j < 3)
		return (-1);
	return (error.count);
}

int	ft_get_map_error(char **map)
{
	if (ft_len_map(map) < 15)
		return (ft_error("Map architecture !\n"));
	if (ft_check_config_map(map) == -1)
		return (ft_error("Need P or E or C !\n"));
	if (ft_check_map_is_quadrilatere(map) == -1)
		return (ft_error("Map is not quadrilateral !\n"));
	else
		return (1);
}
