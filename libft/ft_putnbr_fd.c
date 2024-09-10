/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:21:08 by achacon-          #+#    #+#             */
/*   Updated: 2023/10/25 15:38:25 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	intochar(int x)
{
	char	c;

	c = x + 48;
	return (c);
}

static int	digits(int n)
{
	int	result;

	result = 0;
	while (n > 0)
	{
		result++;
		n = n / 10;
	}
	return (result);
}

void	ft_putnbr_fd(int nb, int fd)
{
	char			char_print;
	int				num_print;
	unsigned int	factor;
	unsigned int	nb_1;

	factor = 10;
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (nb < 0)
		{
			write(fd, "-", 1);
			nb = nb * (-1);
		}
		nb_1 = nb;
		if (digits(nb_1) > 1)
		{
			ft_putnbr_fd(nb_1 / factor, fd);
		}
		num_print = nb_1 % factor;
		char_print = intochar(num_print);
		ft_putchar_fd(char_print, fd);
	}
}
