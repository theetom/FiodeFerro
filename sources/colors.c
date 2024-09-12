/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:19:22 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/12 15:52:40 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int colors(t_data *data, int n)
{
	if (data->tdp[n][3] != 0)
		return (data->tdp[n][3]);
	else
		return (0xFFFFFF);
}