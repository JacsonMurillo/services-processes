#include<stdio.h>
#include<stdlib.h>
#include<time.h>

    void *funcion_cronometro(void *);
int main(){

    pthread_t thread1_id;
    phtread_t thread2_id;

    pthread_create(&thread1_id, NULL, funcion_cronometro, NULL);
    pthread_create(&

    void 

    return EXIT_SUCCESS;
}
