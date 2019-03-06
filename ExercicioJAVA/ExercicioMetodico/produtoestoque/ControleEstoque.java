/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Inicio;

/**
 *
 * @author 19052731
 */
public class ControleEstoque {
    private Estoque estoques[];
    
    public ControleEstoque(int tamanho) {
        estoques = new Estoque[tamanho];
    }
    public void adicionaEstoque(Estoque e) {
        //inclui o parametro 'e' em um posicao livre do vetor estoques
        int i;
        for (i = 0; i < estoques.length; i++) {
            if(estoques[i] == null) {
                estoques[i] = e;
                break;
            }
        }
        if(i == estoques.length) {
            System.out.println("Não foi possível incluir. Vetor cheio");
        }
    }
    public void mostraProdutosEstoque() {
        int i;
        for (i = 0; i < estoques.length; i++) {
            if(estoques[i] != null) {
                System.out.println("Produto: " + estoques[i].getProd());
                System.out.println("QTDE: " + estoques[i].getQtde());
            }
        }
    }
}
