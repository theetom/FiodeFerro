/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:43:09 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/26 15:30:21 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	empty_file_checker(t_data *data)
{
	if (!data->new_line)
	{
		write(1, "file is empty\n", 15);
		exit(1);
	}
}

static int	name_verif(char *f)
{
	int	n;

	n = 0;
	while (f[n])
		n++;
	n -= 4;
	if (f[n] != '.')
		return (0);
	n++;
	if (f[n] != 'f')
		return (0);
	n++;
	if (f[n] != 'd')
		return (0);
	n++;
	if (f[n] != 'f')
		return (0);
	n++;
	if (f[n] == '\0')
		return (1);
	else
		return (0);
}

void	first_verifs(int argc, char *argv)
{
	int	test;

	if (argc != 2)
	{
		write(1, "Wrong number of arguments\n", 27);
		exit (0);
	}
	if (name_verif(argv) == 0)
	{
		write(1, "Wrong file extension\n", 22);
		exit (0);
	}
	test = open(argv, O_RDONLY);
	if (test < 0)
	{
		close(test);
		write(1, "Invalid file\n", 14);
		exit (0);
	}
	else
		close (test);
}

void	z_verif(t_data *data)
{
	int	n;

	n = 0;
	while (n < data->count)
	{
		if (data->tdp[n][2] < -100000 || data->tdp[n][2] > 100000)
		{
			write(1, "Z value in file is too big\n", 28);
			write(1, "(keep them between -100000 and 100000)\n", 40);
			delete_everything(data);
		}
		n++;
	}
}
