#include <stdio.h>  // wiadomo po co
#include <stdlib.h> // qsort
#include <string.h> // strstr

#define BUFSIZE 8192    // zakładamy, że linie będą krótsze niż 8kB

int main ( int argc, char **argv ) {
    int ile_linii;
    char buf[BUFSIZE];

    int opt = argc > 1? atoi(argv[1]): 0;

    FILE *in= argc > 2 ? fopen( argv[2], "r" ) : stdin;


    char **str = malloc(argc * sizeof str);
    int s = 0;
    int i;
    for(i =  3; i < argc; i++)
    {
        str[s] = argv[i];
        s++;
    }

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
                
                if( strstr( buf, str[i] ) != NULL ){
                    printf("Numer linii: %d\n", ile_linii - 1);
		    printf("%s", buf);
                }

            }
        }
    }

    if(opt == 0)
    {
        while( fgets( buf, BUFSIZE, in ) != NULL ) {
            int stat = 0;
	    ile_linii++;
            for(int i = 0; i < s; i++)
            {

                if( strstr( buf, str[i] ) != NULL ){
                    stat++;
                }
		if(stat == s){
			printf("numer linii: %d\n", ile_linii);
			printf("%s", buf);

                }
           }
   	 }
    }
	
	return EXIT_SUCCESS;
}
