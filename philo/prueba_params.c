#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *rutina(int arg)	{

	int *resultado_hilo = malloc(sizeof(int));
	*resultado_hilo = *(int*)arg + 2;
	return((void*)resultado_hilo);
}
int main (void)
{
	pthread_t hilo;
	int *resultado_main;
	int num = 2;
	if(pthread_create(&hilo, NULL, &rutina, &num))
	{
		printf("Error creando el hilo\n");
		return 1;
	}
	pthread_join(hilo, (void**)&resultado_main);
	printf("Resultado_main:%i\n", *resultado_main);
	free(resultado_main);
}