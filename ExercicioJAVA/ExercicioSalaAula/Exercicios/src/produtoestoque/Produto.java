/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package produtoestoque;

/**
 *
 * @author Michel M
 */
public class Produto {
    private int codigo;
    private String nome;
    private String unidadeMedida;
    private double preco;
    public Produto(int c, String n, String um, double p) {
        codigo = c;
        nome = n;
        unidadeMedida = um;
        preco = p;
    }
    public int getCodigo() {
        return codigo;
    }
    public String getNome() {
        return nome;
    }
    public String getUnidadeMedida() {
        return unidadeMedida;
    }
    public double getPreco() {
        return preco;
    }
    public String toString() {
        String s;
        s = "codigo = " + codigo
                + ", nome = " + nome 
                + ", unidadeMedida = " + unidadeMedida 
                + ", preco = " + preco;
        return s;
    }
}
