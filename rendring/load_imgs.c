/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 01:12:07 by osallak           #+#    #+#             */
/*   Updated: 2022/02/05 17:34:15 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

static void	*load_img(t_info *ptr, char	*filename)
{
	int	tmp;

	return (mlx_xpm_file_to_image(ptr->mlx_ptr, filename, &tmp, &tmp));
}

void	load_imgs(t_info *ptr)
{
	ptr->plyr_img = load_img(ptr, "./assets/player.xpm");
	ptr->col_img = load_img(ptr, "./assets/collectibles.xpm");
	ptr->house_img = load_img(ptr, "./assets/exit.xpm");
	ptr->floor_img = load_img(ptr, "./assets/floor.xpm");
	ptr->wall_img = load_img(ptr, "./assets/wall.xpm");
}
