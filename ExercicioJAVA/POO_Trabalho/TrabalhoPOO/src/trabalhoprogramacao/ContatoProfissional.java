/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalhoprogramacao;

/**
 *
 * @author 19052731
 */
public class ContatoProfissional extends Contato {
    private int ramal;
    private String ramoEmpresa;

    public ContatoProfissional(int ramal, String ramoEmpresa, String nome, String endereco, String telefone) {
        super(nome, endereco, telefone);
        this.ramal = ramal;
        this.ramoEmpresa = ramoEmpresa;
    }

    //set

    public void setRamal(int ramal) {
        this.ramal = ramal;
    }

    public void setRamoEmpresa(String ramoEmpresa) {
        this.ramoEmpresa = ramoEmpresa;
    }

    //get

    public int getRamal() {
        return ramal;
    }

    public String getRamoEmpresa() {
        return ramoEmpresa;
    }
    
}
