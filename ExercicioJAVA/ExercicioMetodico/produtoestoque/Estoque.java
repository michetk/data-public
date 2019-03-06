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
public class Estoque {
    private Produto prod;
    private int qtde;
    
    public Estoque(Produto p, int q) {
        prod = p;
        qtde = q;
    }
    
    public Produto getProd() {
        return prod;
    }
    public int getQtde() {
        return qtde;
    }
    
    void entrada(int valor) {
        qtde += valor;
    }
    void saida(int valor) {
        if(valor > qtde)
            System.out.println("VALOR MAIOR QUE QTDE");
        else
            qtde = qtde - valor;
    }
}
