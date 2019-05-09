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
public class TestaData {
    public static void main(String[] args) {
        Data d = new Data();

        d.alteraData(8,5,2019);
        System.out.println("Data: " + d.toString());
    }
}
