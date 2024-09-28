#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *funcion()	{

	int *resultado_hilo = malloc(sizeof(int));
	*resultado_hilo = 2;
	return((void*)resultado_hilo);
}
int main (void)
{
	pthread_t hilo;
	int *resultado_main;
	if(pthread_create(&hilo, NULL, &funcion, NULL))
	{
		printf("Error creando el hilo\n");
		return 1;
	}
	pthread_join(hilo, (void**)&resultado_main);
	printf("Hilo 1, resultado_main:%i\n", *resultado_main);
	free(resultado_main);
}