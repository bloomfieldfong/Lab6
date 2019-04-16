#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

sem_t mutex;

void *thread(void *vargp){

	printf("se creao un bello thread");
	sem_wait(&mutex);
	printf("Entro al semaforo\n");

	printf("Salio del semaforo\n");
	sem_post(&mutex);
}


int main(){

	int cantidad = 10;
	int i;
	pthread_t * thread_id = malloc(sizeof(pthread_t)*cantidad);

	for(i = 0; i< cantidad; i++){
		sem_init(&mutex,0,1);
		pthread_create(&thread_id[i], NULL, thread, NULL);
		pthread_join(thread_id[i], NULL);
	}

	return 0;
}
