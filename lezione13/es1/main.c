#include "main.h"


int main(int argc, char **argv) {
	if(argc < 3) {
		fprintf(stderr, "Fornire il nome dei file\n");
		return 1;
	};
	for(int i = 1; i < argc; i++){
		char *filename = argv[i];
		FILE *file = fopen(filename, "r");
		if(!file) {
			fprintf(stderr, "Errore nell’apertura di uno dei file!\n");
			return 2;
		 }else {
			char c;
			while(fscanf(file, "%c", &c) != EOF){
				fprintf(stdout, "%c", c);
			}
		}
	}
	return 0;
}
