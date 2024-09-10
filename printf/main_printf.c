/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:23:48 by achacon-          #+#    #+#             */
/*   Updated: 2023/11/06 13:54:30 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	main(void)
{
	/*-------------TEST GENERAL---------------	
	int result;
	int ft_result;
	int i = 2;
	unsigned int u = 34;
	char c = 'a';
	char *s = "Hola";
	int x = 255;
	void *p;
	p = &x;
	ft_result = ft_printf("Mia - Prueba: %% // El int es:%i // El unsigned es %u // El char es:%c // La string es %s // El hex es: %x // El HEX es:%X // La dire es: %p // El d es: %d\n", i, u, c, s, x, x, p, x);
	result = printf("Lib - Prueba: %% // El int es:%i // El unsigned es %u // El char es:%c // La string es %s // El hex es: %x // El HEX es:%X // La dire es: %p // El d es: %d\n", i, u, c, s, x, x, p, x);
	printf("\nprintf: %i\nft_printf: %i\n", result, ft_result);
	*/
	/*--------------TEST %%-------------------	
	int result;
	int ft_result;
	
	result = printf("Lib - Esto sale %%%%%%%%\n");
	ft_result = ft_printf("Mia - Esto sale %%%%%%%%\n");
	printf("\nprintf: %i\nft_printf: %i\n", result, ft_result);
*/

	/* -------------TEST de %c---------------	
	int result;
	int ft_result;
	char a;

	a = 'a';
	ft_result = ft_printf("Mia - El numero es: %c\n", a);
	result = printf("Lib - El numero es: %c\n", a);
	printf("printf: %i\nft_printf: %i\n", result, ft_result);
	*/

	/* -------------TEST de %i---------------
	int result;
	int ft_result;
	int	numero;

	numero = -83648;
	ft_result = ft_printf("Mia - El numero es: %i\n", numero);
	result = printf("Lib - El numero es: %i\n", numero);
	printf("printf: %i\nft_printf: %i\n", result, ft_result);
*/

	/* -------------TEST de %d---------------		
	int result;
	int ft_result;
	int	numero;

	numero = -1;
	result = printf("Lib - El numero es: %d\n", numero);
	ft_result = ft_printf("Mia - El numero es: %d\n", numero);
	printf("printf: %i\nft_printf: %i\n", result, ft_result);
*/

	/* -------------TEST de %u---------------		
	int 			result;
	int 			ft_result;
	unsigned int	numero;

	numero = -1;
	result = printf("Lib - El numero es: %u\n", numero);
	ft_result = ft_printf("Mia - El numero es: %u\n", numero);
	printf("printf: %i\nft_printf: %i\n", result, ft_result);
*/

	/* -------------TEST de %s---------------
	int result;
	int ft_result;
	char	*s;

	s = "Hello world!";
	result = printf("Lib - El numero es: %s\n", s);
	ft_result = ft_printf("Mia - El numero es: %s\n", s);
	printf("printf: %i\nft_printf: %i\n", result, ft_result);
	*/

	/* -------------TEST de %x---------------*/
	int result;
	int ft_result;
	int	hexa;

	hexa = 268;
	ft_result = ft_printf("Mia - El numero es: %i, el hexa es: %x\n", hexa, "z");
	result = printf("Lib - El numero es: %i, el hexa es: %x\n", hexa, hexa);
	ft_printf("printf: %i\nft_printf: %i\n", result, ft_result);
	

	/* -------------TEST de %X---------------	
	int result;
	int ft_result;
	int	hexa;

	hexa = 268;
	ft_result = ft_printf("Mia - El numero es: %i, el hexa es: %x\n", hexa, hexa);
	result = printf("Lib - El numero es: %i, el hexa es: %x\n", hexa, hexa);
	ft_printf("printf: %i\nft_printf: %i\n", result, ft_result);
	*/

	/* -------------TEST de %p---------------
	int	*ptr;
	int	x;
	int result;
	int ft_result;

	ptr = &x;
	*ptr = 3;
	result = printf("Lib - La dirección del puntero es %p\n", (void *)ptr);
	ft_result = ft_printf("Mia - La dirección del puntero es %p\n", (void *)ptr);

	ft_printf("printf: %i\nft_printf: %i\n", result, ft_result);

	result = printf("Lib - La dirección del puntero es %p\n", (void *)LONG_MIN);
	ft_result = ft_printf("Mia - La dirección del puntero es %p\n", (void *)LONG_MIN);

	ft_printf("printf: %i\nft_printf: %i\n", result, ft_result);
	*/
}