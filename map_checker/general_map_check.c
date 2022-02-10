/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:40:49 by osallak           #+#    #+#             */
/*   Updated: 2022/02/05 17:32:47 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

bool	check_map_name(char *s)
{
	int		len;
	int		i;

	len = ft_strlen(s) - 4;
	i = 0;
	return (s[len] == '.' && s[len + 1] == 'b'
		&& s[len + 2] == 'e' && s[len + 3] == 'r');
}

bool	check_for_imposters(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
				return (false);
	}
	return (true);
}

bool	check_map_validity(char	**map)
{
	if (!map || !*map)
		return (false);
	return (check_first_last(map) && if_rectangular(map) \
		&& if_surrounded_by_walls(map) && check_p_e_c(map) \
		&& check_for_imposters(map));
}
