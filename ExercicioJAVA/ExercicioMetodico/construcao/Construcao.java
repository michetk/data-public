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
public class Construcao {
    private double area;
    private double precoMetro;
    
    
    public Construcao(double area, double precoMetro) {
        this.area = area;
        this.precoMetro = precoMetro;
    }
    
    //set
    public void setArea(double area) {
        this.area = area;
    }
    public void setPrecoMetro(double precoMetro) {
        this.precoMetro = precoMetro;
    }
    
    //get
    public double getArea() {
        return area;
    }
    public double getPrecoMetro() {
        return precoMetro;
    }
    
    //metodos Operacionais
    public String toString() {
        String s;
        s = "Area: " + area + " Preco Metro: " + precoMetro;
        return s;
    }
    public double obtemPrecoTotal() {
        double a, p, t; //variaveis para retornar o obtemPrecoTotal
        a = area;
        p = precoMetro;
        t = a * p;
        return t;
    }
    public void mostraDados() {
        System.out.println(toString());
        System.out.println("Preco Total: " + obtemPrecoTotal());
    }
}
