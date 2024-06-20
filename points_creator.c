/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:29:48 by toferrei          #+#    #+#             */
/*   Updated: 2024/06/20 15:56:06 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void counter(char *map, count_data *count_data)
{
	int			fd;
	char		**array;
	char		*new_line;
	int			x;
	
	count_data->count_in_line = 0;
	count_data->count_lines = 0;
	x = -1;
	fd = open(map, O_RDONLY);
	while ((new_line = get_next_line(fd)))
	{
		count_data->count_lines++;
		if (count_data->count_in_line == 0)
		{
			array = ft_split(new_line, ' ');
			while(array[x++])
				count_data->count_in_line++;
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
			numbers[n] = malloc(sizeof(numbers) * 3);
			numbers[n][2] = ft_atoi(array[x]);
			numbers[n][1] = y;
			numbers[n][0] = x;
			printf("x:%d	y:%d	z:%d\n", numbers[n][0], numbers[n][1], numbers[n][2]);
			n++;
		}
		y++;
		x = -1;
		free(new_line);
	}
}

void points_creator(char *map, int **numbers)
{
	int			fd;
	count_data	count_data;
	int			count;
	int			n;
	
	counter(map, &count_data);
	printf("lines:%d	words:%d\n",count_data.count_lines, count_data.count_in_line);
	count = (count_data.count_lines * count_data.count_in_line) + count_data.count_in_line + 1;
	malloc(sizeof * numbers * count);
	printf("lines:%d	words:%d\n",count_data.count_lines, count_data.count_in_line);
	fd = open(map, O_RDONLY);
	point_assigner(numbers, fd);
	n = 0;
	while (numbers[n])
	{
		printf("x:%d	y:%d	z:%d\n", numbers[n][0], numbers[n][1], numbers[n][2]);
		n++;
	}
	n = (count_data.count_lines * count_data.count_in_line) + 1;
	while (n < count)
		numbers[n++] = NULL;
	close(fd);
}
