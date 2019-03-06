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
public class TestaEstoque {
    public static void main(String[] args) {
        Produto p1 = new Produto(10, "NOTE", "PECA", 3820.71);
        Estoque e1 = new Estoque(p1, 20);
        Estoque e2 = new Estoque(new Produto(20, "TV", "PECA", 2345.43), 50);
        //System.out.println("ESTOQUE -> PROD: " + e1.getProd());
        //System.out.println("Estoque -> QTDE: " + e1.getQtde());
        
        ControleEstoque ce = new ControleEstoque(100);
        ce.adicionaEstoque(e1);
        ce.adicionaEstoque(e2);
        ce.mostraProdutosEstoque();
    }
}
