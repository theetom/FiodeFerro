/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:56:35 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/23 14:15:00 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_in_base(char c, char *base)
{
	int	n;

	n = 0;
	while (c != base[n] && base[n])
		n++;
	if (c == base[n])
		return (1);
	else
		return (0);
}

static int	let_to_nbr(char c, char *base)
{
	int	n;

	n = 0;
	while (c != base[n] && base[n])
		n++;
	if (c < 'a')
		return (n);
	else
		return (n - 6);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	base_s;
	int	n;
	int	result;
	int	power;

	n = 0;
	result = 0;
	power = 1;
	base_s = 16;
	while (nbr[n + 1])
		n++;
	while (is_in_base(nbr[n], base))
	{
		result += let_to_nbr(nbr[n], base) * power;
		power *= base_s;
		n--;
	}
	return (result);
}

/* int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d\n", ft_atoi_base(argv[1], argv[2]));
	else
		printf("erro");
	return (0);
}
 */