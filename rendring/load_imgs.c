/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 01:12:07 by osallak           #+#    #+#             */
/*   Updated: 2022/01/15 01:34:47 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

static void	*load_img(t_info *ptr, char	*filename)
{
	int	width;
	int	height;

	return (mlx_xpm_file_to_image(ptr->mlx_ptr, filename, &width, &height));
}

void	load_imgs(t_info *ptr)
{
	ptr->plyr_img = load_img(ptr, "./assets/player.xpm");
	ptr->col_img = load_img(ptr, "./assets/collectibles.xpm");
	ptr->house_img = load_img(ptr, "./assets/house.xpm");
	ptr->floor_img = load_img(ptr, "./assets/floor.xpm");
	ptr->wall_img = load_img(ptr, "./assets/wall.xpm");
}
