#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 0;
pthread_mutex_t mutex;

void *funcion1()	{

	for(int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		x++;
		pthread_mutex_unlock(&mutex);
	}
	return(NULL);
}

int main(void)
{
	pthread_t hilo1;
	pthread_t hilo2;
	pthread_mutex_init(&mutex, NULL);
	if(pthread_create(&hilo1,NULL, &funcion, NULL))
	{
		printf("Error creando el hilo1\n");
		return 1;
	}
	if (pthread_create(&hilo2, NULL, &funcion, NULL))
	{
		printf("Error creando el hilo2\n");
		return 1;
	}
	pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);
	printf("x:%i\n", x);
	pthread_mutex_destroy(&mutex);
}