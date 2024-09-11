/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:58:56 by achacon-          #+#    #+#             */
/*   Updated: 2023/11/04 18:06:32 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_print(long long x, int cases)
{
	char	*base;

	if (cases == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (x < 0)
	{
		return (nbr_base(4294967295 + x + 1, base));
	}
	else
	{
		return (nbr_base(x, base));
	}
}
