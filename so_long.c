/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 22:10:23 by osallak           #+#    #+#             */
/*   Updated: 2022/01/18 21:32:53 by osallak          ###   ########.fr       */
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
	t_info	*ptr;

	ptr = (t_info *)malloc(sizeof(t_info));
	if (ac != 2)
		exit(0);//TODO print smthng and exit
	if (!check_map_name(av[1]))
		exit(0);//TODO invalid map name
	ptr->height = map_height(av[1]);
	ptr->map = get_map(av[1], ptr->height);
	if (!check_map_validity(ptr->map))
	{
		printf("Error\nInvalid Map");// TODO free
		exit (0);
	}
	ptr->collectibles = count_collects(ptr->map);
	ptr->plr = find_player(ptr->map);
	ptr->weight = ft_strlen(ptr->map[0]);
	ptr->new_position.line = ptr->plr.line;
	ptr->new_position.colmun = ptr->plr.colmun;
	ptr->mlx_ptr = mlx_init();
	ptr->mlx_wndw = mlx_new_window(ptr->mlx_ptr, (ptr->weight * SIZE), \
									(ptr->height * SIZE), "so_long");
	load_imgs(ptr);
	render(ptr);
	mlx_key_hook(ptr->mlx_wndw, key_hook, ptr);
	mlx_loop(ptr->mlx_ptr);
}
