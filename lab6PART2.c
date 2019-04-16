#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

sem_t inicio;
sem_t recurso_terminado;
int randomy;
pthread_mutex_t mutexThread;
int i;

int recurso;

void *thread(void *vargp){
	print("Se agregaron las funciones deTomas");
	printf("Thread creado correctamente\n");
	sem_wait(&inicio);


	
	int cantidadx = 12;
	int x;

	if(i == 12){
	
		for(x = 0; x < cantidadx; x++){
			sem_wait(&recurso_terminado);
		}
	}else{
		sem_post(&inicio);
	}


}

void *recursos(void *vargp){
	

	while(1){
		recurso++;
		if(recurso < randomy){
			printf("Semaforo creado correctamente (creo)\n");
			printf("Recurso Tomado\n");
			sleep(1);
		}
		recurso = 0;
		printf("se liberaron recursos\n");
		printf("Se esta esperando a que se libere un recurso\n");
		sem_wait(&recurso_terminado);
		
		pthread_mutex_lock(&mutexThread);
		printf("Thread trabajando\n");
		pthread_mutex_unlock(&mutexThread);
	}
	
}




int main(){
	
	printf("SORRY ESTO NO SE CONVERTIRA EN UN TEXTO\N");
	int cantidad = 12;
	int cantidad2 = 24;
	int i;
	randomy = rand()% 5;
	
	pthread_mutex_init(&mutexThread, NULL);


	sem_init(&inicio,0,1);
	pthread_t * thread_id = malloc(sizeof(pthread_t)*cantidad2);

	for(i = 0; i< cantidad; i++){
		printf("Creando thread: %d \n", i);
		pthread_create(&thread_id[i], NULL, thread, NULL);
		sleep(1);
	}

	for(i= cantidad; i< cantidad2; i++){
		pthread_create(&thread_id[i], NULL, recursos, NULL);
		sleep(1);
	}

	for(i = 0; i < cantidad2; i++){
		pthread_join(thread_id[i], NULL);
	}

	pthread_mutex_destroy(&mutexThread);
	sem_destroy(&inicio);
	sem_destroy(&recurso_terminado);
	
	return 0;
}

int decrease_count(int count){
	if(available_resources < cunt){
		return -1;
	}else{
		available_resources-= count;
		return 0;
	}
}

int increase_count(int count){

	available_resources += count;
	return 0;
}
