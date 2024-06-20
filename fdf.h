/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:31:50 by toferrei          #+#    #+#             */
/*   Updated: 2024/06/20 15:02:31 by toferrei         ###   ########.fr       */
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

typedef struct	s_data {
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

typedef struct c_data {
	int	count_in_line;
	int	count_lines;
}	count_data;



char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
int		ft_atoi(const char *nptr);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(int keysim, t_data *t);
void	points_creator(char *map, int **numbers);

#endif