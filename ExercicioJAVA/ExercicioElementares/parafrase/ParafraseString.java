/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package parafrase;

/**
 *
 * @author Michel M
 */
public class ParafraseString {
    public static void main(String[] args) {
        //CRIANDO PALAVRAS
        String[] palavraListaUm = {"vazer", "corromper", "olhara para", "não deixar que", "chamar para", "batendo", "correndo para"};
        String[] palavraListaDois = {"cachorro", "todos", "qualquer", "mais dois", "25/12", "33.000 pessoas", "nenhuma", "programação"};
        String[] palavraListaTres = {"desse jeito", "fim", "desfecho da opera", "nada mais", "parando por aqui", "sem explicação", "para a vovó"};
        //CAPTURANDO QUANTIDADE
        int lengthUm = palavraListaUm.length;
        int lengthDois = palavraListaDois.length;
        int lengthTres = palavraListaTres.length;
        //CRIANDO NUMERO ALEATORIO
        int rand1 = (int) (Math.random() * lengthUm);
        int rand2 = (int) (Math.random() * lengthDois);
        int rand3 = (int) (Math.random() * lengthTres);
        //CONSTRUIR FRASE
        String frase = palavraListaUm[rand1] + " " + palavraListaDois[rand2] + " " + palavraListaTres[rand3];
        //ESCREVER MENSAGEM
        System.out.println("Frase: " + frase);
    }
}
