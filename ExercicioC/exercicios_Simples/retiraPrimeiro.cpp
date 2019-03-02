/*
INT RETIRAPRIMEIRO(STRUCT PILHA *PS) QUE RETIRA E RETORNA O PRIMEIRO ELEMENTO INSERIDO NA PILHA. APÓS A EXECUÇÃO DA FUNÇÃO, MANTER OS ELEMTOS NA MESMA POSIÇÃO RELATIVAS NA PILHA.
*/

struct pilha {
	int item[tamanho];
	int topo;
};
void inicializa(struct pilha *ps) {
	ps->topo = -1;
}
int cheia(struct pilha *ps) {
	if(ps->topo == tamanho-1)
		return 1;
	else
		return 0;
}
int vazia(struct pilha *ps) {
	if(ps->topo == -1)	
		return 1;
	else
		return 0;
}
void push(struct pilha *ps, int x) {
	if(cheia(ps)) {
		printf("\nPilha cheia");
		getchar();
	}
	else {
		ps->item[++(ps->topo)] = x;
		//ps->topo = ps->topo + 1;
		//ps->item[ps->topo] = x;
	}
}
int pop(struct pilha *ps) {
	int x;
	if(vazia(ps)) {
		printf("\nPilha vazia");
		getchar();
		return -1;
	}
	else
		return ps->item[ps->topo--];
		//x = ps->item[ps->topo];
		//ps->topo = ps->topo - 1;
		//return x;
}
int quantidade(struct pilha *ps) {
	int x;
	int contador = 0;
	struct pilha aux;
	inicializa(&aux);
	if(vazia(ps))
		return 0;
	while(!vazia(ps)) {
		x = pop(ps);
		contador++;
		push(&aux, x);
	}
	while(!vazia(&aux)) {
		x = pop(&aux);
		push(ps, x);
	}
	return contador;
}
void mostraPilha(struct pilha *ps) {
	int x;
	struct pilha aux;
	inicializa(&aux);
	if(vazia(ps)) {
		printf("\nPilha vazia");
		getch();
		return;
	}
	while(!vazia(ps)) {
		x = pop(ps);
		push(&aux, x);
	}
	while(!vazia(&aux)) {
		x = pop(&aux);
		printf("\nElemento na pilha %d", x);
		push(ps, x);
	}
}
int retiraPrimeiro(struct pilha *ps) {
	int x, y;
	struct pilha aux;
	inicializa(ps);
	if(vazia(ps))
		return 0;
	y = pop(ps);
	while(!vazia(ps)) {
		x = pop(ps);
		push(&aux, x);
	}
	while(!vazia(&aux)) {
		x = pop(&aux);
		push(ps, x);
	}
	return y;
}
main() {
	struct pilha s;
	int i, x;
	inicializa(&s);
	push(&s, 3);
	push(&s, 10);
	push(&s, 11);
	push(&s, 20);
	push(&s, 40);
	
	printf("\nElemento retirado da pilha: %d", pop(&s));
	printf("\n\nElementos Inseridos:\n\n");
	printf("\n\n\nFim do programa");
	getchar();
	
}
