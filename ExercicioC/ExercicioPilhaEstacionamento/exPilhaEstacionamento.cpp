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
void push(struct pilha *ps, struct veiculo x);
struct veiculo pop(struct pilha *ps);
int quantidade(struct pilha *ps);
void mostraPilha(struct pilha *ps);
void menu(int *op, int aux); //MENU DE CONTROLE DE OPÇÕES
int fconfirmar(char confirmar); //CONFIRMAR OU NÃO A SAIDA DE UM VEÍCULO DO ESTACIONAMENTO
int fconfirmarExit(char confirmar); //CONFIRMAR OU NAO O FECHAMENTO DO PROGRAMA
void qtdeManobra(struct pilha *ps); //CONTA A QUANTIDADE DE MANOBRA QUE CADA VEICULO VAZ PARA UM OUTRO SAIR
void zeraManobra(struct pilha *ps); //INICIALIZA A ENTRADA DE UM VEÍCULO COM MANOBRA ZERO
void exe(struct pilha *ps, struct veiculo *pv); //FUNÇÃO PRINCIPAL ONDE É EXECUTADO TODO O PROGRAMA, AJUDA A REINICIALIZAR O PROGRAMA SEM SAIR DO MESMO E PERDER OS DADOS NA MEMÓRIA 
void fexit(char pexit); //CONTROLA O FECHAMENTO DO PROGRAMA USANDO A TECLA 'ESC'
void validarPlaca(); //FAZ VALIDAÇÃO DA PLACA DO VEÍCULO

int mainRet = 0; //ESTÁ DENTRO DA FUNCAO 'MENU' E 'FCONFIRMAR', SERVE PARA RETORNAR UMA MENSAGEM DE ERRO CASO A OPCAO '2' NÃO SEJA EXECUTADA COM EXIGE O PROGRAMA
int placa;
struct pilha s;
struct veiculo valorS;
int main() {
	valorS.placa = 0;
	inicializar(&s);
	placa = valorS.placa;
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
void push(struct pilha *ps, struct veiculo x) {
	if(cheia(ps)) {
		printf("\nPilha cheia");
		getchar();
	}
	else
		ps->item[++(ps->topo)] = x;
}
struct veiculo pop(struct pilha *ps) {
	if(vazia(ps)) {
		printf("\nPilha vazia");
		getchar();
		return ps->item[ps->topo];
	}
	else
		return ps->item[ps->topo--];
}
int quantidade(struct pilha *ps) {
	struct pilha aux;
	struct veiculo x;
	int qtde = 0;
	inicializar(&aux);
	if(vazia(ps))
		return qtde;
	while(!vazia(ps)) {
		x = pop(ps);
		push(&aux, x);
	}
	while(!vazia(&aux)) {
		x = pop(&aux);
		qtde++;
		push(ps, x);
	}
	return qtde;
}
void mostraPilha(struct pilha *ps) {
	struct pilha aux;
	struct veiculo x;
	int cont = 0;
	inicializar(&aux);
	if(vazia(ps))
		printf("\nESTACIONAMENTO vazio\n");
	while(!vazia(ps)) {
		x = pop(ps);
		push(&aux, x);
	}
	printf("\n");
	while(!vazia(&aux)) {
		x = pop(&aux);
		push(ps, x);
		printf("\n--> POSICAO(%d) contem PLACA %d ::::: QTDE manobras: %d", cont, x.placa, ps->item[ps->topo].manobras);
		cont++;
	}
	printf("\n");
}
void menu(int *op, int aux) {
	if (aux != 1)
		aux = 0; //VARIÁVEL QUE CONTROLA QUAL PARTE DO MENU SERÁ EXECUTADO
	*op = -1;
	/*LAÇO PARA CONTROLAR A REINCIDÊNCIA NO MENU*/
	do {
		system("cls");
		printf(":::CONTROLE DE ESTACIONAMENTO:::\t\tCAPACIDADE DE VEICULOS: %d\n\t\t\t\t\t\tVAGAS DISPONIVEIS: %d", TAMANHO, TAMANHO - quantidade(&s));
		if(valorS.placa == 0)
			printf("\n\t\t\t\t\t\tUltimo veiculo que entrou: PLACA (----)");		
		else
			printf("\n\t\t\t\t\t\tUltimo veiculo que entrou: PLACA %d", placa);
		
		printf("\n\t\t\t\t\t\tQuantidade de veiculos no estacionamento: %d", quantidade(&s));
		printf("\n___ESCOLHA AS OPCOES___\n");
		printf("\n1. ENTRADA DE VEICULO");
		printf("\n2. SAIDA DE VEICULO");
		printf("\n3. MOSTRAR ESTACIONAMENTO");
		/*ENTRA PRIMEIRO AQUI*/
		if(aux == 0) {
			if(mainRet == 1) { //RETORNA AQUI SOMENTE SE A OPCAO '2' FOR CONFIRMADA DE FORMA ERRADA
				printf("\n\nOPCAO INVALIDA! digite s(sim) ou n(nao) para a opcao 2...");
				mainRet = 0;
				printf("\nDigite a opcao: ");
				scanf("%d", op);
				break;
			}
			printf("\n\n\nDigite a opcao: ");
			scanf("%d", op);
		}
		/*SE A OPCAO DIGITADA NÃO FOR CONFORME AS QUE FORAM FORNECIDAS O MENU RETORNA AQUI*/
		if(aux == 1) {
			printf("\n\nOPCAO INVALIDA! ..tente novamente..");
			printf("\nDigite a opcao: ");
			scanf("%d", op);
		}
		aux = 1;
	}while(*op < 1 || *op > 3); //SE A OPÇÃO FOR CORRETA O PROGRAMA PULA O LAÇO DE REPETIÇÃO
	aux = 2;
	/*SE A OPCAO DIGITADA FOR CORRETA, O PROGRAMA LIMPA A TELA E FORNECE AS INFORMAÇÕES DE FORMA CLARA*/
	if(aux == 2) {
		system("cls");
		printf(":::CONTROLE DE ESTACIONAMENTO:::\t\tCAPACIDADE DE VEICULOS: %d\n\t\t\t\t\t\tVAGAS DISPONIVEIS: %d", TAMANHO, TAMANHO - quantidade(&s));
		if(valorS.placa == 0)
			printf("\n\t\t\t\t\t\tUltimo veiculo que entrou: PLACA (----)");		
		else
			printf("\n\t\t\t\t\t\tUltimo veiculo que entrou: PLACA %d", placa);
		printf("\n\t\t\t\t\t\tQuantidade de veiculos no estacionamento: %d", quantidade(&s));
		printf("\n___ESCOLHA AS OPCOES___\n");
		printf("\n1. ENTRADA DE VEICULO");
		printf("\n2. SAIDA DE VEICULO");
		printf("\n3. MOSTRAR ESTACIONAMENTO");
		printf("\n\n\nDigite a opcao: %d", *op);
		printf("\n\n______________________________\n\n");
	}
	aux = 0; //ANTES DE SAIR DO MENU, O PROGRAMA ZERA O CONTROLE DO MENU
}
void qtdeManobra(struct pilha *ps) {
	if(vazia(ps))
		return;
	struct pilha aux;
	struct veiculo x;
	inicializar(&aux);
	while(!vazia(ps)) {
		x = pop(ps);
		push(&aux, x);
	}
	while(!vazia(&aux)) {
		x = pop(&aux);
		push(ps, x);
		ps->item[ps->topo].manobras++; //SOMA '1' SOBRE A MANOBRA DO VEICULO
	}
}
void zeraManobra(struct pilha *ps) {
	ps->item[ps->topo].manobras = 0;
}
void exe(struct pilha *ps, struct veiculo *pv) {
	int op; //VARIÁVEL QUE CONTROLA AS OPÇÕES ESCOLHIDAS
	do {
		menu(&op, 0); //CHAMA O MENU
		switch(op) {
			case 1:
				printf(":::ENTRADA:::");
				/*SE O ESTACIONAMENTO ESTIVER CHEIO, CONDICIONAL NÃO PERMITE A ENTRADA DO VEÍCULO*/
				if(cheia(ps)) {
					printf("\nNAO HA VAGAS\n");
					printf("\nENTER para voltar as OPCOES");
					printf("\nESC para sair do programa");
					fexit(getch()); //CONTROLA O FECHAMENTO DO PROGRAMA USANDO A TECLA 'ESC'
					exe(&s, &valorS); //CHAMA A FUNÇÃO PRINCIPAL NOVAMENTE E COMEÇA O PROGRAMA NOVAMENTE SEM ZERAR A MEMÓRIA
				}
				else {
					printf("\nVAGA DISPONIVEL\n");
				}
				printf("\nDigite o numero da PLACA: ");
				scanf("%d", &pv->placa);
				validarPlaca();
				placa = valorS.placa;
				printf("______________________________\n");
				/*QUANDO VEÍCULO ENTRA, AS MANOBRAS SÃO ZERADAS PARA QUE NÃO HAJA LIXO NA MEMÓRIA DE MANOBRAS*/
				push(ps, valorS);
				zeraManobra(ps);
				break;
			case 2:
				/*SE TENTAR REMOVER UM CARRO COM O ESTACIONAMENTO JÁ VAZIO , PROGRAMA ALERTA USUÁRIO*/
				if(vazia(ps)) {
					printf("\nESTACIONAMENTO VAZIO!\n");
					printf("\nENTER para voltar as OPCOES");
					printf("\nESC para sair do programa");
					fexit(getch()); //CONTROLA O FECHAMENTO DO PROGRAMA USANDO A TECLA 'ESC'
					exe(&s, &valorS); //CHAMA A FUNÇÃO PRINCIPAL NOVAMENTE E COMEÇA O PROGRAMA NOVAMENTE SEM ZERAR A MEMÓRIA
				}
				else {
					char confirmar;
					int conf;
					printf(":::SAIDA:::");
					printf("\nTem certeza que deseja remover o veiculo PLACA %d? S/N: ", ps->item[ps->topo]);
					fflush(stdin); //LIMPA UMA TECLA DIGITADA DA MEMÓRIA FLUSH, IMPORTANTE PARA A FUNÇÃO 'FCONFIRMAR' NÃO CAPTURAR UMA ENTRADA INDESEJADA
					scanf("%c", &confirmar);
					conf = fconfirmar(confirmar);
					if(conf == 1) {
						int qtdeMan; //VARIÁVEL PARA RECEBER O ÚLTIMO VALOR DE 'TOPO' ANTES DO MESMO SER REMOVIDO, SERVIRÁ PARA AJUDAR A MOSTRAR MANOBRAS QUE O VEÍCULO VEZ ANTES DE PARTIR
						qtdeMan = ps->topo;
						pop(ps);
						qtdeManobra(ps);
						printf("\nQTDE manobras do veiculo PLACA %d: %d\n\n", ps->item[qtdeMan].placa, ps->item[qtdeMan].manobras); //VARIÁVEL 'qtdeMan' É USADA DENTRO DO ÍNDECE DE 'ITEM' PARA REPRESENTAR O ÚLTIMO VEÍCULO QUE SAIU, E A QUANTIDADE DE MANOBRAS
						break;
					}
					else
						exe(&s, &valorS); //APÓS A CONCLUSÃO DA OPERAÇÃO, A FUNCAO PRINCIPAL É CHAMADA E O PROGRAMA REINICIALIZADO SEM ZERAR OS DADOS DA MEMÓRIA
				}
				case 3:
						break;
			default:
				break;
		}
		/*TODA VEZ QUE UMA OPERAÇÃO FOR REALIZADA E O ESTACIONAMENTO ESTIVER VAZIO, SERÁ MOSTRA UM ALERTA E NÃO SERÁ POSSÍVEL AVANÇAR*/
		if(vazia(ps)) {
			printf("\n\nESTACIONAMENTO VAZIO!\n");
			getch();
			exe(&s, &valorS); //APÓS A CONCLUSÃO DA OPERAÇÃO, A FUNCAO PRINCIPAL É CHAMADA E O PROGRAMA REINICIALIZADO SEM ZERAR OS DADOS DA MEMÓRIA
		}
		/*INFORMAÇÕES QUE IRÃO APARECER SEMPRE QUE UMA OPERAÇÃO BEM SUCEDIDA FOR REALIZADA, INCLUSIVE PARA O OPÇÃO '3'*/
		if(op != 2)
			mostraPilha(ps);
		printf("\n\n\nFIM DO PROGRAMA");
		printf("\nENTER para voltar as OPCOES");
		printf("\nESC para sair do programa");
		fexit(getch()); //CONTROLA O FECHAMENTO DO PROGRAMA USANDO A TECLA 'ESC'
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
		mainRet = 1; //VARIÁVEL CRIADA NO INÍCIO DO PROGRAMA PARA CONTROLAR MENSAGEM A SER EXIBIDA SE O OPÇÃO DE CONFIRMAR NÃO SATISFAZER AO 'S' OU 'N'.
		exe(&s, &valorS); //PROGRAMA É REINICIALIZADO PARA ENTRAR NA CONDIÇÃO 'mainRet' DENTRO DA FUNÇÃO MENU E EXIBIR MENSAGEM DE ATENÇÃO.
	}
}
int fconfirmarExit(char confirmar) {
	if(confirmar == 's' || confirmar == 'n' || confirmar == 'S' || confirmar == 'N') {
		if(confirmar == 's' || confirmar == 'S')
			return 1;
		else
			return 0;
	}
	/*BLOCO DE COMANDO CONSTRUIDO PARA CRIAR UM LOOP DE REPETIÇÃO SE A OPCAO DE SAIR DO PROGRAMA NÃO FOR SATISFEITA COM UMA CONFIRMAÇÃO EXIGIDA PELO PROGRAMA*/
	else {
		printf("\n\nOPCAO INVALIDA! digite s(sim) ou n(nao) ...");
		int auxConfirmar; //VARIÁVEL CRIADA PARA RECEVER RETORNO DE '1' OU 'O' DA FUNÇÃO 'FCONFIRMAEXIT'
		int auxExit = 0;
		printf("\n\nTem certeza que deseja sair do programa? S/N: ");
		fflush(stdin); // LIMPA ÚLTIMA ENTRADA DO TECLADO, IMPORTANTE PARA QUE A FUNÇÃO 'FCONFIRMAEXIT' FUNCIONE PERFEITAMENTE
		auxConfirmar = fconfirmarExit(getch());
		if(auxConfirmar == 1) {
			exit(0);  //SAIR DO PROGRAMA
		}
		/*SE A TENTATIVA DE SAIR DO PROGRAMA NÃO FOR CONFIRMADA, PEDIR NOVAMENTE QUE O USUÁRIO TOME UMA DECISÃO*/
		if(auxConfirmar == 0) {
		printf("\n\nENTER para voltar as OPCOES");
		printf("\nESC para sair do programa");
		fexit(getch()); //CONTROLA O FECHAMENTO DO PROGRAMA USANDO A TECLA 'ESC'
		}
	}
}
void fexit(char pexit) {
	/*SE A TECLHA DIGITADA FOR 'ESC' O PROGRAMA DEVE PERGUNTAR PARA O USUÁRIO SE ELE REALMENTE DESEJA FECHAR O PROGRAMA*/
	if(pexit == 27) {
		int auxConfirmar; //VARIÁVEL PARA RECEBER RETORNO DA FUNÇÃO 'FCONFIRMAEXIT' '1' OU '0'
		int auxExit = 0;
		printf("\nTem certeza que deseja sair do programa? S/N: ");
		auxConfirmar = fconfirmarExit(getch());
		if(auxConfirmar == 1) { //SE A OPÇÃO FOR 'S' OU 's'
			exit(0); //FECHAR PROGRAMA
		}
		if(auxConfirmar == 0) { //SE A OPÇÃO FOR 'N' OU 'n'
			printf("\n\nENTER para voltar as OPCOES");
			printf("\nESC para sair do programa");
			fexit(getch()); //CHAMA A FUNÇÃO DE CONTROLE DE FECHAMENTO NOVAMENTE FAZENDO UM LAÇO DE REPETIÇÃO
		}
	}
	exe(&s, &valorS);
}
void validarPlaca() {
	int placaIgual;
	struct veiculo auxplaca;
	struct veiculo auxpop;
	struct pilha auxp;
	inicializar(&auxp);
	if(valorS.placa == 0) {
		printf("\nPLACA nao pode ser 0\n\n");
		printf("\nENTER para voltar as OPCOES");
		printf("\nESC para sair do programa");
		fexit(getch());
	}
	placaIgual = 0;
	auxplaca.placa = valorS.placa;
	while(!vazia(&s)) {
		auxpop = pop(&s);
		if(auxpop.placa == auxplaca.placa) {
			placaIgual = 1;
		}
		push(&auxp, auxpop);
	}
	while(!vazia(&auxp)) {
		auxpop = pop(&auxp);
		push(&s, auxpop);
	}
	if(placaIgual) {
		printf("\nPLACA ja existe no estacionamento! operacao cancelada\n\n");
		printf("\nENTER para voltar as OPCOES");
		printf("\nESC para sair do programa");
		fexit(getch());
	}
}
