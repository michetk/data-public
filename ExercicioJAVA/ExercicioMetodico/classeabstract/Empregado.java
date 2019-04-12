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
public abstract class Empregado {
    private int codigo;
    private String nome;
    
    public Empregado(int codigo, String nome) {
        this.codigo = codigo;
        this.nome = nome;
    }
    //set
    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    //get
    public int getCodigo() {
        return codigo;
    }
    public  String getNome() {
        return nome;
    }
    
    //metodos operacionais
    public String toString() {
        String s;
        s = "Codigo: " + codigo + " Nome: " + nome;
        return s;
    }
    public abstract double obtemPagamento();
}
