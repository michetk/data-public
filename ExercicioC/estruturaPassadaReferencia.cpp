/*
*ESTRUTURA PASSADA POR REFERÊNCIA
*/

#include<stdio.h>

struct ponto {
	int x, y;
};
void atribui(struct ponto *p) {
	(*p).x = 10;
	(*p).y = 20;
}

int main() {
	struct ponto p1;
	atribui(&p1);
	printf("x = %d\n", p1.x);
	printf("y = %d\n", p1.y);
	
	getchar();
	return 0;
}
