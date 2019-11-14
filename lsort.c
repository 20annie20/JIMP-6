#include <stdio.h> 
#include <stdlib.h> //qsort, makra 
#include <string.h> //strdup?, strcpy(w warunku?)

#define BUFSIZE 8192
#define MAXLINES 1000

//zwracanie info dla qsorta
int linecmp( const void *a, const void *b){
	char **ca = (char**)a;
	char **cb = (char**)b;
	return strcmp( *ca, *cb );
}

int main(int argc, char**argv){
	//jesli za malo danych wejsciowych
	if(argc < 2){
		printf("prosze wprowadzic nazwe pliku oraz numery linii oddzielone spacjami");
		return EXIT_FAILURE;
	}


	//otwieranie pliku
	FILE *in = argc > 1 ? fopen( argv[1], "r") : stdin;
	if( in == NULL){
		fprintf( stderr," %s: blad odczytu pliku %s\n", argv[0], argv[1]);
		return EXIT_FAILURE;
	}

	char *dst[MAXLINES];//tablica do ktorej zapiszemy
	int ctr = 0;
	int i = 2; //tutaj definiowane, zeby while go nie resetowalo - nr argv - nr linii do zapisania
	char buf[BUFSIZE];
	int pos = 0;//umozliwia dobre zmiany indeksu przy kopiowaniu do dst
	int nrline;

	//zapisanie wybranych linii do tablicy destin
	while( fgets( buf, BUFSIZE, in) != NULL){
		if( i == argc){
			printf("koniec argumentow\n");
			break; 
		}

		if(ctr < MAXLINES){
		
			if( (dst[pos] = malloc( (strlen(buf)+1) * sizeof( char) )) == NULL ){
				fprintf( stderr, "%s: blad zbyt wiele danch\n", argv[0] );
				return EXIT_FAILURE;
			}
			nrline = atoi(argv[i]) - 1;//zbadac opcje znakow
	      		if(ctr == nrline){
			       	strcpy( dst[pos], buf );
				i++;
				pos++;
	       		}
			ctr++;
		}

		else {
			 fprintf( stderr, "%s: blad: zbyt wiele linii wejscia\n", argv[0] );
			 return EXIT_FAILURE;
		 }
	
	 }
	qsort( dst, pos, sizeof *dst, linecmp);
	int j; //i juz wykorzystane wczesniej
	for( j=0; j < pos; j++)
		printf("%s", dst[j]);

	return EXIT_SUCCESS;
 }
