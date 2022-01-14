/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:46:43 by osallak           #+#    #+#             */
/*   Updated: 2022/01/14 14:27:08 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

bool	check_move_validity(t_info *ptr)
{
	if (ptr->map[ptr->new_position.line][ptr->new_position.colmun] == 'C')
	{
		ptr->collectibles--;
		return (true);
	}
	else if (ptr->map[ptr->new_position.line][ptr->new_position.colmun] == 'E')
	{
		if (!ptr->collectibles)
			return (true);//todo print you win and exit 
		return (false);
	}
	else if (ptr->map[ptr->new_position.line][ptr->new_position.colmun] == '1')
		return (false);
	return (true);
}

void	move_udrl(t_info *ptr)
{
	if (!ptr->check_move)
		return ;
	if (ptr->check_move == 'U')
		ptr->new_position.line--;
	else if (ptr->check_move == 'D')
		ptr->new_position.line++;
	else if (ptr->check_move == 'R')
		ptr->new_position.colmun++;
	else if (ptr->check_move == 'L')
		ptr->new_position.colmun--;
	if (!check_move_validity(ptr))
		return ;
	ptr->map[ptr->plr.line][ptr->plr.colmun] = '0';
	ptr->map[ptr->new_position.line][ptr->new_position.colmun] = 'P';
	return ;
}
