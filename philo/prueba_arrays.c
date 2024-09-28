#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int x = 0;
pthread_mutex_t mutex;

void *funcion()	{

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
	pthread_t *array = malloc(4 * sizeof(pthread_t));
	pthread_mutex_init(&mutex, NULL);
	int i = 0;
	while (i < 4)
	{
	if (pthread_create(&array[i],NULL, &funcion, NULL) != 0)
	{
		printf("Error creando el hilo1\n");
		return 1;
	}
		printf("Hilo %i creado\n", i);
		i++;
	}
	i = 0;
	while(i < 4)
		{
		if (pthread_join(array[i], NULL) != 0)
			{
				printf("Error cerrando\n");
				return 1;
			}
			printf("Hilo %i cerrado\n", i);
			i++;
		}
	printf("x:%i\n", x);
	pthread_mutex_destroy(&mutex);
}