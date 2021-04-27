package TrabProg3;

import java.util.ArrayList;
import java.util.Date;

public class Eleicao {

	int numeroVagasEleicao; 
	private ArrayList <Partidos> partidosEleicao;
	private ArrayList <Candidatos> eleitosProporcionalmente;
	private ArrayList <Candidatos> maisVotados;
	private ArrayList <Candidatos> eleitosMajoritariamente;
	private ArrayList <Candidatos> naoEleitosMajoritariamente; 
	private Date dataEleicao;
	private int qtdVagas; 
	
	public Eleicao() {
		super();
		this.numeroVagasEleicao = numeroVagasEleicao;
		this.partidosEleicao = new ArrayList <Partidos>();
		this.eleitosProporcionalmente = new ArrayList <Candidatos>();
		this.maisVotados = new ArrayList<Candidatos>();
		this.eleitosMajoritariamente = new ArrayList <Candidatos>();
		this.naoEleitosMajoritariamente = new ArrayList <Candidatos>();
		this.dataEleicao = dataEleicao;
	}

	public int getNumeroVagasEleicao() {
		return numeroVagasEleicao;
	}

	public void setNumeroVagasEleicao(int numeroVagasEleicao) {
		this.numeroVagasEleicao = numeroVagasEleicao;
	}

	public ArrayList<Partidos> getPartidosEleicao() {
		return partidosEleicao;
	}

	public void setPartidosEleicao(ArrayList<Partidos> partidosEleicao) {
		this.partidosEleicao = partidosEleicao;
	}

	public ArrayList<Candidatos> getEleitosProporcionalmente() {
		return eleitosProporcionalmente;
	}
	public void setEleitosProporcionalmente(ArrayList<Candidatos> eleitosProporcionalmente) {
		this.eleitosProporcionalmente = eleitosProporcionalmente;
	}
	public ArrayList<Candidatos> getMaisVotados() {
		return maisVotados;
	}
	public void setMaisVotados(ArrayList<Candidatos> maisVotados) {
		this.maisVotados = maisVotados;
	}
	public ArrayList<Candidatos> getEleitosMajoritariamente() {
		return eleitosMajoritariamente;
	}
	public void setEleitosMajoritariamente(ArrayList<Candidatos> eleitosMajoritariamente) {
		this.eleitosMajoritariamente = eleitosMajoritariamente;
	}
	public ArrayList<Candidatos> getNaoEleitosMajoritariamente() {
		return naoEleitosMajoritariamente;
	}
	public void setNaoEleitosMajoritariamente(ArrayList<Candidatos> naoEleitosMajoritariamente) {
		this.naoEleitosMajoritariamente = naoEleitosMajoritariamente;
	}
	public Date getDataEleicao() {
		return dataEleicao;
	}
	public void setDataEleicao(Date dataEleicao) {
		this.dataEleicao = dataEleicao;
	}
	public void addPartido(Partidos p) {
		this.partidosEleicao.add(p);	
	}
	
	public Partidos retornaPartidoPeloNum(int x) {
		for(Partidos p : this.partidosEleicao) {
			if(x == p.getNumeroPartido()) {
				return p;
			}
		}
		return null;
	}

	public int getQtdVagas() {
		return qtdVagas;
	}

	public void setQtdVagas(int qtdVagas) {
		this.qtdVagas = qtdVagas;
	}
}
