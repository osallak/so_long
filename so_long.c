/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 22:10:23 by osallak           #+#    #+#             */
/*   Updated: 2022/01/14 15:59:34 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	**get_map(char *path, int height)
{
	int		fd;
	char	**ret;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	ret = (char **)malloc ((height + 1) * sizeof(char *));
	if (!ret)
		exit(1); //todo ft_error
	while (true)
	{
		ret[i] = get_next_line(fd);
		if (!ret[i])
			break ;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

int	main(int ac, char **av)
{
	t_info	*infos;

	infos = (t_info *)malloc(sizeof(t_info));
	if (ac != 2)
		exit(0);//TODO print smthng and exit
	if (!check_map_name(av[1]))
		exit(0);//TODO invalid map name
	infos->height = map_height(av[1]);
	infos->map = get_map(av[1], infos->height);
	if (!check_map_validity(infos->map))
	{
		printf("Error\nInvalid Map");// TODO free
		return (0);
	}
	infos->collectibles = count_collects(infos->map);
	infos->plr = find_player(infos->map);
	infos->weight = ft_strlen(infos->map[0]);
	int i = -1;
	while (infos->map[++i])
		printf("%s\n",infos->map[i]);
	infos->check_move = 'R';
	infos->new_position.line = infos->plr.line;
	infos->new_position.colmun = infos->plr.colmun;
	move_udrl(infos);
	printf("\n--------------------------------\n");
	i = -1;
	while (infos->map[++i])
		printf("%s\n",infos->map[i]);
}
