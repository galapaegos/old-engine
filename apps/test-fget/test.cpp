#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	FILE *stream;
	char line[100];

	if( (stream = fopen( "test.scene", "r" )) != NULL )
	{
		while( fgets( line, 100, stream ) != NULL)
			printf( "%s", line);
		fclose( stream );
	}

	return 0;
}