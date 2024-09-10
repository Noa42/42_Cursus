/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:08:55 by achacon-          #+#    #+#             */
/*   Updated: 2023/11/02 21:09:58 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_print(char *s)
{
	char	*null;

	null = "(null)";
	if (s == NULL)
	{
		ft_putstr_fd(null, 1);
		return (ft_strlen(null));
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
