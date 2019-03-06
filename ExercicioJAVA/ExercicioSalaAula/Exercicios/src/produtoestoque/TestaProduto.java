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
public class TestaProduto {
    public static void main(String[] args) {
        Produto p1 = new Produto(10, "TV", "UND", 3454.32);
        Estoque e1 = new Estoque(p1, 5);
        System.out.println("Codigo: " + p1.getCodigo());
        System.out.println("Nome: " + p1.getNome());
        System.out.println("UnidadeMedida: " + p1.getUnidadeMedida());
        System.out.println("Preco: " + p1.getPreco());
        System.out.println("Estoque -> Prod: " + e1.getProd());
        System.out.println("Estoque -> Qtde: " + e1.getQtde());
        
    }
}
