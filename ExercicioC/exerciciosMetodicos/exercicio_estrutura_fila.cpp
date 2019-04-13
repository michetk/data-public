/* estrutura lista
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define TAMANHO 100

struct fila {
	int inicio, fim, contador;
	int item[TAMANHO];
};
void filaInicializa(struct fila *pf) {
	pf->inicio = 0;
	pf->fim = TAMANHO -1;
	pf->contador = 0;
}
int filaCheia(struct fila *pf) {
	if(pf->contador == TAMANHO)
		return 1;
	else
		return 0;
}
int filaVazia(struct fila *pf) {
	if(pf->contador == 0)
		return 1;
	else
		return 0;
}
void filaRecebe(struct fila *pf, int x) {
	if(filaCheia(pf)) {
		printf("\nFila cheia!");
		getch();
	}
	else {
		pf->contador++;
		if(pf->fim == TAMANHO-1) {
			pf->fim = 0;
			pf->item[pf->fim] = x;
		}
		else {
			pf->item[++(pf->fim)] = x;
		}
	}
}
int filaRetira(struct fila *pf) {
	if(filaVazia(pf)) {
		printf("\nFila vazia!");
		getch();
		return -1;
	}
	else {
		pf->contador--;
		if(pf->inicio == TAMANHO-1) {
			int aux;
			aux = pf->item[pf->inicio];
			pf->inicio = 0;
			return aux;
		}
		else {
			return pf->item[pf->inicio--];
		}
	}
}
void furaFila(struct fila *pf, int x) {
	if(filaCheia(pf)) {
		printf("\nFila cheia!");
		getch();
	}
	else {
		pf->contador++;
		if(pf->inicio == 0) {
			pf->inicio = TAMANHO-1;
			pf->item[pf->inicio] = x;
		}
		else {
			pf->item[--(pf->inicio)] = x;
		}
	}
}
void intercalaFilas(struct fila *pf1, struct fila *pf2, struct fila *pf3) {
	int aux;
	if(filaCheia(pf3)) {
		printf("\nFila cheia!");
		getch();
		return;
	}
	while((!filaVazia(pf1) || !filaVazia(pf2)) && !filaCheia(pf3)) {
		if(!filaVazia(pf1)) {
			aux = filaRetira(pf1);
			filaRecebe(pf3, aux);
		}
		if(!filaVazia(pf2)) {
			aux = filaRetira(pf2);
			filaRecebe(pf3, aux);
		}
	}
	if(filaCheia(pf3))
		printf("\nFila cheia!");
}
void mostraFila(struct fila *pf) {
	if(filaVazia(pf)) {
		printf("\nFila vazia!");
		getch();
	}
	for(int i = 0; i < pf->contador; i++) {
		printf("\nPosicao[%d] :::: Valor: %d", i, pf->item[i]);
	}
}
void filaOrdenada(struct fila *pf1, struct fila *pf2, struct fila *pf3) {
	int auxpf1, auxpf2;
	if(filaCheia(pf3)) {
		printf("\nFila cheia!");
		getch();
	}
	while((!filaVazia(pf1) || !filaVazia(pf2)) && !filaCheia(pf3)) {
		if(filaCheia(pf3)) {
			printf("\nFila cheia!");
			getch();
		}
		if(filaVazia(pf1)) {
			auxpf2 = filaRetira(pf2);
			filaRecebe(pf3, auxpf2);
		}
		else
			if(filaVazia(pf2)) {
				auxpf1 = filaRetira(pf1);
				filaRecebe(pf3, auxpf1);
			}
		else {
			if(!filaVazia(pf1) || !filaVazia(pf2)) {
				auxpf1 = filaRetira(pf1);
				auxpf2 = filaRetira(pf2);
				if(auxpf1 < auxpf2) {
					filaRecebe(pf3, auxpf1);
					furaFila(pf2, auxpf2);
				}
			}
			else {
				filaRecebe(pf3, auxpf2);
				furaFila(pf1, auxpf1);
			}
		}	
	}
}
int main() {
	struct fila f1, f2, f3;
	filaInicializa(&f1);
	filaInicializa(&f2);
	filaInicializa(&f3);
	
	filaRecebe(&f1, 1);
	filaRecebe(&f1, 3);
	filaRecebe(&f1, 5);
	filaRecebe(&f1, 7);
	filaRecebe(&f1, 8);
	filaRecebe(&f1, 9);
	
	filaRecebe(&f2, 0);
	filaRecebe(&f2, 2);
	filaRecebe(&f2, 4);
	filaRecebe(&f2, 12);
	
	filaOrdenada(&f1, &f2, &f3);
	mostraFila(&f3);
	

	printf("\n\n\n:::FIM DO PROGRAMA:::");
	getch();
	return 0;
}
