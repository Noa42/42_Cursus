/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_getnextline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:10:27 by achacon-          #+#    #+#             */
/*   Updated: 2023/12/13 12:32:46 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	/* TEST strjoin	
	char *s1;
	s1 = NULL;
	printf("%zu\n", ft_strlen(s1));
	char *s2 = "Hola";
	s1 = ft_strjoin(s1, s2);
	printf("%s\n", s1);
	s1 = ft_strjoin(s1, "-Adios");
	printf("%s\n", s1);
*/
	/* TEST GENERAL	*/
	int	fd;
	fd = open(argv[argc - argc + 1], O_RDONLY);
	fd = 1000;
	printf("1: %s", get_next_line(fd));
	printf("2: %s", get_next_line(fd));
	printf("3: %s", get_next_line(fd));
	printf("4: %s", get_next_line(fd));
	printf("5: %s", get_next_line(fd));
	printf("6: %s", get_next_line(fd));
	printf("7: %s", get_next_line(fd));
	close(fd);
}
