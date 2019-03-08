/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package funcaomenorelementovetor;

/**
 *
 * @author Michel M
 */
public class FuncaoMenorElementoVetor {

    private static int calculaMenor (int a[], int n) {
        int i, menor;
        menor = a[0];
        for(i = 1; i < n; i++) {
            if (a[i] < menor)
                menor = a[i];
        }
        return menor;
    }
    public static void main(String[] args) {
        int a[] = {5,4,3,2,1};
        int t = a.length;
        int menor;
        
        menor = calculaMenor(a, t);
        System.out.println(menor);
    }
}
