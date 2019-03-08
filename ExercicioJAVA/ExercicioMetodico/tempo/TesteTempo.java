/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tempo;

/**
 *
 * @author Michel M
 */
public class TesteTempo {
    public static void main(String[] args) {
        Tempo t1 = new Tempo();
        t1.setHora(23);
        t1.setMinuto(59);
        t1.setSegundo(59);
        t1.setAno(2019);
        t1.setMes(12);
        t1.setDia(31);
        t1.getStrInv();
        t1.getStrVal();
        t1.getMensage();
        t1.incrementaSegundo();
        
        if(t1.getStrInv().equals(t1.getMensage()))
            System.out.println(t1.getMensage());
        else {
            System.out.println("HORAS: " + t1.getHora() + ":" + t1.getMinuto() + ":" + t1.getSegundo());
            System.out.println("DATA: " + t1.getDia() + "/" + t1.getMes() + "/" + t1.getAno());
        }
    }
}
