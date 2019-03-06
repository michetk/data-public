/*
 * 
 */
package Inicio;

/**
 *
 * @author 19052731
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
    
    public double getProduto() {
        return preco;
    }
    public String toString() {
        String s;
        s="Produto { codigo = " + codigo + ", nome = " + nome + ", UM = " + unidadeMedida + ", preco = " + preco + "}";
        return s;
    }
    
}
