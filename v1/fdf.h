/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:57:04 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/04 17:10:04 by toferrei         ###   ########.fr       */
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

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		**tdp;
	int		line_l;
	int		lines;
	char	*new_line;
	char	**array;
	int		img_h;
	int		img_w;
	int		position_w;
	int		position_h;
	int		scale;
	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;
	int		count;
}	t_data;

typedef struct s_conv
{
	double		xx;
	double		yy;
	double		xx1;
	double		yy1;
	double		a;
	double		b;
	double		c;
	double		x;
	int			temp;
}	t_conv;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(int keysim, t_data *data);
void	points_creator(char *map, t_data *data);
char	*get_next_line(int fd);
void	struct_init(t_data *data);
void	two_to_three(t_data *data);

#endif