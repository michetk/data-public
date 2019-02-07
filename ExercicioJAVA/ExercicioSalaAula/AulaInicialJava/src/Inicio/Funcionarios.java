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
public class Funcionarios {
    private int codigo;
    private String nome;
    private String cargo;
    private double salario;
    private float aumento;
    
    void alteraNome(String n) {
        nome = n;
    }
    void alteraCodigo(int c) {
        codigo = c;
    }
    void alteraCargo(String c) {
        cargo = c;
    }
    void alteraSalario(double s) {
        salario = s;
        if (salario < 0)
            salario = 0;
    }
    void aumentaSalario(float a) {
        aumento = a;
        salario = salario + (salario * a / 100);
    }
    
    void mostraAumentaSalario() {
        System.out.println("Aumento Salarial: %" + aumento);
    }
    
    void mostraNome() {
        System.out.println("Nome: " + nome);
    }
    void mostraCodigo() {
        System.out.println("Codigo: " + codigo);
    }
    void mostraCargo() {
        System.out.println("Cargo: " + cargo);
    }
    void mostraSalario() {
        System.out.println("Salario: " + salario);
    }
}
