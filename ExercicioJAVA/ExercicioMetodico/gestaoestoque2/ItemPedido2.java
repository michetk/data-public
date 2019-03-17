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
public class ItemPedido2 {
    private Produto2 prod;
    private double preco;
    private int qtde;
    
    //set
    public void setProd(Produto2 p) {
        prod = p;
    }
    public void setPreco(double pr) {
        preco = pr;
    }
    public void setQtde(int q) {
        qtde = q;
    }
    
    //get
    public Produto2 getProd() {
        return prod;
    }
    public double getPreco() {
        return preco;
    }
    public int getQtde() {
        return qtde;
    }
}
