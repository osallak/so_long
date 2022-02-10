/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:34:52 by osallak           #+#    #+#             */
/*   Updated: 2022/02/07 22:19:05 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	put_imgs(t_info *ptr, int j, int i)
{
	if (ptr->map[i][j] == '1')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_wndw \
						, ptr->wall_img, (j * SIZE), (i * SIZE));
	else if (ptr->map[i][j] == 'C')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_wndw \
								, ptr->col_img, (j * SIZE), (i * SIZE));
	else if (ptr->map[i][j] == 'P')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_wndw \
								, ptr->plyr_img, (j * SIZE), (i * SIZE));
	else if (ptr->map[i][j] == 'E')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_wndw \
								, ptr->house_img, (j * SIZE), (i * SIZE));
}

void	render(t_info *ptr)
{
	int	i;
	int	j;

	i = -1;
	while (ptr->map[++i])
	{
		j = -1;
		while (ptr->map[i][++j])
		{
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_wndw \
				, ptr->floor_img, (j * SIZE), (i * SIZE));
			put_imgs(ptr, j, i);
		}
	}
}
