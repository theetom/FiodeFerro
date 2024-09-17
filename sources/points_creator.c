/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:39:05 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/16 18:21:13 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	counter(int fd, t_data *data)
{
	int			x;
	int			n;

	x = -1;
	data->new_line = get_next_line(fd);
	while (data->new_line)
	{
		n = -1;
		data->lines++;
		if (data->line_l == 0)
		{
			data->array = ft_split(data->new_line, ' ');
			while (data->array[++x])
				data->line_l++;
			x = -1;
			while (data->array[++n])
				free(data->array[n]);
		}
		free(data->new_line);
		data->new_line = get_next_line(fd);
	}
	free(data->array);
}

void	freefree(t_data *data)
{
	int	m;

	m = -1;
	while (data->array[++m])
		free(data->array[m]);
	free(data->new_line);
	free(data->array);
}

void	point_assigner(int fd, t_data *data)
{
	int		x;
	int		n;
	int		y;

	x = -1;
	y = 0;
	n = 0;
	data->new_line = get_next_line(fd);
	while (data->new_line)
	{
		data->array = ft_split(data->new_line, ' ');
		while (data->array[++x])
		{
			coord_creator(data, n, x, y);
			n++;
		}
		y++;
		x = -1;
		freefree (data);
		data->new_line = get_next_line(fd);
	}
}

void	z_calc(t_data *data)
{
	int	n;

	n = 0;
	data->z_max = data->tdp[n][2];
	data->z_min = data->tdp[n][2];
	while (n < data->count)
	{
		data->z[n] = data->tdp[n][2];
		if (data->z_max < data->tdp[n][2])
			data->z_max = data->tdp[n][2];
		if (data->z_min > data->tdp[n][2])
			data->z_min = data->tdp[n][2];
		n++;
	}
}

void	points_creator(char *map, t_data *data)
{
	int	fd;

	data->line_l = 0;
	data->lines = 0;
	fd = open(map, O_RDONLY);
	counter(fd, data);
	close(fd);
	data->count = data->lines * data->line_l;
	data->tdp = malloc(sizeof *(data->tdp) * data->count);
	if (!data->tdp)
	{
		write(1, "malloc error", 13);
		delete_everything(data);
	}
	data->z = malloc(sizeof *(data->tdp) * data->count);
	if (!data->z)
	{
		write(1, "malloc error", 13);
		delete_everything(data);
	}
	fd = open(map, O_RDONLY);
	point_assigner(fd, data);
	close(fd);
}
