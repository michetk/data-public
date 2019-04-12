/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package construcao;

/**
 *
 * @author 19052731
 */
public class Escritorio extends Apto {
    private double vendas;
    private double percentual;
    
    public Escritorio(double area, double precoMetro, int numeroQuartos, double vendas, double percentual) {
        super(area, precoMetro, numeroQuartos);
        this.vendas = vendas;
        this.percentual = percentual;
    }
    
    //set
    public void setVendas(double vendas) {
        this.vendas = vendas;
    }
    public void setPercentual(double percentual) {
        this.percentual = percentual;
    }
    
    //get
    public double getVendas() {
        return vendas;
    }
    public double getPercentual() {
        return percentual;
    }
    
    //metodos operacionais
    public String toString() {
        String s;
        s = super.toString() + " Vendas: " + vendas + " Percentual: " + percentual;
        return s;
    }
    public double obtemPrecoTotal() {
        double aux, vend;
        vend = vendas * percentual /100;
        aux = super.obtemPrecoTotal() + vend;
        return aux;
    }
    public void mostraDados() {
        System.out.println(toString());
        System.out.println("Preco Total: " + obtemPrecoTotal());
    }
}
