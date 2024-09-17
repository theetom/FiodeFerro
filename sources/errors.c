/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:43:09 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/16 17:24:18 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (argc != 2)
	{
		write(1, "Wrong number of arguments", 26);
		exit (0);
	}
	if (name_verif(argv) == 0)
	{
		write(1, "Wrong file extension", 21);
		exit (0);
	}
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

