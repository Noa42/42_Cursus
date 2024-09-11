/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:08:55 by achacon-          #+#    #+#             */
/*   Updated: 2023/11/04 17:35:23 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	i_print(long long nb)
{
	int	counter;

	counter = 0;
	if (nb < 0)
	{
		write(1, "-", sizeof(char));
		nb = -nb;
		counter ++;
	}
	return (counter + nbr_base(nb, "0123456789"));
}
