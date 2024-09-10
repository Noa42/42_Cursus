/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:21:38 by achacon-          #+#    #+#             */
/*   Updated: 2023/10/24 14:46:23 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;
	char	x;

	x = (unsigned char)c;
	i = ft_strlen(s);
	if (x == '\0')
	{
		result = (char *)&s[i];
		return (result);
	}
	while (s[i] != x && i > 0)
	{
		i --;
	}
	if (i == 0 && s[i] != x)
	{
		result = 0;
		return (result);
	}
	else
	{
		result = (char *)&s[i];
		return (result);
	}
}
