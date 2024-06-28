/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:29:48 by toferrei          #+#    #+#             */
/*   Updated: 2024/06/28 17:20:07 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void counter(char *map, t_count_data *count_values)
{
	int			fd;
	int			x;
	int			n;
	
	count_values->count_in_line = 0;
	count_values->count_lines = 0;
	x = -1;
	fd = open(map, O_RDONLY);
	while ((count_values->new_line = get_next_line(fd)))
	{
		n = -1;
		count_values->count_lines++;
		if (count_values->count_in_line == 0)
		{
			count_values->array = ft_split(count_values->new_line, ' ');
			while(count_values->array[++x])
				count_values->count_in_line++;
		x = -1;
		while(count_values->array[++n])
			free(count_values->array[n]);
		free(count_values->new_line);
		}
	}
	free(count_values->array);
	close(fd);
}

static void point_assigner(int **numbers, int fd, t_count_data *count_values)
{
	int		x;
	int		n;
	int		y;
	int		m;

	x = -1;
	y = 0;
	n = 0;
	while ((count_values->new_line = get_next_line(fd)))
	{
		count_values->array = ft_split(count_values->new_line, ' ');
		while(count_values->array[++x])
		{
			numbers[n] = malloc(sizeof * numbers * 3);
			if(!numbers[n])
				return ;
			numbers[n][2] = ft_atoi(count_values->array[x]);
			numbers[n][1] = y;
			numbers[n++][0] = x;
		}
		y++;
		x = -1;
		m = 0;
		while(count_values->array[++m])
			free(count_values->array[m]);
		free(count_values->new_line);
	}
	free(count_values->array);
}

void points_creator(char *map, int ***numbers, t_count_data *count_values)
{
	int			fd;
	int			count;
	
	counter(map, count_values);
	count = (count_values->count_lines * count_values->count_in_line) + count_values->count_in_line + 1;
	(*numbers) = malloc(sizeof * (*numbers) * count);
	fd = open(map, O_RDONLY);
	point_assigner((*numbers), fd, count_values);
	close(fd);
}
