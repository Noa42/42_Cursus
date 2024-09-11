/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:17:18 by achacon-          #+#    #+#             */
/*   Updated: 2023/11/04 17:36:11 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digits(long long n, unsigned int factor)
{
	unsigned int	result;

	result = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		result++;
		n = n / factor;
	}
	return (result);
}

int	nbr_base(long long x, char *base)
{
	unsigned int	factor;

	factor = ft_strlen(base);
	if (digits(x, factor) > 1)
	{
		nbr_base(x / factor, base);
	}
	write(1, &base[x % factor], sizeof(char));
	return (digits(x, factor));
}
