/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 00:52:25 by osallak           #+#    #+#             */
/*   Updated: 2022/01/13 16:59:41 by osallak          ###   ########.fr       */
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
