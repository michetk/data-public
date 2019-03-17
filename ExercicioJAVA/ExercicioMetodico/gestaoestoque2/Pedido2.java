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
public class Pedido2 {
    private int numero;
    private Cliente2 cli;
    private ItemPedido2 item[] = new ItemPedido2[10];
    private String dataPedido;
    private String situacao;
    
    //metodo construtor
    public Pedido2(int n, Cliente2 c, String dp) {
        numero = n;
        cli = c;
        dataPedido = dp;
        situacao = "Aberto";
    }
    
    //set
    public void setNumero(int n) {
        numero = n;
    }
    public void setCli(Cliente2 c) {
        cli = c;
    }
    public void setDataPedido(String dp) {
        dataPedido = dp;
    }
    public void setSituacao(String s) {
        situacao = s;
    }
    
    //get
    
    public int getNumero() {
        return numero;
    }
    public Cliente2 getCli() {
        return cli;
    }
    public String getDataPedido() {
        return dataPedido;
    }
    public String getSituacao() {
        return situacao;
    }
    
    //funcoes
    public void adicionaItemPedido(ItemPedido2 it) {
        for (int i = 0; i < item.length; i++) {
            if(item[i] == null)
                item[i] = it;
                return;
        }
    }
    public boolean cancelaPedido() {
        // opedido só pode ser cancelado se estiver com a situação "Aberto"
        // se conseguir cancelar retorna true, senão false
        if(situacao.equals("Aberto")) {
            situacao = "Cancelado";
            return true;
        }
        return false;
    }
    public boolean fechaPedido() {
        // o pedido só pode ser fechado se estivdr com a situação "Aberto"
        // se conseguir fechar retona true, senao false
        if(situacao.equals("Aberto")) {
            situacao = "Fechado";
            return true;
        }    
        return false;
    }
    public ItemPedido2 obtemPedido(int codigoProduto) {
        // esse metodo percorre o vetor itens e tenta encontrar um item cujo produto tenha o codigo
        // igual ao parametro codigoProduto. Se encontrar, retorna o item, se não encontrar retorna null
        for (int i = 0; i < item.length; i++) {
            if(item[i] != null) {
                if(item[i].getProd().getCodigo() == codigoProduto) {
                    return item[i];
                }
            }
        }
        return null;
    }
}
