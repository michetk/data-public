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
    private String mensage;
    private String str_inv;
    private String str_val;
    
    //METODOS SET
    public void setHora(int h) {
        if(h >= 0 && h <= 23)
            hora = h;
        else
            hora = -1;
    }
    public void setMinuto(int m) {
        if(m >= 0 && m <= 59)
            minuto = m;
        else
            minuto = -1;
    }
    public void setSegundo(int s) {
        if(s >= 0 && s <= 59)
            segundo = s;
        else
            segundo = -1;
    }
    public void setAno(int a) {
        if(a >= 1)
            ano = a;
        else
            ano = -1;
    }
    public void setMes(int m) {
        if(m >= 1 && m <= 12)
            mes = m;
        else
            mes = -1;
    }
    public void setDia(int d) {
        if (d >= 1 && (((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && d <= 31) || ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && d <= 30)))
            dia = d;
        else
            if(mes == 2 && (d >= 1 && d <= 28 ))
                dia = d;
            else
                if(mes == 2 && d == 29 && ((ano % 4 == 0 && !(ano % 100 == 0)) || (ano % 100 == 0 && ano % 400 == 0))) {
                    dia = d;
                }
        else
            dia = -1;
    }
    
    // METODOS GET
    public int getHora() {
        if(hora >= 0 || hora <= 23)
            return hora;
        else
            return hora = 0;
    }
    public int getMinuto() {
        return minuto;
    }
    public int getSegundo() {
        return segundo;
    }
    public int getAno() {
        return ano;
    }
    public int getMes() {
        return mes;
    }
    public int getDia() {
        return dia;
    }
    public String getStrInv() {
        return str_inv = "DADO INVÁLIDO!";
    }
    public String getStrVal() {
        return str_val = "DADO VÁLIDO";
    }
    public String getMensage() {
        if(segundo == -1 || minuto == -1 || hora == -1 || dia == -1 || mes == -1 || ano == -1)
            return mensage = str_inv;
        else
            return mensage = str_val;
    }
    
    // METODOS DE MANIPULAÇÃO
    public void incrementaSegundo() {
        segundo++;
        if(segundo > 59) {
            segundo = 0;
            minuto++;
            if(minuto > 59) {
                minuto = 0;
                hora++;
                if(hora > 23) {
                    hora = 0;
                    dia++;
                    if(((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia > 31) || ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)) {
                        dia = 1;
                        mes++;
                    }
                    else
                        if(mes == 2 && (dia >= 1 && dia <= 28 )) {
                        dia = 1;
                        mes++;
                    }
                        else
                            if(mes == 2 && dia == 29 && ((ano % 4 == 0 && !(ano % 100 == 0)) || (ano % 100 == 0 && ano % 400 == 0))) {
                                dia = 1;
                                mes++;
                    }
                    if(mes > 12) {
                        mes = 1;
                        ano++;
                    }
                }
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
