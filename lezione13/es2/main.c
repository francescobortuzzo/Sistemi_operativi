#include "main.h"


int main(int argc, char **argv) {
	if(argc < 3) {
		fprintf(stderr, "Fornire il nome dei file\n");
		return 1;
	};
		char line0[SIZE];
		char line1[SIZE];
		char *filename0 = argv[1];
		char *filename1 = argv[2];
		FILE *file0 = fopen(filename0, "r");
		FILE *file1 = fopen(filename1, "r");
		if(!file0 || !file1) {
			fprintf(stderr, "Errore nell’apertura di uno dei file!\n");
			return 2;
		 }else {
		 	while((fgets(line0, SIZE, file0) !=NULL) && (fgets(line0 , SIZE, file1)!=NULL)){
		 		
		 		if(strcmp(line0, line1) != 0){
		 			fprintf(stdout, "%s\n %s\n", line0, line1);
		 		}
		 	}
		 	if((fgets(line0, SIZE, file0) !=NULL) && (fgets(line0 , SIZE, file1) == NULL)) {
		 		fprintf(stdout, "%s\n", line0);
		 	} else if ((fgets(line0, SIZE, file0) == NULL) && (fgets(line0 , SIZE, file1) != NULL)) {
		 		fprintf(stdout, "%s\n", line1);
		 	} else {
		 		fprintf(stdout, "I due file contengono lo stesso testo\n");
		 	}
		 	return 0;		 	
		}
}
