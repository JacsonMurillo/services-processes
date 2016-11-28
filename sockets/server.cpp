#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, const char *argv[]){

	struct sockaddr_un s_filedata;
	s_filedata.sun_family = AF_LOCAL;//AFLOCAL indica q es un fichero
	strcpy(s_filedata.sun_path, argv[1]);

	/* crear el socket, decir la conexion(PF_UNIX(PF_LOCAL), tipo de conexion, la manera de conexion  0 es eligelo tu*/
	socket_fd = socket(PF_UNIX,CONNECTION,0 );
	bind(socket_fd,&s_fileadata, SUN_LEN(&s_filedata) );/*SUN_LEN es una macro*/
	listen(socket_fd,5);//escuchar y tiene un limite de 5 conexiones

	do{
		struct sockaddr_un who_are_you;//
		sockle_t who_len;//longitud

		int new_connection_fd = accept(socket_fd, &who_are_you, &who_len);

		talk_to(new_connection_fd);//habla con la conexion
		close(new_connection_fd);
	}while(1);
	close(socket_fd);
	unlink(argv[1]; 

			return EXIT_SUCCESS;
			}

