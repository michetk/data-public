/*
*Gravar Caracteres em um Arquivo
*/

#include<stdio.h>
int main() {
	FILE *p;
	char carac;
	p = fopen("C:\\Users\\Michel M\\Documents\\GitHub\\Developement\\data-public\\ExercicioC\\exerciciosArquivos\\openCloseFile\\caract.dat", "a");
	if(p == NULL)
		printf("\nErro na abertura");
	else {
		printf("\nDigite um caractere: ");
		scanf("%c%*c", &carac);
		while(carac != 'f') {
			fputc(carac, p);
			if(ferror(p))
				printf("\nErro na gravação do caractere");
			else
				printf("\nGravacao realizada com sucesso");
			printf("\nDigite outro caractere: ");
			scanf("%c%*c", &carac);
			
		}
	}
	fclose(p);	
	getchar();
	return 0;
}
