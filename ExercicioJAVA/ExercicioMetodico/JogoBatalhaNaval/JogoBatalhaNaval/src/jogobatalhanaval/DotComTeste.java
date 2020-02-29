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
public class DotComTeste {
    public static void main(String[] args) {
        DotCom dot = new DotCom();
        int local[] = {2,3,4};

        dot.setLocalCelulas(local);

        String palpiteUsuario = "0";
        String resultado = dot.conferePalpite(palpiteUsuario);
        
        palpiteUsuario = "4";
        resultado = dot.conferePalpite(palpiteUsuario);
        
        palpiteUsuario = "3";
        resultado = dot.conferePalpite(palpiteUsuario);
    }
}
