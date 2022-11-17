#include <stdio.h>


int power(int, int);
int lg(int);

int main()
{
	int c;
	scanf("%d", &c);
	int m = lg(c);
	printf("%d\n", m);
}

int lg(int n){
	int m = 0;
	while(power(10, m) <= n){
		m++;
	}
	return m -1;
}

int power( int m, int n){
	int p = 1;
	for(int i = 0; i < n; i++){
		p = p * m;
	}
	return p;
}
