/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:46:43 by osallak           #+#    #+#             */
/*   Updated: 2022/02/09 15:42:25 by osallak          ###   ########.fr       */
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
		{
			write (1, "you Win\n", 8);
			ft_free(ptr->map);
			exit (0);
		}
		return (false);
	}
	else if (ptr->map[ptr->new_position.line][ptr->new_position.colmun] == '1')
		return (false);
	return (true);
}

void	initialize_plr_pos(t_info *ptr)
{
	ptr->new_position.line = ptr->plr.line;
	ptr->new_position.colmun = ptr->plr.colmun;
}

void	move_udrl(t_info *ptr)
{
	int			check;
	static int	moves;

	check = true;
	if (ptr->check_move == 'U')
		check *= move_up(ptr);
	else if (ptr->check_move == 'D')
		check *= move_down(ptr);
	else if (ptr->check_move == 'R')
		check *= move_right(ptr);
	else if (ptr->check_move == 'L')
		check *= move_left(ptr);
	else
		return ;
	if (!check)
	{
		initialize_plr_pos(ptr);
		return ;
	}
	printf("Number of Moves : %d\n", ++moves);
	ptr->map[ptr->plr.line][ptr->plr.colmun] = '0';
	ptr->map[ptr->new_position.line][ptr->new_position.colmun] = 'P';
	ptr->plr.line = ptr->new_position.line;
	ptr->plr.colmun = ptr->new_position.colmun;
	render(ptr);
}

int	key_hook(int keycode, t_info *ptr)
{
	if (keycode == 53)
	{
		mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_wndw);
		ft_free(ptr->map);
		exit(0);
	}
	if (keycode == 13)
		ptr->check_move = 'U';
	else if (keycode == 1)
		ptr->check_move = 'D';
	else if (keycode == 2)
		ptr->check_move = 'R';
	else if (keycode == 0)
		ptr->check_move = 'L';
	else
		return (0);
	move_udrl(ptr);
	ptr->check_move = 0;
	return (0);
}
