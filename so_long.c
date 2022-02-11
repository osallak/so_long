/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 22:10:23 by osallak           #+#    #+#             */
/*   Updated: 2022/02/11 17:29:12 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	collect_map_info(t_info *ptr)
{
	if (!check_map_validity(ptr->map))
	{
		printf("Error\nInvalid Map");
		ft_free(ptr->map);
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
}

char	**get_map(char *path, int height)
{
	int		fd;
	char	**map;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	map = (char **)malloc ((height + 1) * sizeof(char *));
	if (!map)
	{
		perror("Error");
		exit(1);
	}
	while (true)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	main(int ac, char **av)
{
	t_info	*ptr;

	ptr = (t_info *)malloc(sizeof(t_info));
	if (!ptr)
	{
		perror("Error");
		exit(1);
	}
	if (ac != 2)
	{
		printf("Error\nwrong number of arguments");
		free(ptr);
		exit(0);
	}
	if (!check_map_name(av[1]))
	{
		printf("Error\ninvalid map name");
		free(ptr);
		exit(0);
	}
	ptr->height = map_height(av[1]);
	ptr->map = get_map(av[1], ptr->height);
	collect_map_info(ptr);
	load_imgs(ptr);
	render(ptr);
	mlx_hook(ptr->mlx_wndw, 2, 0, key_hook, ptr);
	mlx_loop(ptr->mlx_ptr);
}
