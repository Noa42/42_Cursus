/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:16:53 by achacon-          #+#    #+#             */
/*   Updated: 2023/12/17 11:30:46 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	count;

	count = 0;
	if (s == NULL)
		return (0);
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

	size1 = ft_strlen(s1);
	size_total = size1 + ft_strlen(s2);
	dest = malloc((size_total + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < size1 && s1[i] != '\0')
		dest[i] = s1[i];
	while (i + j < size_total && s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	free (s1);
	return (dest);
}

int	ft_nl(char *s)
{
	int	i;

	i = 0;
	if (!s || s == NULL)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i ++;
	}
	return (-1);
}

char	*ft_first_line(char *s)
{
	char	*result;
	int		len;

	if (s == NULL || ft_strlen(s) == 0)
	{
		return (NULL);
	}
	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	result = malloc(sizeof(char) * len + 2);
	if (result == NULL)
	{
		free (result);
		return (NULL);
	}
	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
	{
		result[len] = s[len];
		len ++;
	}
	result[len] = s[len];
	result[len + 1] = '\0';
	return (result);
}

char	*ft_substr(char *s, unsigned int start, size_t len)

{
	char	*sub;
	size_t	i;

	if (start > ft_strlen(s))
		len = 0;
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (0);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	free (s);
	return (sub);
}
