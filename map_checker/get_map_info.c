/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 00:52:25 by osallak           #+#    #+#             */
/*   Updated: 2022/02/08 22:49:45 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

int	map_height(char *path)
{
	int		fd;
	int		height;
	char	*s;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(1);
	}
	height = 0;
	while (true)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		height++;
		free(s);
	}
	return (height);
}

int	count_collects(char **map)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	c = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'C')
				c++;
	}
	return (c);
}

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
