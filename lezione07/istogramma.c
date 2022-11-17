#include <stdio.h> // Funzioni di I/O dalla libreria standard
int main()
{
	int whitespace = 0;
	for(char c = getchar(); c != EOF; c = getchar())
		if( !((c == ' ') || (c == '\n') || (c == '\t')) ){
			printf("-");
			whitespace = 0;
		} else if( ((c == ' ') || (c == '\n') || (c == '\t')) && !whitespace ){
			printf("\n");
			whitespace = 1;
		}
	return 0;
}
