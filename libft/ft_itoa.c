/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:11:05 by achacon-          #+#    #+#             */
/*   Updated: 2023/10/25 15:33:04 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(int n)
{
	int	result;

	if (n < 0)
		n = -n;
	result = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		result++;
		n = n / 10;
	}
	return (result);
}

static char	*positive(int n)
{
	int		digs;
	char	*s;

	digs = digits(n);
	s = malloc((digs + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	s[digs] = '\0';
	digs = digs - 1;
	while (digs >= 0)
	{
		s[digs] = n % 10 + 48;
		digs--;
		n = n / 10;
	}
	return (s);
}

static char	*negative(int n)
{
	int		digs;
	char	*s;

	digs = digits(n) + 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = malloc((digs + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	s[0] = '-';
	n = -n;
	s[digs] = '\0';
	digs = digs - 1;
	while (n >= 0 && digs >= 0)
	{
		s[digs] = n % 10 + 48;
		digs--;
		n = n / 10;
	}
	s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	if (n >= 0)
		return (positive(n));
	else
		return (negative(n));
}
