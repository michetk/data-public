/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Inicio;

/**
 *
 * @author 19052731
 */
public class testaAluno {
    public static void main(String args[]) {
        // criar um objeto da classe aluno
        Aluno aluno1 = new Aluno();
        aluno1.alteraNome("Joao");
        aluno1.alteraRgm(10);
        aluno1.alteraNota1(8);
        aluno1.alteraNota2(10);
        aluno1.mostraNome();
        aluno1.mostraMedia();
        
        Aluno aluno2 = new Aluno();
        aluno2.alteraNome("Maria");
        aluno2.alteraRgm(10);
        aluno2.alteraNota1(8);
        aluno2.alteraNota2(10);
        aluno2.mostraNome();
        aluno2.mostraMedia();
    }
}
