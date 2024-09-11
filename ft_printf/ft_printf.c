/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:14:58 by achacon-          #+#    #+#             */
/*   Updated: 2023/11/06 13:24:04 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	placeholders(va_list params, char a)
{
	int	counter;

	counter = 0;
	if (a == 'i' || a == 'd')
		counter = counter + i_print(va_arg(params, int));
	if (a == 'u')
		counter = counter + u_print(va_arg(params, int));
	if (a == 'c')
		counter = counter + c_print((char)va_arg(params, int));
	if (a == 's')
		counter = counter + s_print(va_arg(params, char *));
	if (a == 'x')
		counter = counter + x_print(va_arg(params, int), 0);
	if (a == 'p')
		counter = counter + p_print(va_arg(params, void *));
	if (a == 'X')
		counter = counter + x_print(va_arg(params, int), 1);
	if (a == '%')
	{
		write(1, "%", sizeof(char));
		counter ++;
	}
	return (counter);
}

int	ft_printf(char const *s, ...)
{
	va_list	params;
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	va_start(params, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			counter = counter + placeholders(params, s[i + 1]);
			i = i + 2;
		}
		else
		{
			counter ++;       
			ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	va_end(params);
	return (counter);
}
