/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:19:06 by achacon-          #+#    #+#             */
/*   Updated: 2023/10/15 18:17:47 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(((ft_strlen(s1)) + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (i <= ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}
