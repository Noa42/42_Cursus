/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:19:06 by achacon-          #+#    #+#             */
/*   Updated: 2023/10/16 13:18:37 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
