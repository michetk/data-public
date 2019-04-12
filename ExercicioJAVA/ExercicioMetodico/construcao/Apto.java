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
public class Apto extends Construcao {
    private int numeroQuartos;
    
    public Apto(double area, double precoMetro, int numeroQuartos) {
        super(area, precoMetro);
        this.numeroQuartos = numeroQuartos;
    }

    //set
    public void setNumeroQuartos(int numeroQuartos) {
        this.numeroQuartos = numeroQuartos;
    }
    
    //get
    public int getNumeroQuartos() {
        return numeroQuartos;
    }
    
    //metodos
    public String toString() {
        String s;
        s = super.toString() + " Numero Quartos: " + numeroQuartos;
        return s;
    }
    public double obtemPrecoTotal() {
        double v;
        v = super.obtemPrecoTotal() * numeroQuartos;
        return v;
    }
    public void mostraDados() {
        System.out.println(super.toString());
        System.out.println(toString());
        System.out.println("Preco Total: " + obtemPrecoTotal());
    }
}
