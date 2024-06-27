/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:29:48 by toferrei          #+#    #+#             */
/*   Updated: 2024/06/27 13:53:52 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void counter(char *map, count_data *count_values)
{
	int			fd;
	char		**array;
	char		*new_line;
	int			x;
	
	count_values->count_in_line = 0;
	count_values->count_lines = 0;
	x = -1;
	fd = open(map, O_RDONLY);
	while ((new_line = get_next_line(fd)))
	{
		count_values->count_lines++;
		if (count_values->count_in_line == 0)
		{
			array = ft_split(new_line, ' ');
			while(array[++x])
				count_values->count_in_line++;
		x = -1;
		free(new_line);
		}
	}
	close(fd);
}

static void point_assigner(int **numbers, int fd)
{
	char	*new_line;
	char	**array;
	int		x;
	int		n;
	int		y;

	x = -1;
	y = 0;
	n = 0;
	while ((new_line = get_next_line(fd)))
	{
		array = ft_split(new_line, ' ');
		while(array[++x])
		{
			numbers[n] = malloc(sizeof * numbers * 3);
			if(!numbers[n])
				return ;
			numbers[n][2] = ft_atoi(array[x]);
			numbers[n][1] = y;
			numbers[n++][0] = x;
		}
		y++;
		x = -1;
		free(new_line);
	}
	free(array);
}

void points_creator(char *map, int ***numbers, count_data *count_values)
{
	int			fd;
	int			count;
	int			n;
	
	counter(map, count_values);
	count = (count_values->count_lines * count_values->count_in_line) + count_values->count_in_line + 1;
	(*numbers) = malloc(sizeof * (*numbers) * count);
	fd = open(map, O_RDONLY);
	point_assigner((*numbers), fd);	n = 0;
	close(fd);
}
