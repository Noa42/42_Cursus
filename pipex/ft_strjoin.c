/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:19:06 by achacon-          #+#    #+#             */
/*   Updated: 2024/04/16 15:06:39 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	size1;
	size_t	size_total;
	size_t	i;
	size_t	j;

	size1 = ft_strlen(s1) - 1;
	size_total = size1 + ft_strlen(s2);
	dest = malloc((size_total + 2) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	j = 0;
	while (i <= size1 && s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (i + j <= size_total && s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
