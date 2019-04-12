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
public class PorHora extends Empregado{
    private double numeroHoras;
    private double valorHora;
    
    public PorHora(int codigo, String nome, double numeroHoras, double valorHora) {
        super(codigo, nome);
        this.numeroHoras = numeroHoras;
        this.valorHora = valorHora;
    }
    
    //set
    public void setNumeroHoras(double numeroHoras) {
        this.numeroHoras = numeroHoras;
    }
    public void setValorHora(double valorHora) {
        this.valorHora = valorHora;
    }
    
    //get
    public double getNumeroHoras() {
        return numeroHoras;
    }

    public double getValorHora() {
        return valorHora;
    }
    
    //metodos operacionais
    public String toString() {
        String s;
        s = super.toString() + " NumeroHoras: " + numeroHoras + " ValorHora: " + valorHora;
        return s;
    }
    public double obtemPagamento() {
        double valor;
        valor = numeroHoras * valorHora;
        return valor;
    }
    
    
}
