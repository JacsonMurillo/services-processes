#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct Param{
    char caracter;
    int cantidad;
};
void *print(void *parameter) {
    struct Param *datos =(struct Param *) parameter;

    for (int i=0; i<datos->cantidad; i++)
        fputc(datos->caracter, stderr);

    return NULL;
}

int main(){

    pthread_t thread_id1, thread_id2;
    struct Param x = {'x', 20000};
    struct Param o = {'o', 50000};

    pthread_create(&thread_id1, NULL, &print, &x);
    pthread_create(&thread_id2, NULL, &print, &o);

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    printf("\n");

   return EXIT_SUCCESS;
}
