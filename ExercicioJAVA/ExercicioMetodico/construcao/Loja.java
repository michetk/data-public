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
public class Loja extends Construcao {
    private double vendas;
    private double percTaxaComissao;
    
    public Loja(double area, double precoMetro, double vendas) {
        super(area, precoMetro);
        this.vendas = vendas;
        percTaxaComissao = 0.05;
    }
    
    //set
    public void setVendas(double vedas) {
        this.vendas = vendas;
    }
    
    //get
    public double getVendas() {
        return vendas;
    }
    public double getPercTaxaComissao() {
        return percTaxaComissao;
    }
    
    //metodos Operacionais
    public String toString() {
        String s;
        s = super.toString() + " Vendas: " + vendas + " Taxa Comissao: " + percTaxaComissao;
        return s;
    }
    public double obtemPrecoTotal() {
        double v;
        v = super.obtemPrecoTotal() + vendas * percTaxaComissao;
        return v;
    }
    public void mostraDados() {
        System.out.println(toString());
        System.out.println("Preco Total: " + obtemPrecoTotal());
    }
}
