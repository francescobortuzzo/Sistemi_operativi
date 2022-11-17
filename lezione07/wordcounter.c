#include <stdio.h> // Funzioni di I/O dalla libreria standard
int main()
{
	long wc = 0;
	int whitespace = 0;
	for(char c = getchar(); c != EOF; c = getchar()) {
		if( ((c == ' ') || (c == '\n') || (c == '\t')) && !whitespace ){
			wc++;
			whitespace = 1;
		}
		else {
			whitespace = 0;
		}
	}
	printf("\n%ld\n", wc);
	return 0;
}
