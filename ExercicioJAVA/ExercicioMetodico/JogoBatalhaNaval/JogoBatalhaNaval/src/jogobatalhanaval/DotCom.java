/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jogobatalhanaval;

/**
 *
 * @author miche
 */
public class DotCom {
    private int[] localCelulas;
    private int numeroPontos = 0;
    
    public void setLocalCelulas(int[] localCelulas) {
        this.localCelulas = localCelulas;
    }
    
    public String conferePalpite(String palpiteUsuario) {
        int palpite = Integer.parseInt(palpiteUsuario);
        String resultado = "miss";
        
        for(int celula : localCelulas) {
            if(palpite == celula) {
                resultado = "hit";
                numeroPontos++;
                break;
            }
        }
        
        if(numeroPontos == localCelulas.length)
            resultado = "kill";
        
        System.out.println(resultado);
        return resultado;
    }
}
