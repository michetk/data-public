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
public class TestaVetor {
    public static void main(String[] args) {
        int a[] = new int[10];
        for (int i = 0; i < 10; i++) {
            a[i] = i*i;
        }
        for (int i = 0; i < a.length; i++) {
            System.out.println("a["+i+"] = "+a[i]);
        }
    }
}
