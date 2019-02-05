#include<stdio.h>

int soma(int a, int b) {
	int soma;
	soma = a + b;
	return soma;
}

main() {
	int a, b, s;
	printf("Valor A: ");
	scanf("%d", &a);
	printf("Valor B: ");
	scanf("%d", &b);
	s = soma(a, b);
	printf("\n\nResultado: %d", s);
	
	getchar();
	getchar();
	
}
