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

	//wpisanie pliku do tablicy kopia
	char *kopia[MAXLINES];
  	int ile_linii;
	char buf[BUFSIZE];

	int ile_inii= 0;
	while( fgets( buf, BUFSIZE, in ) != NULL ) {
		if( ile_linii < MAXLINES ) {
			if( (kopia[ile_linii]= malloc( (strlen(buf)+1) * sizeof( char ) )) == NULL ) {
				fprintf( stderr, "%s: błąd: zbyt wiele danych (brak pamięci)\n", argv[0] );
				return EXIT_FAILURE;
			}
			strcpy( kopia[ile_linii], buf );
			ile_linii++;
		} else {
			fprintf( stderr, "%s: błąd: zbyt wiele linii wejścia\n", argv[0] );
			return EXIT_FAILURE;
		}
	}

	/*zasadnicza czesc do przerobki
	*zapisac argumenty do tablic(tablicy tablic?)
	*kolejno wywolywac je do porownania z lines
	*jesli pattern wystapi, wpisac linie do dst
	nested loop will do!*/

	char *ptr;
	char *pattern = argv[2];
	int i;
	char *ptr_tab[ile_linii];
	for(i = 0; i < ile_linii; i++){
		ptr = strstr(kopia[i] ,pattern);
		ptr_tab[i] = ptr;
	}

	int j; 
	for( j=0; j < ile_linii; j++){
		if(ptr != NULL)
			printf("%s", kopia[(int)ptr]);
        }
	return EXIT_SUCCESS;
 }
