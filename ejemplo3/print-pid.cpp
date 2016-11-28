#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	printf("the process ID is %d\n", (int) getpid());
	printf("the parent process ID is %d\n", (int) getppid());
	return 0;
}