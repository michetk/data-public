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
public class Main {
    public static void main(String[] args) {
        Agenda ag = new Agenda();
        Contato cont[] = new Contato[4];
        Data d = new Data(23,4,1990);
        cont[0] = new ContatoPessoal("Miguel", "Rua Miragaia", "999999", "Vendedor", d);
        cont[1] = new ContatoPessoal("Jessika", "Rua Kabb", "999999", "JogadorFutebol", d);
        cont[2] = new ContatoProfissional("Karlos", "Rua Herioval", "999999", 1145, "Deposito");
        cont[3] = new ContatoProfissional("Mirela", "Rua Cabral", "999999", 1245, "ADM");
        
        for(int i = 0; i < cont.length; i++) {
            ag.adicionaContato(cont[i]);
        }
        
        //ag.mostraAniversariates(d);
        ag.empresaRamo("Deposito");
        
        //ag.mostraContatoPessoal();
        //ag.mostraContatoProfissional();
        
    }
}
