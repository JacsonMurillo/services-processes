#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

void spawn(const char *command, char *args[])
{
	pid_t hijid = fork();
	if (!hijid)
	{
		execvp(command, args);
		fprintf(stderr, "Opps. Somethind went wrong \n");
	}
}
int main(int argc, char *argv[])
{
	int salida;
	spawn("ls", argv);

	printf("Waiting for my son \n");

	wait(&salida);
	printf("Game over\n");

	return 0;
}