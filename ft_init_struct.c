/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:47:00 by mafissie          #+#    #+#             */
/*   Updated: 2022/06/10 18:40:59 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_init_struct(t_error *error)
{
	error->check_p = 0;
	error->check_e = 0;
	error->check_c = 0;
	error->count = 0;
	error->line = 0;
}
