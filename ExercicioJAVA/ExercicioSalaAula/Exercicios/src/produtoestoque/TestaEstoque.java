/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package produtoestoque;

/**
 *
 * @author Michel M
 */
public class TestaEstoque {
    public static void main(String[] args) {
        Produto p1 = new Produto(10, "VENTILADOR", "UND", 567);
        Estoque e1 = new Estoque(p1, 20);
        Estoque e2 = new Estoque(new Produto(43, "ESCOVA CABELO", "UND", 145.55), 54);
        
        ControleEstoque ce = new ControleEstoque(100);
        ce.adicionaEstoque(e1);
        ce.adicionaEstoque(e2);
        ce.mostraProdutoEstoque();
    }
}
