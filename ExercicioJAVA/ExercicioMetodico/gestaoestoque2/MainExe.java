/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gestaoestoque2;

import java.util.Scanner;
 
public class MainExe {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int cap;
        
        Produto2 tv = new Produto2(01, "TV", "UND", 2455.89);
        Produto2 vt = new Produto2(02, "Ventilador", "UND", 546.77);
        
        Estoque2 a = new Estoque2(tv, 25);
        Estoque2 b = new Estoque2(vt, 37);
        
        ControleEstoque2 ce;
        
        System.out.println("GESTÃO E CONTROLE DE ESTOQUE\n\n\n");
        
        System.out.println("Quantidade de estoque suportado: ");
        cap = 0;
        cap  = s.nextInt();
        ce = new ControleEstoque2(cap);
        
        if(cap == 0) {
            System.out.println("\nNão existe Estoque");
        }
        else {
            ce.adicionaEstoque(a);
            }
        }
    }
}
