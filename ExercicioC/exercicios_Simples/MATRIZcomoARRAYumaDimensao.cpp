/*
MATRIZ como ARRAY de uma dimensão
*/

#include<stdio.h>
#include<stdlib.h>

void imprime_matriz(int *m, int t) {
	int i;
	
	for (i = 0; i < t; i++)
		printf("%d\n", m[i]);
}

int main() {
	int mat[3][2] = {{1, 2}, {3, 4}, {5, 6}};
	
	imprime_matriz(&mat[0][0], 6);
	
	system("pause");
	return 0;
}
