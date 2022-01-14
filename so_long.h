/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:42:50 by osallak           #+#    #+#             */
/*   Updated: 2022/01/14 14:06:16 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include<fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# define BUFFER_SIZE 1024

typedef struct s_pos
{
	int	line;
	int	colmun;
}	t_pos;

typedef struct s_info
{
	char	**map;
	t_pos	plr;
	int		height;
	int		weight;
	int		collectibles;
	t_pos	new_position;
	int		check_move;
}	t_info;

typedef struct s_pec
{
	int	player;
	int	col;
	int	esc;
}	t_pec;

//map_check
bool	check_map_name(char	*name);
bool	check_first_last(char **map);
bool	check_last_line(char	**map);
bool	if_rectangular(char	**map);
bool	if_surrounded_by_walls(char	**map);
bool	check_p_e_c(char **map);
bool	check_map_validity(char	**map);
bool	check_for_imposters(char **map);
char	**get_map(char *path, int height);
//gnl utils
int		ft_strlen(char *str);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
//game play
int		map_height(char *path);
t_pos	find_player(char	**map);
int		count_collects(char **map);
bool	check_move_validity(t_info *ptr);
void	move_udrl(t_info *ptr);

#endif