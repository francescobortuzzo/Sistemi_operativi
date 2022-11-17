#include <stdio.h>

int main(){
	int x;
	int sum = 0;
	while(scanf("%d", &x) != EOF){
		sum = sum + x;
	}
	printf("\n La somma dei valori inseriti e' %d\n", sum);
	return 0;
}
