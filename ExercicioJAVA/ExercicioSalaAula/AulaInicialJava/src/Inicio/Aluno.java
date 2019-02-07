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
public class Aluno {

    int rgm;
    String nome;
    private double nota1;
    private double nota2;

    void alteraNome(String n) {
        nome = n;
    }

    void mostraNome() {
        System.out.println("Nome: " + nome);
    }

    void alteraRgm(int n) {
        rgm = n;
    }

    void mostraRgm() {
        System.out.println("Rgm: " + rgm);
    }

    void alteraNota1(double n1) {
        if (n1 >= 0 && n1 <= 10) {
            nota1 = n1;
        } else {
            nota1 = 0;
        }
    }

    void alteraNota2(double n2) {
        if (n2 >= 0 && n2 <= 10) {
            nota2 = n2;
        } else {
            nota2 = 0;
        }
    }
    
    void mostrarNota1() {
        System.out.println("Nota 1: " + nota1);
    }
    
    void mostrarNota2() {
        System.out.println("Nota 2: " + nota2);
    }
    
    double calculaMedia() {
        double m;
        m = (nota1 + nota2) / 2;
        return m;
    }
    
    void mostraMedia() {
        System.out.println("Media: " + calculaMedia());
    }
}
