/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:05:06 by osallak           #+#    #+#             */
/*   Updated: 2022/02/05 17:32:28 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

bool	if_rectangular(char	**map)
{
	int	i;
	int	len;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[++i])
		if (ft_strlen(map[i]) != len)
			return (false);
	return (true);
}

bool	check_first_last(char	**map)
{
	int	i;
	int	j;

	i = -1;
	while (map[0][++i])
		if (map[0][i] != '1')
			return (false);
	i = 0;
	while (map[i])
		i++;
	i--;
	j = -1;
	while (map[i][++j])
		if (map[i][j] != '1')
			return (false);
	return (true);
}

bool	if_surrounded_by_walls(char	**map)
{
	int	i;
	int	len;

	len = 0;
	while (map[0][len])
		len++;
	len--;
	i = -1;
	while (map[++i])
		if (map[i][0] != '1' || map[i][len] != '1')
			return (false);
	return (true);
}

bool	check_p_e_c(char **map)
{
	t_pec	m_info;
	int		i;
	int		j;

	m_info.player = 0;
	m_info.col = 0;
	m_info.esc = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				m_info.esc++;
			else if (map[i][j] == 'P')
				m_info.player++;
			else if (map[i][j] == 'C')
				m_info.col++;
		}
	}
	return (m_info.player == 1 && m_info.col >= 1 && m_info.esc >= 1);
}
