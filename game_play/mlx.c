/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:11:01 by osallak           #+#    #+#             */
/*   Updated: 2022/01/18 19:53:06 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	mlx(t_info *ptr)
{
	load_imgs(ptr);
	render(ptr);
	mlx_key_hook(ptr->mlx_wndw, key_hook, ptr);
	mlx_loop(ptr->mlx_ptr);
}
