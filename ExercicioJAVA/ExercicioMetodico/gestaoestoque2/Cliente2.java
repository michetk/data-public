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
public class Cliente2 {
    private int id;
    private String nome;
    private String endereco;
    private String telefone;
    private int tipo;
    
    // set
    public void setId(int i) {
        id = i;
    }
    public void setNome(String n) {
        nome = n;
    }
    public void setEndereco(String e) {
        endereco = e;
    }
    public void setTelefone(String te) {
        telefone = te;
    }
    public void setTipo(int t) {
        if(t != 1 && t!= 2) {
            t = 1;
        }
        tipo = t;
    }
    // get
    public int getId() {
        return id;
    }
    public String getNome() {
        return nome;
    }
    public String getEndereco() {
        return endereco;
    }
    public String getTelefone() {
        return telefone;
    }
    public int getTipo() {
        return tipo;
    }
    // metodo construtor
    public Cliente2(int i, String n, String e, String te, int t) {
        id = i;
        nome = n;
        endereco = e;
        telefone = te;
        setTipo(t);
    }
}
