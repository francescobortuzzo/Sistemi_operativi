#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_LINE_SIZE 10000

int getLine(FILE *file, char *string){
	int i = 0;
	for(char c = fgetc(file); c != '\n'; c = fgetc(file)){
		if(c != EOF){
			string[i] = c;
			i++;
		} else {
			return -1;
		}
	}
	return i;
}

int isAt(int argc, char** argv){
	for(int i = 3; i < argc; i++){
		if(argv[i][0] == '@'){
			return i;
		}
	}
	return 0;
}


int main(int argc, char **argv) {

	if(argc < 4) {
		fprintf(stderr, "Fornire il nome di un file e di un comando\n");
		return 1;
	};
	
	char *filename = argv[1];
	FILE *file = fopen(filename, "r");
	
	if(!file){
		fprintf(stderr, "Errore nell'apertura del file\n");
		return 2;
	};
	
	
	char *line = calloc(MAX_LINE_SIZE, sizeof(char));
	int size = getLine(file, line);
	line = realloc(line, size);
	
	int i = isAt(argc, argv);
	argv[i] = line;
	
	if(i){
		while(size != -1){
			pid_t pid = fork();
			switch(pid){
				case -1:
					perror("fork failed");
					return 3;
				case 0:
					execvp(argv[2], argv + 2);
					perror("exec failed");
					return 4;
				default :
					wait(NULL);
					char *line = calloc(MAX_LINE_SIZE, sizeof(char));
					size = getLine(file, line);
					line = realloc(line, size);
					argv[i] = line;
				}
			
		}
	} else {
		execvp(argv[2], argv + 2);
	}
	return 0;
}
