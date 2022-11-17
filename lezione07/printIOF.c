#include <stdio.h> // Funzioni di I/O dalla libreria standard
int main()
{
	long nc = 0;
	for(char c = getchar(); c != EOF; c = getchar()) {
		if((c == '\n') || (c == '\t') || (c == ' ')) {
			++nc;
		}
	}
	printf("\n%ld\n", nc);		
	return 0;
}
