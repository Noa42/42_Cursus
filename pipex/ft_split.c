/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:19:06 by achacon-          #+#    #+#             */
/*   Updated: 2024/04/16 14:52:31 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	counter(char const *s, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			counter ++;
		while (s[i] != c && s[i] != '\0')
			i ++;
	}
	return (counter);
}

static char	*cut(char *beg, char *end)
{
	char	*slice;
	int		i;

	i = 0;
	while (&beg[i] != &end[0])
	{
		i++;
	}
	slice = malloc(sizeof(char) * (i + 1));
	if (slice == NULL)
		return (NULL);
	i = 0;
	while (&beg[i] != &end[0])
	{
		slice[i] = beg[i];
		i++;
	}
	slice[i] = '\0';
	return (slice);
}

static char	**erase(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
	return (NULL);
}

static char	**words(char **array, char c, const char *s)
{
	char	*beg;
	char	*end;
	int		i;

	i = 0;
	beg = (char *)&s[0];
	end = beg;
	while (*beg != '\0' && i < counter(s, c))
	{
		while (*beg == c && *beg != '\0')
			beg++;
		end = beg;
		while (*end != c && *end != '\0')
			end ++;
		array[i] = cut(beg, end);
		if (array[i] == NULL)
			return (erase(array, i - 1));
		i++;
		beg = end;
	}
	array[counter(s, c)] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = (char **)malloc((counter(s, c) + 1) * sizeof (char *));
	if (array == NULL)
		return (NULL);
	array = words(array, c, s);
	return (array);
}
