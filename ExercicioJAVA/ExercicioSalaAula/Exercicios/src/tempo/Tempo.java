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
public class Tempo {
    private int hora;
    private int minuto;
    private int segundo;
    private int ano;
    private int mes;
    private int dia;
    
    public void setHora(int h) {
        if(h >= 0 || h <= 23)
            hora = h;
        else
            integer.toString(hora);
            
    }
    public void setMinuto(int m) {
        if(m >= 0 || m <= 59)
            minuto = m;
        else
            minuto = 0;
    }
    public void setSegundo(int s) {
        if(s >= 0 || s <= 59)
            segundo = s;
        else
            segundo = 0;
    }
    public void setAno(int a) {
        if(a > 1)
            ano = a;
        else
            ano = 0;
    }
    public int getHora() {
        return hora;
    }
    public int getMinuto() {
        return minuto;
    }
    public int getSegundo() {
        return segundo;
    }
    public void incrementaSegundo() {
        segundo++;
        if(segundo > 59) {
            segundo = 0;
            minuto++;
            if(minuto > 59) {
                minuto = 0;
                hora++;
                if(hora > 23)
                    hora = 0;
            }
        }
    }
    public void decrementaSegundo() {
        segundo--;
        if(segundo < 0) {
            segundo = 59;
            minuto--;
            if(minuto < 0) {
                minuto = 59;
                hora--;
                if(hora < 0)
                    hora = 23;
            }
        }            
    }
}
