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
void fialiInicializa(struct fila *pf) {
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
int filaFazia(struct fila *pf) {
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
		f->contador++;
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
	while((!filaVazia(pf1) || !fliaVazia(pf2)) && !filaCheia(pf3)) {
		if(!filaVazia(pf1)) {
			aux = filaRemove(pf1);
			filaRecebe(pf3, aux);
		}
		if(!filaVazia(pf2)) {
			aux = filaRemove(pf2);
			filaRecebe(pf3, aux);
		}
	}
	if(filaCheia(pf3))
		printf("\nFila cheia!");
}
void filaOrdenada(struct fila *pf1, struct fila *pf2, struct fila *pf3) {
	int auxpf1, auxpf2;
	if(filaCheia(pf3)) {
		printf("\nFila cheia!");
		getch();
	}
	while((!filaVazia(pf1) || !filaVazia(pf2)) && !filaCheia(pf3)) {
		if(!filaVazia(pf1)) {
			auxpf1 = filaRemove(pf1);
		}
		if(!filaVazia(pf2)) {
			auxpf2 = filaRemove(pf2);
		}
		
	}
}
