/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:21:38 by achacon-          #+#    #+#             */
/*   Updated: 2023/10/16 14:15:39 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match(char c, const char *set)
{
	int	i;
	int	match;

	match = 0;
	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
		{
			match = 1;
			break ;
		}
		i++;
	}
	return (match);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ini;
	size_t	fin;
	char	*result;
	size_t	len;

	if (ft_strlen(set) == 0)
		return (ft_strdup((char *)s1));
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	ini = 0;
	fin = ft_strlen(s1) - 1;
	while (s1[ini] != '\0' && match(s1[ini], set) == 1)
		ini++;
	while (fin >= ini && match(s1[fin], set) == 1)
		fin --;
	len = (fin + 1) - ini;
	result = ft_substr(s1, ini, len);
	if (result == NULL)
		return (NULL);
	return (result);
}
