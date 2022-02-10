/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:36:56 by osallak           #+#    #+#             */
/*   Updated: 2022/02/07 15:37:32 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

bool	move_up(t_info *ptr)
{
	ptr->new_position.line--;
	return (check_move_validity(ptr));
}

bool	move_down(t_info *ptr)
{
	ptr->new_position.line++;
	return (check_move_validity(ptr));
}

bool	move_right(t_info *ptr)
{
	ptr->new_position.colmun++;
	return (check_move_validity(ptr));
}

bool	move_left(t_info *ptr)
{
	ptr->new_position.colmun--;
	return (check_move_validity(ptr));
}
