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
public class testaFuncionarios {
    public static void main(String args[]) {
        Funcionarios f1 = new Funcionarios();
        f1.alteraNome("João");
        f1.alteraCodigo(12);
        f1.alteraCargo("Quimico");
        f1.alteraSalario(520.00);
        f1.mostraNome();
        f1.mostraSalario();
        f1.aumentaSalario(10);
        f1.mostraAumentaSalario();
        f1.mostraSalario();
    }
}
