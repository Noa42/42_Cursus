/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:08:55 by achacon-          #+#    #+#             */
/*   Updated: 2024/07/29 05:54:58 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digitsp(unsigned long int n, unsigned int factor)
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

static int	nbrp_base(unsigned long int x, char *base)
{
	unsigned int	factor;

	factor = ft_strlen(base);
	if (digitsp(x, factor) > 1)
	{
		nbrp_base(x / factor, base);
	}
	write(1, &base[x % factor], sizeof(char));
	return (digitsp(x, factor));
}

static int	xp_print(unsigned long int x, int cases)
{
	char	*base;

	if (cases == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (nbrp_base(x, base));
}

int	p_print(void *ptr)
{
	unsigned long int	i_adress;

	i_adress = (unsigned long int)ptr;
	ft_putstr_fd("0x", 1);
	return (xp_print(i_adress, 0) + 2);
}
