#include <stdio.h>
#define arrayLength 8

void sort( int *);
void reverse( int *);
void qsort( int *, int, int);
void merge( int *, int, int, int);
void swap(int*, int, int);
void copy(int *, int *, int, int);


int main(){
	int array[arrayLength] = {4, 3, 16, 22, 11, 8, 32, 10};
	int *arr = array;
	int x;
	scanf("%d", &x);
	if( x == 0){
		sort(arr);
		printf("L'array ordinato e': ");
		for(int i = 0; i < arrayLength; i++){
			printf("%d ", array[i] );
		};
	} else if (x == 1) {
		reverse(arr);	
		printf("\nL'array invertito e': ");
		for(int i = 0; i < arrayLength; i++){
			printf("%d ", array[i] );
		};
	} else if (x == 2){
		qsort(arr, 0, arrayLength-1);
		printf("\nL'array ordinato con qsort e': ");
		for(int i = 0; i < arrayLength; i++){
			printf("%d ", array[i] );
		};
	};
	printf("\n");
	return 0;
}

void sort( int *array){
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

void reverse( int *array){
	int i = 0;
	int j = arrayLength -1;
	while(i < j){
		swap( array, i, j);
		i++;
		j--;
	};	
}

void qsort( int *array, int l, int r){
	if( l < r ){
		int mid = (r + l)/2;
		qsort(array, l, mid);
		qsort(array, mid+1, r);
		merge( array, l, mid, r);
	}
}

void merge(int *array, int l, int mid, int r){
	int i = l;
	int j = mid+1;
	int k = 0;
	int beta[500];
	
	while( (i <= mid) && (j <= r) ){
		if( array[i] < array[j] ) {
			beta[k] = array[i];
			i++;
		} else {
			beta[k] = array[j];
			j++;
		};
		k++;
	};
	while (i <= mid) {
		beta[k] = array[i];
		i++;
		k++;
	};
	while (j <= r) {
		beta[k] = array[j];
		j++;
		k++;
	};
	copy(array, beta, l, r);
}

void swap(int *array, int i, int j){
	int tmp = array [i];
	array[i] = array[j];
	array[j] = tmp;
}

void copy(int *array, int *beta, int l, int r){
	for(int i = l; i <= r; i++){
		array[i] = beta[i-l];
	};
}
