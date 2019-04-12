/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package classeabstract;

/**
 *
 * @author 19052731
 */
public class PorComissao extends Empregado {
    private double vendas;
    private double percentualComissao;
    
    public PorComissao(int codigo, String nome, double vendas, double percentualComissao) {
        super(codigo, nome);
        this.vendas = vendas;
        this.percentualComissao = percentualComissao;
    }
    
    //set
    public void setVendas(double vendas) {
        this.vendas = vendas;
    }
    public void setPercentualComissao(double percentualComissao) {
        this.percentualComissao = percentualComissao;
    }
    
    //get
    public double getVendas() {
        return vendas;
    }
    public double getPercentualComissao() {
        return percentualComissao;
    }
    
    //metodos operacionais
    public String toString() {
        String s;
        s = super.toString() + " Vendas: " + vendas + " Percentual Comissao: " + percentualComissao;
        return s;
    }
    public double obtemPagamento() {
        double valor;
        valor = vendas * percentualComissao / 100;
        return valor;
    }
}
