/*
*CAMPO DA ESTRUTURA PASSADA POR VALOR
*/

#include<stdio.h>

struct ponto {
	int x, y;
};
void imprime_valor(int n) {
	printf("Valor = %d\n", n);
}

int main() {
	struct ponto p1 = {10, 20};
	imprime_valor(p1.x);
	imprime_valor(p1.y);
	
	getchar();
	return 0;
}
