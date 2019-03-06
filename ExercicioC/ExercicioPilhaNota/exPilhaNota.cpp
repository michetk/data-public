/*
*UM ESTACIONAMENTE CONTEM UMA UNICA ALAMEDA QUE GUARDA ATÉ 10 CARROS. ok
*EXISTE APENAS UMA ENTRA/SAIDA NO ESTACIONAMENTO EM UMA EXTREMIDADE DA ALAMEDA. ok
*SE CHEGAR UM CLIENTE PARA TIRAR UM CARRO QUE NÃO O MAIS PROXIMO DA SAÍDA, TODOS OS CARROS BLOQUEANDO O CAMINHO SAIRÃO DO ESTACIONAMENTO. ok
*O CARRO DO CLIENTE SARÁ MANOBRADO PARA FORA, E OS OUTROS CARROS VOLTARÃO A OCULPAR A MESMA SEQUENCIA INICIAL. ok
*ESCREVA UM PROGRAMA EM C, QUE TENHA COMO ENTRADA UM "E" DE ENTRADA OU UM "S" DE SAÍDA E O NÚMERO DA PLACA DO CARRO. ok
*O PROGRAMA DEVE MOSTRAR UMA MENSAGEM SEMPRE QUE UM CARRO CHEAR OU SAIR. ok
*QUANDO CHEGAR A MENSAGEM DEVE ESPECIFICAR SE EXISTE VAGA PARA O CARRO, SE NÃO HOUVER VAGA O CARRO PARTIRÁ SEM ENTRAR NO ESTACIONAMENTO. ok
*QUANDO O CARRO SAIR DO ESTACIONAMENTO A MENSAGEM DEVERÁ INCLUIR O NÚMERO DE VEZES QUE O CARRO FOI MANOBRADO PARA FORA DO ESTACIONAMENTO. ok
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define TAMANHO 4
#define ANSI_COLOR_RED "\e[31m"
#define ANSI_COLOR_BLUE "\e[34m"
#define ANSI_COLOR_RESET "\e[0m"

struct veiculo {
	int placa;
	int manobras;
};
struct pilha {
	int topo;
	struct veiculo item[TAMANHO];
};
void inicializar(struct pilha *ps);
int cheia(struct pilha *ps);
int vazia(struct pilha *ps);
void push(struct pilha *ps, int x);
int pop(struct pilha *ps);
int quantidade(struct pilha *ps);
void mostraPilha(struct pilha *ps);
void menu(int *op, int aux);
int fconfirmar(char confirmar);
int fconfirmarExit(char confirmar);
void qtdeManobra(struct pilha *ps);
void zeraManobra(struct pilha *ps);
void exe(struct pilha *ps, struct veiculo *pv);
void fexit(char pexit);

int mainRet = 0;
struct pilha s;
struct veiculo valorS;
int main() {
	valorS.placa = 0;
	inicializar(&s);
	exe(&s, &valorS);
	
	getchar();
	return 0;
}
void inicializar(struct pilha *ps) {
	ps->topo = -1;
}
int cheia(struct pilha *ps) {
	if(ps->topo == TAMANHO -1)
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
	else
		ps->item[++(ps->topo)].placa = x;
}
int pop(struct pilha *ps) {
	if(vazia(ps)) {
		printf("\nPilha vazia");
		getchar();
		return -1;
	}
	else
		return ps->item[ps->topo--].placa;
}
int quantidade(struct pilha *ps) {
	struct pilha aux;
	struct veiculo x;
	int qtde = 0;
	inicializar(&aux);
	if(vazia(ps))
		return qtde;
	while(!vazia(ps)) {
		x.placa = pop(ps);
		push(&aux, x.placa);
	}
	while(!vazia(&aux)) {
		x.placa = pop(&aux);
		qtde++;
		push(ps, x.placa);
	}
	return qtde;
}
void mostraPilha(struct pilha *ps) {
	struct pilha aux;
	struct veiculo x;
	int cont = 0;
	inicializar(&aux);
	if(vazia(ps))
		printf(ANSI_COLOR_RED"\nESTACIONAMENTO VAZIO!"ANSI_COLOR_RESET);
	while(!vazia(ps)) {
		x.placa = pop(ps);
		push(&aux, x.placa);
	}
	printf("\n");
	while(!vazia(&aux)) {
		x.placa = pop(&aux);
		push(ps, x.placa);
		printf(ANSI_COLOR_BLUE"\n--> POSICAO(%d) contem PLACA->%d ::::: QTDE manobras: %d"ANSI_COLOR_RESET, cont, x.placa, ps->item[ps->topo].manobras);
		cont++;
	}
	printf("\n");
}
void menu(int *op, int aux) {
	if (aux != 1)
		aux = 0;
	*op = -1;
	do {
		system("cls");
		printf(":::CONTROLE DE ESTACIONAMENTO:::\n\n");
		printf("\n___ESCOLHA AS OPCOES___\n");
		printf("\n1. ENTRADA DE VEICULO");
		printf("\n2. SAIDA DE VEICULO");
		printf("\n3. MOSTRAR ESTACIONAMENTO");
		if(aux == 0) {
			if(mainRet == 1) {
				printf(ANSI_COLOR_RED"\n\nOPCAO INVALIDA! digite s(sim) ou n(nao) para a opcao 2..."ANSI_COLOR_RESET);
				mainRet = 0;
				printf("\nDigite a opcao: ");
				scanf("%d", op);
				break;
			}
			printf("\n\n\nDigite a opcao: ");
			scanf("%d", op);
		}
		if(aux == 1) {
			printf(ANSI_COLOR_RED"\n\nOPCAO INVALIDA! ..tente novamente.."ANSI_COLOR_RESET);
			printf("\nDigite a opcao: ");
			scanf("%d", op);
		}
		aux = 1;
	}while(*op < 1 || *op > 3);
	aux = 2;
	if(aux == 2) {
		system("cls");
		printf(":::CONTROLE DE ESTACIONAMENTO:::\n\n");
		printf("\n___ESCOLHA AS OPCOES___\n");
		printf("\n1. ENTRADA DE VEICULO");
		printf("\n2. SAIDA DE VEICULO");
		printf("\n3. MOSTRAR ESTACIONAMENTO");
		printf("\n\n\nDigite a opcao: %d", *op);
		printf("\n\n______________________________\n\n");
	}
	aux = 0;
}
void qtdeManobra(struct pilha *ps) {
	if(vazia(ps))
		return;
	struct pilha aux;
	struct veiculo x;
	inicializar(&aux);
	while(!vazia(ps)) {
		x.placa = pop(ps);
		push(&aux, x.placa);
	}
	while(!vazia(&aux)) {
		x.placa = pop(&aux);
		push(ps, x.placa);
		ps->item[ps->topo].manobras++;
	}
}
void zeraManobra(struct pilha *ps) {
	ps->item[ps->topo].manobras = 0;
}
void exe(struct pilha *ps, struct veiculo *pv) {
	int op;
	do {
		menu(&op, 0);
		switch(op) {
			case 1:
				printf(":::ENTRADA:::");
				if(cheia(ps)) {
					printf(ANSI_COLOR_RED"\nNAO HA VAGAS"ANSI_COLOR_RESET);
					printf("\nENTER para voltar as OPCOES");
					printf("\nESC para sair do programa");
					fexit(getch());
					exe(&s, &valorS);
				}
				else {
					printf("\nVAGA DISPONIVEI");
				}
				printf("\nDigite o numero da PLACA: ");
				scanf("%d", &pv->placa);
				printf("______________________________\n");
				push(ps, pv->placa);
				zeraManobra(ps);
				break;
			case 2:
				if(vazia(ps)) {
					printf(ANSI_COLOR_RED"\nESTACIONAMENTO VAZIO!"ANSI_COLOR_RESET);
					printf("\nENTER para voltar as OPCOES");
					printf("\nESC para sair do programa");
					fexit(getch());
					exe(&s, &valorS);
				}
				else {
					char confirmar;
					int conf;
					printf(":::SAIDA:::");
					printf("\nTem certeza que deseja remover o carro de PLACA->%d? S/N: ", ps->item[ps->topo]);
					fflush(stdin);
					scanf("%c", &confirmar);
					conf = fconfirmar(confirmar);
					if(conf == 1) {
						int qtdeMan;
						qtdeMan = ps->topo;
						pop(ps);
						qtdeManobra(ps);
						printf("\nQTDE manobras do VEICULO: %d", ps->item[qtdeMan].manobras);
						break;
					}
					else
						exe(&s, &valorS);
				}
				case 3:
						break;
			default:
				break;
		}
		if(vazia(ps)) {
			printf("\nQuantidade de veiculos no estacionamento: %d", quantidade(ps));
			printf(ANSI_COLOR_RED"\n\nESTACIONAMENTO VAZIO!"ANSI_COLOR_RESET);
			getch();
			exe(&s, &valorS);
		}
			printf("\nUltimo veiculo a entrar: PLACA->%d", ps->item[ps->topo]);
			printf("\nQuantidade de veiculos no estacionamento: %d", quantidade(ps));
			mostraPilha(ps);
		
		printf("\n\n\nFIM DO PROGRAMA");
		printf("\nENTER para voltar as OPCOES");
		printf("\nESC para sair do programa");
		fexit(getch());
	}while(1);
}
int fconfirmar(char confirmar) {
	if(confirmar == 's' || confirmar == 'n' || confirmar == 'S' || confirmar == 'N') {
		if(confirmar == 's' || confirmar == 'S')
			return 1;
		else
			return 0;
	}
	else {
		mainRet = 1;
		exe(&s, &valorS);
	}
}
int fconfirmarExit(char confirmar) {
	if(confirmar == 's' || confirmar == 'n' || confirmar == 'S' || confirmar == 'N') {
		if(confirmar == 's' || confirmar == 'S')
			return 1;
		else
			return 0;
	}
	else {
		printf(ANSI_COLOR_RED "\n\nOPCAO INVALIDA! digite s(sim) ou n(nao) ..." ANSI_COLOR_RESET);
		int auxConfirmar;
		int auxExit = 0;
		printf("\n\nTem certeza que deseja sair do programa? S/N: ");
		fflush(stdin);
		auxConfirmar = fconfirmarExit(getch());
		if(auxConfirmar == 1) {
			exit(0);
		}
		if(auxConfirmar == 0) {
		printf("\n\nENTER para voltar as OPCOES");
		printf("\nESC para sair do programa");
		fexit(getch());
		}
	}
}
void fexit(char pexit) {
	if(pexit == 27) {
		int auxConfirmar;
		int auxExit = 0;
		printf("\nTem certeza que deseja sair do programa? S/N: ");
		//fflush(stdin);
		auxConfirmar = fconfirmarExit(getch());
		if(auxConfirmar == 1) {
			exit(0);
		}
		if(auxConfirmar == 0) {
		printf("\n\nENTER para voltar as OPCOES");
		printf("\nESC para sair do programa");
		fexit(getch());
		}
	}
}
