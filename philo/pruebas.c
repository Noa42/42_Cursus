#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 0;
void *funcion()	{
	x = 2;
	printf("Hilo 1, x:%i\n", x);
	return(NULL);
}

void *funcion2()
{
	x = 3;
	printf("Hilo 2, x:%i\n", x);
	return(NULL);
}

int main(void)
{
	pthread_t hilo1;
	pthread_t hilo2;
	if(pthread_create(&hilo1,NULL, &funcion, NULL))
	{
		printf("Error creando el hilo1\n");
		return 1;
	}
	pthread_join(hilo1, NULL);
	sleep(3);
	if (pthread_create(&hilo2, NULL, &funcion2, NULL))
	{
		printf("Error creando el hilo2\n");
		return 1;
	}
	pthread_join(hilo2, NULL);
	//escribir la prueba los mutex
}