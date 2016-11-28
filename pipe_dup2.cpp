#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main ()
{
	int fds[2];
	pid_t pid;

	pipe (fds);

	pid = fork();
	if(pid == (pid_t) 0) {
		close(fds[1]);
		dup2 (fds[0], STDIN_FILENO);
		execlp("sort", "sort", 0);
	}
	else{
		FILE* strem;
		close(fds[0]);
		stream = fdopen (fds[1], "w");
		fprintf (stream, "this is a test.\n");
		fprintf (stream,"Hello, world.\n");
		fprintf (stream, "my dog has fleas.\n");
		fprintf (stream, "this program is great.\n");
		fprintf (stream, "One fish, two fish.\n");
		fflush(stream);
		close(fds[1]);

		waitpid (pid, NULL, 0);
	}
	return 0;
}
