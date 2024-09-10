/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:19:01 by achacon-          #+#    #+#             */
/*   Updated: 2023/11/06 12:18:29 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		i_print(long long nb);
int		u_print(long long u);
int		p_print(void *ptr);
int		c_print(char a);
int		s_print(char *s);
int		x_print(long long x, int cases);
int		ft_printf(char const *s, ...);
int		nbr_base(long long x, char *base);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
size_t	ft_strlen(const char *s);

#endif