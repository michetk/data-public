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
public class ContatoPessoal extends Contato {
    private String profissao;
    private Data dataNascimento;

    public ContatoPessoal(String profissao, Data dataNascimento, String nome, String endereco, String telefone) {
        super(nome, endereco, telefone);
        this.profissao = profissao;
        this.dataNascimento = dataNascimento;
    }

    //set
    public void setProfissao(String profissao) {
        this.profissao = profissao;
    }

    public void setDataNascimento(Data dataNascimento) {
        this.dataNascimento = dataNascimento;
    }

    //get
    public String getProfissao() {
        return profissao;
    }

    public Data getDataNascimento() {
        return dataNascimento;
    }
    
    
}
