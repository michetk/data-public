/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalhoprogramacao;

/**
 *
 * @author 19052731
 */
public class Data {
    private int dia;
    private int mes;
    private int ano;

    //get
    public int getDia() {
        return dia;
    }

    public int getMes() {
        return mes;
    }

    public int getAno() {
        return ano;
    }
    
    //operacionais
    public int anoBissesto(int a) {
        if((a % 4 == 0 && !(a % 100 == 0) || a % 400 == 0))
            return 1;
        else
            return 0;
    }
    public void alteraData(int dia, int mes, int ano) {
        if((dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1919)
                || ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
                || (mes == 2 && dia > 29)
                || (mes == 2 && dia == 29 && anoBissesto(ano) == 0)) {
            System.out.println("Data Invalida!");
        }
            else {
                this.dia = dia;
                this.mes = mes;
                this.ano = ano;
            }
        }
    public boolean comparaData(Data data) {
        return true;
    }
    public boolean comparaDiaMes(Data data) {
        return true;
    }
    public String toString() {
        String formatDia = String.format("%02d", dia);
        String formatMes = String.format("%02d", mes);
        String formatAno = String.format("%02d", ano);
        String s;
        s = formatDia + "/" + formatMes + "/" + formatAno;
        return s;
    }
}
