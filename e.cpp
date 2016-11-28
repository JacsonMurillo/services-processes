#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "interfaz.h"

int factorial(int n){

	return n==0 ? 1 : n * factorial(n-1);}


double e (double error){
	double result =0;
			termino;

	// el numero e es  1/factorial(0) +1/factorial(1) + 1/factorial(2)+.....
	/*do{

		termino= 1. /factorial(i);
		result += termino; 

	}while( rtermino> error)*/

	for (int i = 0; 
		(termino = 1. / factorial(i)) > error;
		 i++,result += termino);
		
		return result;
	
	
}

int main(int argc, char const *argv[]){

	double error;

	if(argc <2)
		printf_usage(argv[0]);
	error= atof(argv[1]);

	printf("e = %lf", e(error) );

	return 0;


}
