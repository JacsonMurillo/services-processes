#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <malloc.h>

void* print(void *){
    for(int i= 0; i<100; i++){
       
      printf("%s",i)
    }
    }

int main(){

    pthread_t hilo1;
    pthread_create(&hilo1, NULL,print ,NULL);
    pthread_t hilo2;
    pthread_create(&hilo2, NULL,print ,NULL);
  
    pthread_join(hilo1,NULL);
    pthread_join(hilo2, NULL);




    return EXIT_SUCCESS;

}
