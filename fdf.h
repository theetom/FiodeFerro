/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:31:50 by toferrei          #+#    #+#             */
/*   Updated: 2024/06/28 17:06:49 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct	t_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	int		img_w;
	int		img_h;
}	t_data;

typedef struct count_data {
	t_data	t;
	t_data	img;
	int		count_in_line;
	int		count_lines;
	double		position_w;
	double		position_h;
	double	scale;
	char		**array;
	char		*new_line;
	int			**numbers;
	
}	t_count_data;



char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
int		ft_atoi(const char *nptr);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(int keysim, t_count_data *count_values);
void	points_creator(char *map, int ***numbers, t_count_data *count_values);
void	two_to_three(int **numbers, t_count_data *count_data);

#endif