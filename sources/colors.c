/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:19:22 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/13 15:53:28 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int colors(t_data *data, int n, int sit)
{
	if (sit == 0)
		return (data->tdp[n][3]);
	if (sit == 1)
		return (data->tdp[n][3]);
	else
		return (data->tdp[n][3]);
}
