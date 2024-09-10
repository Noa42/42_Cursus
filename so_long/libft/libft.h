/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/02/08 12:50:49 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					stack;

/**
 * @brief Convierte una string en un int. 
 * La string puede tener muchos espacios o carácteres de tabulación primero y un signo positivo o negativo al inicio del número.
 * Con la función spaces llega al indice en el que ya no hay espacios o carácteres de tabulación. Luego mira si hay signos.
 * Luego guarda el primer número en result y en cada iteración lo multiplica por 10 y le añade el nuevo número.
 * @param str 
 * @return int 
 */

int					ft_atoi(const char *str);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Rellena una posición de memoria con 0s
 * Con la posición del puntero parámetro llena hasta n de sus posiciones contiguas con 0s.
 * @param s 
 * @param n 
 */
void				ft_bzero(void *s, size_t n);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Devuelve 1 si el caracter es una letra (mayúscula o minúscula) o un número
 * @param c 
 * @return int 
 */
int					ft_isalnum(int c);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Devuelve 1 si es un caracter ascii (del 0 al 127)
 * @param c 
 * @return int 
 */
int					ft_isascii(int c);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Devuelve 1 si el caracter es un número
 * @param c 
 * @return int 
 */
int					ft_isdigit(int c);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Busca la aparición del carácter c en las primeras n posiciones de s
 * El caracter c se mete como un int y se castea a un unsigned char. Devuelve un puntero situado en la posición donde ecuentra c.
 * @param s 
 * @param c 
 * @param n 
 * @return void* 
 */
void				*ft_memchr(const void *s, int c, size_t n);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Copia n bloques de memoria de src en dst
 * Trata los bloques como unsigned char
 * @param dst 
 * @param src 
 * @param n 
 * @return void* 
 */
void				*ft_memcpy(void *dst, const void *src, size_t n);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Copia len bytes de memoria de src a dst (no destructivo)
 * Copia las posiciones desde el final si dst está después de src. Copia a la posicíon anterior (len -1) para tener acceso al source
 * Si dst va antes que src lo hace desde la primera posición en adelante.
 * @param dst 
 * @param src 
 * @param len 
 * @return void* 
 */
void				*ft_memmove(void *dst, const void *src, size_t len);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Compara bloques de memoria
 * Compara hasta n posiciones (da igual si hay nulls). Castea a unsigned char.
 * Devuelve la diferencia del caracter diferente s2 - s1.
 * Si son iguales hasta len deveuelve 0.
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int					ft_memcmp(const void *s1, const void *s2, size_t n);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Rellena los primeros n bloques de memoria de b en el carácter c
 * 
 * @param b 
 * @param c 
 * @param len 
 * @return void* 
 */
void				*ft_memset(void *b, int c, size_t len);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Devuelve 1 si el carácter es una letra
 * @param c 
 * @return int 
 */
int					ft_isalpha(int c);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Devuelve 1 si el carácter es imprimible (entre el 32 y el 126)
 * @param c 
 * @return int 
 */
int					ft_isprint(int c);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Devuelve la posición de memoria donde encuentra por primera vez c en s desde el principio
 * Si c el \0 devuelve la posición del nulo, es decir, lo busca también.
 * Si no esta c en s devuelve NULL.
 * @param s 
 * @param c 
 * @return char* 
 */
char				*ft_strchr(const char *s, int c);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Concatena cadenas hasta el tamaño datasize, devuelve la longitud de la cadena nueva
 *  Primero comprueba que el datasize no sea 0 o más largo que la len de destino. En ese caso devuelve la len de src + el dst
 * Concatena hasta el nulo o el dstsize -1 porque le añade el nulo.
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t 
 */
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Copia dst a la src hasta dstsize
 * Si dstsize es 0 devuelve la len de la src.
 * Recorre hasta el dstsize -1 porque le pone el nulo manualmente.
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t 
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Devuelve la longitud de la cadena
 * Recorre hasta el caracter nulo y lo cuenta pero como está indexada en 0 este da las posiciones en total de la cadena.
 * Ej: ft_strlen("HHH") = 3, la funcion cuenta hasta la posición 2 pero igual le suma al contador y el resultado es 3.
 * el nulo está en la posición [ft_strlen()].
 * @param s 
 * @return size_t 
 */
size_t				ft_strlen(const char *s);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Compara hasta n carácteres entre s1 y s2
 * Devuelve la diferencia entre carácteres de la posición diferente s1 -s2.
 * Se diferencia de memcmp en que esta funcion para si encuentra NULL mientras que memcmp no lo hace.
 * Esto es porque memcmp se usa para comparar posiciones de memoria en general y strncmp para strings concretamente.
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int					ft_strncmp(const char *s1, const char *s2, size_t n);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Devuelve la posición de memoria de donde esta needle dentro de haystack
 * Si no needle está vacía devuelve haystack
 * Si needle no está en haystack devuelve NULL
 * 
 * @param haystack 
 * @param needle 
 * @param len 
 * @return char* 
 */
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Devuelve la posición de memoria doende encuentra por primera vez c en s desde el final
 * Busca desde el len de s hasta el 0. Si busca el \0 lo va a encontra lo primero de todo.
 * Si no esta c en s devuelve NULL.
 * @param s 
 * @param c 
 * @return char* 
 */
char				*ft_strrchr(const char *s, int c);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Convierte todos los carácteres a minúsculas
 * @param c 
 * @return int 
 */
int					ft_tolower(int c);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Convierte todos los carácteres a mayúsculas
 * 
 * @param c 
 * @return int 
 */
int					ft_toupper(int c);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Aloca memoria y la llena de 0s
 * Usa la bzero para rellenar lo que ha alocado de 0s.
 * @param count 
 * @param size 
 * @return void* 
 */
void				*ft_calloc(size_t count, size_t size);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Hace una copia de s1 en un espacio alocado y devuelve el puntero a la copia
 * Hace malloc de strlen(s) + 1 para ponerle el NULL.
 * Recorre el bucle hasta el strlen(s1) lo que copia el NULL de la ultima posición (porque indexadas en 0)
 * @param s1 
 * @return char* 
 */
char				*ft_strdup(const char *s1);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Aloca una cadena sub donde guarda una subcadena de s, desde el indice start hasta len posiciones más
 * Si el start es mayor que la strlen(s) devuelve NULL
 * Si start + len se sale de la strlen(s) hace que la len sea el máximo (strlen(s) - start) y llega hasta el final de la cadena
 * Le pone el NULL al final.
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char				*ft_substr(char const *s, unsigned int start, size_t len);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Aloca una nueva cadena resultado de concatenar s2 a s1.
 * Pimero copia la cadena s1 sin incluir el NULL y luego le mete la s2.
 * Al final del todo le mete un NULL.
 * @param s1 
 * @param s2 
 * @return char* 
 */
char				*ft_strjoin(char const *s1, char const *s2);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Devuelve una cadena resultado de quitar todos los carácteres del set desde ambos extremos
 * Recorre la cadena desde el pricipio hasta el final y al revés ccon la función match para conseguir los indices
 * Después usa la substr para alocar la nueva cadena y copiarla.
 * Si el set está vacío devuelve una copia de la cadena s1 hecha con strdup
 * Si s1 está vacía hace un strdup(""), es decir aloca una nuva cadena pero vacía
 * @param s1 
 * @param set 
 * @return char* 
 */
char				*ft_strtrim(char const *s1, char const *set);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Te genera una array de cadenas que contiene los fragmentos de la cadena s separados por uno o varios carácteres c
 * Primero cuenta cuantos fragmentos hay con counter para poder alocar el array. Además aloca +1 porque el ultimo puntero debe apuntar a NULL.
 * Segundo llama a words que calcula los indices de cada fragmentos y se los pasa a cut que hace la subacadena (la aloca y además le incluye el NULL) y se lo mete la psoición i del array.
 * Si por lo que sea cut no puede alocar llama a la función erase que borra todo el array y lo libera (tanto cada posición como el doble puntero)
 * @param s 
 * @param c 
 * @return char** 
 */
char				**ft_split(char const *s, char c);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Convierte un int en una cadena
 * Primero mira si el int es negativo o positio y llama a negative o a positive.
 * Negative maneja el caso de en el que haya que alocar una posición más porque hay que incluir el -.
 * Ambas funciones miran cuantos dígitos tiene el n (su valor absoluto) y allocan memoria para estos (el negative incluye el -)
 * Luego va desde el final del número hasta el primer dígito dividiendo entre 10 y quedandose con el resto de la división. 
 * @param n 
 * @return char* 
 */
char				*ft_itoa(int n);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Aloca una copia de s pero después de pasarle la función f a cada carácter
 * la f toma como parámetros el indice i como la s[i].
 * @param s 
 * @param f 
 * @return char* 
 */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Le aplica la función f a cada carácter de la cadena s
 * Provoca los cambios en la cadena original.
 * La diferencia con strmapi es que no aloca una nueva cadena sino que cambia la original.
 * @param s 
 * @param f 
 */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Envía un carácter en el file descriptor elegido
 * El 0 es para la entrada estándar
 * El 1 es para la salida estándar
 * El 2 es para la salida de errores
 * fd puede ser el puntero a un archivo abierto, imprimiría ahí.
 * @param c 
 * @param fd 
 */
void				ft_putchar_fd(char c, int fd);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Envía una cadena en el file descriptor elgido
 * El 0 es para la entrada estándar
 * El 1 es para la salida estándar
 * El 2 es para la salida de errores
 * fd puede ser el puntero a un archivo abierto, imprimiría ahí.
 * @param s 
 * @param fd 
 */
void				ft_putstr_fd(char *s, int fd);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Envía la cadena el el file descriptor pero ademas imprime un '\n'
 * Usa putstr y luego putchar de '\n'
 * El 0 es para la entrada estándar
 * El 1 es para la salida estándar
 * El 2 es para la salida de errores
 * fd puede ser el puntero a un archivo abierto, imprimiría ahí.
 * @param s 
 * @param fd 
 */
void				ft_putendl_fd(char *s, int fd);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Imprime un int en el file desciptor elegido
 * Si el int es negativo primero imprime un '-' y lo pasa a positivo
 * Luego usa recursión a la que le manda una copia del nb cada vez y en la que va dividiendo entre 10. Al final de la función se queda con el módulo.
 * @param nb 
 * @param fd 
 */
void				ft_putnbr_fd(int nb, int fd);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Crea un nuevo nodo
 * @param content 
 * @return t_list* 
 */
stack				*ft_lstnew(void *content);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Añade un nodo al principio de la lista
 * Hace que el next de new apunte al nodo **lst
 * @param lst 
 * @param new 
 */
void				ft_lstadd_front(stack **lst, stack *new);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Devuelve cuántos nodos tiene la lista
 * Recorre hasta que lst -> new es NULL.
 * @param lst 
 * @return int 
 */
int					ft_lstsize(stack *lst);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Recorre una lista y devuelve un puntero al último nodo
 * @param lst 
 * @return t_list* 
 */
stack				*ft_lstlast(stack *lst);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Añade el nodo al final de la lista
 * Lleva un puntero al final de la lista con lstlast y ahi añade el nodo
 * @param lst 
 * @param new 
 */
void				ft_lstadd_back(stack **lst, stack *new);
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Borra el nodo y usa la función del para borrar también el content del nodo
 * Lo desaloca con free.
 * @param lst 
 * @param del 
 */
void				ft_lstdelone(stack *lst, void (*del)(void *));
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Borra toda una lista y utiliza la función del para el content de cada nodo
 * Va avanzando con el **lst pero en cada paso hace que un puntero ptr se quede en el anterior yen lo usa para hacer el free y el del.
 * En cada iteración vuelve a apuntar ptr a lst y mueve lst al sigueinte y así lo hace.
 * @param lst 
 * @param del 
 */
void				ft_lstclear(stack **lst, void (*del)(void *));
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Recorre toda la lista y aplica la función del al content de cada nodo
 * Lo hace hasta que encuentra el NULL y vuelve a hacer f(lst -> content) para el último.
 * @param lst 
 * @param f 
 */
void				ft_lstiter(stack *lst, void (*f)(void *));
/*-------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Aloca una nueva lista y copia lst pero con el resultado de aplicar la f a cada content
 * 1º Comprueba crea dos punteros a nodos y y los inicializa en NULL. En node vamos a guaradar el nodo creado en cada iteración y el newhead en el que se va a quedar al principio de la lista para luego usar el lstadd_back.
 * 2º Comprueba si alguno de los punteros que entran como parámetros apuntan a NULL.
 * 3º En cada iteración crea el nodo con lstnew y su content lo apunta a NULL (para que no hay que borra luego con del si la alocación del nodo falla).
 * 4º Después comprueba si ha podido alocar el nodo y si no usa lstclear para liberar la lista entera
 * 5º Le mete el content al nodo creado pasandole la función f.
 * 6º Lo añade a la lista con lstadd_back de &newhead
 * Al final devuelve newhead que sigue apuntando al principio de la lista.
 * @param lst 
 * @param f 
 * @param del 
 * @return t_list* 
 */
stack				*ft_lstmap(stack *lst, void *(*f)(void *),
						void (*del)(void *));
/*-------------------------------------------------------------------------------------------------------------------------*/

#endif