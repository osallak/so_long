/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:42:50 by osallak           #+#    #+#             */
/*   Updated: 2022/02/07 22:38:03 by osallak          ###   ########.fr       */
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
# include <mlx.h>
# define BUFFER_SIZE 1024
# define SIZE 40

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
	void	*mlx_ptr;
	void	*mlx_wndw;
	void	*col_img;
	void	*floor_img;
	void	*house_img;
	void	*plyr_img;
	void	*wall_img;
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
void	collect_map_info(t_info *ptr);
//gnl utils
int		ft_strlen(char *str);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	ft_free(char **map);
//game play
int		map_height(char *path);
t_pos	find_player(char	**map);
int		count_collects(char **map);
bool	check_move_validity(t_info *ptr);
void	move_udrl(t_info *ptr);
void	load_imgs(t_info *ptr);
void	render(t_info *ptr);
int		key_hook(int keycode, t_info *ptr);
bool	move_up(t_info *ptr);
bool	move_down(t_info *ptr);
bool	move_right(t_info *ptr);
bool	move_left(t_info *ptr);

#endif