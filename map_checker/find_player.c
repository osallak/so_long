/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:37:01 by osallak           #+#    #+#             */
/*   Updated: 2022/01/13 01:25:49 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_pos	find_player(char	**map)
{
	int			y;
	int			x;
	t_pos		pos;
	int			tmp;

	y = -1;
	tmp = 1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{	
			if (map[y][x] == 'P')
			{
				pos.line = y;
				pos.colmun = x;
				tmp = 0;
				break ;
			}
		}
		if (!tmp)
			break ;
	}
	return (pos);
}
