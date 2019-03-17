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
public class ControleEstoque2 {
    private Estoque2 estoques[];
    
    //metodo construtor
    public ControleEstoque2(int tamanho) {
        estoques = new Estoque2[tamanho];
    }
    public void adicionaEstoque(Estoque2 e) {
        //inclui o parametro 'e' em um posicao livre do vetor estoques
        for (int i = 0; i < estoques.length; i++) {
            if(estoques[i] == null) {
                estoques[i] = e;
                return;
            }
        }
    }
    public void mostraProdutoEstoque() {
       for (int i = 0; i < estoques.length; i++) {
           if(estoques[i] != null) {
               System.out.println(estoques[i].getProd());
               System.out.println("Qtde: " + estoques[i].getQtde());
           }
       }
   }
}
