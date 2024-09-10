/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:57:04 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/10 18:43:22 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define W 119
# define A 97
# define S 115
# define D 100
# define R 0x72
# define F 0x66
# define Z 0x7a
# define X 0x78
# define C 0x63
# define V 0x76
# define B 98
# define N 110
# define PLUS 0xffab
# define MINUS 0xffad
# define ESC 0xff1b

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
	int		*z;
	int		line_l;
	int		lines;
	char	*new_line;
	char	**array;
	int		img_h;
	int		img_w;
	double	position_w;
	double	position_h;
	double	scale;
	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;
	int		count;
	int		zx;
	float	angle;
	float	angles;
	float	anglec;
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
int		keys(int keycode, t_data *data);
void	points_creator(char *map, t_data *data);
char	*get_next_line(int fd);
void	struct_init(t_data *data);
void	two_to_three(t_data *data);
int		delete_everything(t_data *data);
double	two_d_cos(int position, int scale, t_data *data, int n);
double	two_d_sin(int position, int scale, t_data *data, int n);
int		keys(int keysim, t_data *data);
void	point_assigner(int fd, t_data *data);

#endif