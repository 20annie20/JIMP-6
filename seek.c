#include <stdio.h> 
#include <stdlib.h> // makra 
#include <string.h> // strstr

#define BUFSIZE 8192
#define MAXLINES 1000

int main(int argc, char**argv){
	if(argc < 2){
		printf("prosze wprowadzic nazwe pliku oraz sekwencje znakow do odszukania");
		return EXIT_FAILURE;
	}


	//otwieranie pliku
	FILE *in = argc > 1 ? fopen( argv[1], "r") : stdin;
	if( in == NULL){
		fprintf( stderr," %s: blad odczytu pliku %s\n", argv[0], argv[1]);
		return EXIT_FAILURE;
	}

	/*zasadnicza czesc do przerobki
	*zapisac argumenty do tablic(tablicy tablic?)
	*kolejno wywolywac je do porownania z lines
	*jesli pattern wystapi, wpisac linie do dst)*/

	int j; 
	for( j=0; j < ; j++)
		printf("%s", dst[j]);

	return EXIT_SUCCESS;
 }
