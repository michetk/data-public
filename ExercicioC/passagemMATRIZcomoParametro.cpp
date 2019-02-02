/*
Passagem de MATRIZ como parâmetro
*/

#include<stdio.h>
#include<stdlib.h>

void imprime_matriz(int m[][2], int t) {
	int i, j;
	
	for (i = 0; i < t; i++) 
		for (j = 0; j < 2; j++) 
			printf("%d\n", m[i][j]);
}

int main() {
	int mat[3][2] = {{1, 2}, {3, 4}, {5, 6}};
	
	imprime_matriz(mat, 3);
	
	system("pause");
	return 0;
}
