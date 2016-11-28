#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 0x100
#define MAX 0x1000

sig_atomic_t hijo_vivo = 0;

void clean_child(int sig_number){
    int exit_status;
   
    wait(&exit_status);
    hijo_vivo = 0;
}
void spawn(char *argv[]){
    pid_t child_pid =fork();
   if(child_pid){
       hijo_vivo = 1;
      return;
    }
//Only the child is running
    execv(argv[0], argv);
    fprint(stderr, "%s never was up. Rerturning \n", argv[0]);
    abort();
}

int main(){
    int i=0;
    char buffer[MAX];
    char *parse=buffer;
    char *command[n];

    struct sigaction conf_hadler;
    bzero(&conf_handler, sizeof(conf_handler));
    conf_handler.sa_handler = &clean_child;
    sigaction(SIGCHLD, &conf_handler, NULL); 

    printf("command :");
    fgets(buffer, MAX, stdin);

    while ((command[i++]= strtok(buffer, " ")) !=NULL);

        parse =NULL;

    printf("Wainting for %s to end.\n", command[0]);
    spawn(command);
  
    while (hijo_vivo)
         sleep(1);

    printf("%s is over. \n", command[0]);
    return EXIT_SUCCESS;

}
