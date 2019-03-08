/*
*CAMPO DA ESTRUTURA PASSADA POR REFERÊNCIA
*/

#include<stdio.h>

struct ponto {
	int x, y;
};
void imprime_valor_referencia(int *n) {
	printf("Valor = %d\n", *n);
}

int main() {
	struct ponto p1 = {10, 20};
	imprime_valor_referencia(&p1.x);
	imprime_valor_referencia(&p1.y);
	
	getchar();
	return 0;
}
