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
public class Agenda {
    private Contato contatos[] = new Contato[100];
	
    
    //metodos operacionais
    public int contaContatos() {
        int contador = 0;
        for(int i = 0; i < contatos.length; i++) {
            if(contatos[i] != null)
                contador++;
        }
        return contador;
    }
    public void adicionaContato(Contato contato) {
    if(contaContatos() == contatos.length)
        System.out.println("\nLista contatos cheia!");
        else
            for(int i = 0; i < contatos.length; i++) {
                if(contatos[i] == null) {
                    contatos[i] = contato;
                    break;
                }
            }
    }
    public void retiraContato(String nome) {
		if(contaContatos() == 0)
			System.out.println("\nLista contatos vazia!");
		else
			for(int i = 0; i < contatos.length; i++) {
				if(contatos[i].getNome() == nome) {
					contatos[i] = null;
					break;
				}
			}
    }
    public void mostraContatoPessoal() {
        int contador = 0;
        if(contaContatos() == 0)
            System.out.println("\nLista contatos vazia!");
        for(int i = 0; i < contatos.length; i++) {
            if(contatos[i] instanceof ContatoPessoal) {
                System.out.println("\nContato Pessoal: " + contatos[i].toString());
                contador++;
            }
        }
        if(contador == 0)
            System.out.println("\nNão existem contatos pessoais!");
    }
    public void mostraContatoProfissional() {
		int contador = 0;
		if(contaContatos() == 0)
			System.out.println("\nLista contatos vazia!");
		for(int i = 0; i < contatos.length; i++) {
			if(contatos[i] instanceof ContatoProfissional) {
				System.out.println("\nContato Profissional: " + contatos[i].toString());
				contador++;
			}
		}
		if(contador == 0)
			System.out.println("\nNão existem contatos profissionais!");
    }
    public Contato buscaContato(String nome) {
		if(contaContatos() == 0)
			System.out.println("\nLista contatos vazia!");
		for(int i = 0; i < contatos.length; i++) {			
			if(contatos[i].getNome() == nome)
				return contatos[i];
		}
		return null;
		
    }
    public void mostraAniversariates(Data dataAniversario) {
        int contador = 0;
		if(contaContatos() == 0)
			System.out.println("\nLista contatos vazia!");
		for(int i = 0; i < contatos.length; i++) {
			if(contatos[i] instanceof ContatoPessoal) {
                            ContatoPessoal cp;
                            cp = (ContatoPessoal)contatos[i];
                            if(cp.getDataNascimento().comparaDiaMes(dataAniversario)) {
					System.out.println("\nContato Pessoal: " + contatos[i].toString());
					contador++;
				}
			}
		}
		if(contador == 0)
			System.out.println("\nNão existem contatos pessoais!");
		
			
    }
    public void empresaRamo(String ramoEmpresa) {
        int contador = 0;
		if(contaContatos() == 0)
			System.out.println("\nLista contatos vazia!");
		for(int i = 0; i < contatos.length; i++) {
                    ContatoProfissional cp;
                    cp = (ContatoProfissional)contatos[i];
			if(contatos[i] instanceof ContatoProfissional) {
				if(cp.getRamoEmpresa() == ramoEmpresa) {
					System.out.println("\nContato Profissional: " + contatos[i].toString());
					contador++;
				}
			}
		}
		if(contador == 0)
			System.out.println("\nNão existem contatos profissionais!");
    }
}
