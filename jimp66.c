#include <stdio.h>  // wiadomo po co
#include <stdlib.h> // qsort
#include <string.h> // strstr

#define BUFSIZE 8192    // zakładamy, że linie będą krótsze niż 8kB

int
main( int argc, char **argv ) {
  int ile_linii;
	char buf[BUFSIZE];

    int opt = argc > 1? atoi(argv[1]): 0;

	char **str = malloc(argc * sizeof str);
    int s = 0;
    for(int i = 3; i<argc-2; i++)
    {
        str[s] = argv[i];
        s++;
    }

	FILE *in= argc > 2 ? fopen( argv[2], "r" ) : stdin;

	if( str == NULL ) {
		fprintf( stderr, "%s: błąd: proszę podac napis do wyszukiwania\n", argv[0] );
		return EXIT_FAILURE;
	}

	if( in == NULL ) {
		fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[2] );
		return EXIT_FAILURE;
	}

	ile_linii= 0;
    if(opt == 1)
    {
        while( fgets( buf, BUFSIZE, in ) != NULL ) {
            ile_linii++;
            for(int i = 0; i < s; i++)
            {
                
                if( strstr( buf, str[i] ) != NULL )
                    printf( "%s\n", buf );
                    printf("Numbe lini %d\n", ile_linii);
            }
        }
	}
	
	return EXIT_SUCCESS;
}
