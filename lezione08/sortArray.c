#include <stdio.h>

#define arrayLength  11

void insertionSort( int *array){
	for (int i = 1; i < arrayLength; i++){
     		int value = array[i];
     		int j = i-1;
     		while ( (j >= 0) && (array[j] > value) ){
             		array[j + 1] = array[j];
        		array[j] = value;
        		j--;
        	}
        }
}

int main(){
	int array[arrayLength] ={8, 7, 22, 90, 8, 55, 31, 100, 1009102, 9480213, 99999};
	int *arr = array;	
     	insertionSort(arr);
	for(int i = 0; i < arrayLength; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}
