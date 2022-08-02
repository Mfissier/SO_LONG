/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:11:59 by mafissie          #+#    #+#             */
/*   Updated: 2022/07/04 15:13:03 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_name_map_error(char *file, int fd)
{
	if (fd == -1)
		exit(ft_error("fd invalid !\n"));
	if (file)
	{
		if (ft_strlen(file) > 4)
		{
			if (file[ft_strlen(file) - 1] != 'r')
				exit(ft_error("Why you test this... It's a .ber !\n"));
			else if (file[ft_strlen(file) - 2] != 'e')
				exit(ft_error("Why you test this... It's a .ber !\n"));
			else if (file[ft_strlen(file) - 3] != 'b')
				exit(ft_error("Why you test this... It's a .ber !\n"));
			else if (file[ft_strlen(file) - 4] != '.')
				exit(ft_error("Why you test this... It's a .ber !\n"));
		}
		else
			ft_error("Why you test this... It's a .ber !\n");
	}
}

char	**ft_get_map(char *file)
{
	int		fd;
	char	*str;
	char	*tmp;
	char	**map;

	fd = open(file, O_RDONLY);
	ft_name_map_error(file, fd);
	tmp = ft_calloc(1, sizeof(char));
	str = get_next_line(fd);
	while (str != NULL)
	{
		tmp = ft_strjoin(tmp, str);
		free(str);
		str = get_next_line(fd);
	}
	map = ft_split(tmp, '\n');
	close (fd);
	if (map == NULL)
	{
		free(tmp);
		free(str);
		ft_error("MALLOC FAILED !");
	}
	return (free(tmp), map);
}
