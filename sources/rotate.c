/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:41:54 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/13 13:49:20 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rz(t_data *data, int direction)
{
	if (direction > 0)
	{
		data->anglex += 0.1;
		data->angley += 0.1;
	}
	else
	{
		data->anglex -= 0.1;
		data->angley -= 0.1;
	}
}

static void	rx(t_data *data, int direction)
{
	if (direction > 0)
	{
		data->anglez += 0.1;
		data->angley += 0.1;
	}
	else
	{
		data->anglez -= 0.1;
		data->angley -= 0.1;
	}
}

static void	ry(t_data *data, int direction)
{
	if (direction > 0)
	{
		data->anglex += 0.1;
		data->anglez += 0.1;
	}
	else
	{
		data->anglex -= 0.1;
		data->anglez -= 0.1;
	}
}

void	rotate(int k, t_data *data)
{
	if (k == Z)
		rz(data, 0);
	if (k == X)
		rz(data, 1);
	if (k == C)
		rx(data, 0);
	if (k == V)
		rx(data, 1);
	if (k == B)
		ry(data, 0);
	if (k == N)
		ry(data, 1);
}