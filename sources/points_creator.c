/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:39:05 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/12 15:49:57 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	counter(int fd, t_data *data)
{
	int			x;
	int			n;

	x = -1;
	while ((data->new_line = get_next_line(fd)))
	{
		n = -1;
		data->lines++;
		if (data->line_l == 0)
		{
			data->array = ft_split(data->new_line, ' ');
			while(data->array[++x])
				data->line_l++;
			x = -1;
			while(data->array[++n])
				free(data->array[n]);
		}
		free(data->new_line);
	}
	free(data->array);
}

static void	coord_creator(t_data *data, int n, int x, int y)
{
	int m;
	char **temp;

	temp = ft_split(data->array[x], ',');
	m = -1;
	data->tdp[n] = malloc(sizeof * data->tdp * 4);
	if(!data->tdp[n])
		return ;
	if (temp[1])
		data->tdp[n][3] = ft_atoi_base(temp[1], "0123456789ABCDEF");
	else
		data->tdp[n][3] = 0;
	data->tdp[n][2] = ft_atoi(data->array[x]);
	data->tdp[n][1] = y;
	data->tdp[n][0] = x;
	while(temp[++m])
		free(temp[m]);
	free(temp);
}

void	point_assigner(int fd, t_data *data)
{
	int		x;
	int		n;
	int		y;
	int		m;

	x = -1;
	y = 0;
	n = 0;
	while ((data->new_line = get_next_line(fd)))
	{
		data->array = ft_split(data->new_line, ' ');
		while(data->array[++x])
		{
			coord_creator(data, n, x, y);
			n++;
		}
		y++;
		x = -1;
		m = -1;
		while(data->array[++m])
			free(data->array[m]);
		free(data->new_line);
		free(data->array);
	}
}

void	points_creator(char *map, t_data *data)
{
	int	fd;
	int	n;

	n = 0;
	data->line_l = 0;
	data->lines = 0;
	fd = open(map, O_RDONLY);
	counter(fd, data);
	close(fd);
	data->count = data->lines * data->line_l;
	data->tdp = malloc(sizeof *(data->tdp) * data->count);
	data->z = malloc(sizeof *(data->tdp) * data->count);
	fd = open(map, O_RDONLY);
	point_assigner(fd, data);
	data->z_max = data->tdp[n][2];
	while (n < data->count)
	{
		data->z[n] = data->tdp[n][2];
		if (data->z_max < data->tdp[n][2])
			data->z_max = data->tdp[n][2];
		n++;
	}
	close(fd);
}
