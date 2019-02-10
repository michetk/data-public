/*
Implementar a função LerValorValido que verifica se um valor
introduzido pelo usuário pertence ao conjunto limitado por dois
dados valores inteiros, devolvendo o primeiro valor que pertença
àquele intervalo
*/

#include<stdio.h>
#include<stdlib.h>

void lerValorValido(int n);

int main() {
	do{
		system("cls");
		int n;
		printf("Digite um Numero N: ");
		scanf("%d", &n);
		lerValorValido(n);
	
		system("pause");
	}while(1);
	
	return 0;
}

void lerValorValido(int n) {
	int i, a, b, t, pos;
	a = 10;
	b = 20;
	
	if (a >= b)
		if (n < b || n > a)
			printf("%d nao esta no intervalo predeterminado.\nO INTERVALO E DE %d a %d.\n", n, b, a);
		else {
			t = a + 1 - b;
			int v[t];
	
			if (a <= b)
				v[0] = a;
			else
				v[0] = b;
			
			for (i = 1; i <= t; i++) {
				v[i] = v[0] + i;
			}
			
			for (i = 0; i < t; i++) {
				if (n == v[i]) {
				pos = i+1;
				break;
				}
			}
			printf("O valor digitado foi %d e a posicao no intervalo de %d a %d e: %d\n", n, b, a, pos);
		}
		
	if (a <= b)
		if (n < a || n > b)
			printf("%d nao esta no intervalo predeterminado.\nO INTERVALO E DE %d a %d.\n", n, a, b);
		else {
			t = b + 1 - a;
			int v[t];
	
			if (a <= b)
				v[0] = a;
			else
				v[0] = b;
			
			for (i = 1; i <= t; i++) {
				v[i] = v[0] + i;
			}
			
			for (i = 0; i < t; i++) {
				if (n == v[i]) {
				pos = i+1;
				break;
				}
			}
			printf("O valor digitado foi %d e a posicao no intervalo de %d a %d e: %d\n", n, a, b, pos);
		}
}
