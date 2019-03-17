/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gestaoestoque2;

/**
 *
 * @author Michel M
 */
public class Estoque2 {
    private Produto2 prod;
    private int qtde;
    
    // set
    public void setProd(Produto2 p) {
        prod = p;
    }
    public void setQtde(int q) {
        qtde = q;
    }
    // get
    public Produto2 getProd() {
        return prod;
    }
    public int getQtde() {
        return qtde;
    }
    // metodo construtor
    public Estoque2(Produto2 p, int q) {
        prod = p;
        qtde = q;
    }
    void entradaQtde(int q) {
        qtde = qtde + q;
    }
    void saidaQtde(int q) {
        if(q > qtde)
            System.out.println("Qtde em estoque menor que a saida desejada");
        else
            qtde = qtde - q;
    }
}
