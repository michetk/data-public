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
public class TestaProduto {
    public static void main(String[] args) {
        Produto produto = new Produto(10, "TV", "Peça", 1345);
        Estoque estoque = new Estoque(produto, 5);
        
        System.out.println("Codigo: " + produto.getCodigo() + ", Nome: " + produto.getNome() + ", Unidade de Medida: " + produto.getUnidadeMedida());
        System.out.println("Preço: " + produto.getProduto());
        System.out.println("Estoque -> Qtde " + estoque.getQtde() + " Prod: " + estoque.getProd());
    }
}
