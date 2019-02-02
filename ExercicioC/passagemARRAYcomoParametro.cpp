/*
Passagem de ARRAY como parâmetro
*/

#include<stdio.h>
#include<stdlib.h>

void imprime(int *n, int t) {
	int i;
	for (i = 0; i < t; i++) {
		printf("%d\n", n[i]);
	}
}

int main() {
	int v[5] = {1, 2, 3, 4, 5}, t;
	t = 5;
	
	imprime(v, t);
	
	system("pause");
	return 0;
}
