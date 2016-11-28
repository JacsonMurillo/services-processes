#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

	/* */

void writer(const char *mssg, int times, FILE *out_tube) {
    const char *letter;
    for (letter=mssg; times>0; --times, letter=mssg)
        while (*letter != '\0'){
            fputc(*letter, out_tube);//lo pasa a la tuberia
            fputc(*letter, stderr);//Salida de errores
            fflush(out_tube);//Limpia el buffer
            letter++;
            usleep(100000);
        }
}

void reader(FILE *in_tube) {
    char c;
	/*lee de principio a fin la tuberia, y si a hay error */
    while (!feof(in_tube) && !ferror(in_tube) && (c=fgetc(in_tube))){
        fputc(c, stdout);//consigue un caracte del in_tube
        fputc('\a', stdout);
        fflush(stdout);
    }
}

int main(int argc, char *argv[]) {

    int fds[2];
	//Crea un tuberia q si es igual a -1 no se puede abrir fichero
    if (pipe(fds) == -1){
        fprintf(stderr, "Couldn't open file.\n");
        return EXIT_FAILURE;
    }
	/*crear proceso hijo*/
    pid_t child_pid = fork();

	//Cierra la copia de escritura
    if (child_pid) {
        close(fds[0]);// covierte a un archivo objeto y escribi en el
        writer("The World is a Vampire.\n", 5, fdopen(fds[1], "w"));
        close(fds[1]);
    } else {
        close(fds[1]);//covierte a archivo objetc y lo lee
        reader(fdopen(fds[0], "r"));
        close(fds[0]); // cierra la copia
    }

    return EXIT_SUCCESS;
}
