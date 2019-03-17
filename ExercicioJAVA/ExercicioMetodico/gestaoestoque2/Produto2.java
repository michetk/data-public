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
public class Produto2 {
    private int codigo;
    private String nome;
    private String unidadeMedida;
    private double preco;
    // metodo construtor
    public Produto2(int c, String n, String um, double p) {
        codigo = c;
        nome = n;
        unidadeMedida = um;
        preco = p;
    }

    Produto2() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    // SET
    public void setCodigo(int c) {
        codigo = c;
    }
    public void setNome(String n) {
        nome = n;
    }
    public void setUnidadeMedida(String um) {
        unidadeMedida = um;
    }
    public void setPreco(double p) {
        preco = p;
    }
    // GET
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
    // metodo da biblioteca java para impressao
    public String toString() {
        String s;
        s = "Produto: " + codigo
                + "\nNome: " + nome
                + "\nUnidadeMedida: " + unidadeMedida
                + "\nPreco: " + preco;
        return s;
    }
}
