// package TrabProg3;


#include <iostream>
#include <string>
#include <list>

#include "Candidatos.hpp";

using namespace std;

class Eleicao {
	private:
	int numeroVagasEleicao; 
	// ArrayList <Partidos> partidosEleicao;
	list<Partidos> partidosEleicao;
	// ArrayList <Candidatos> eleitosProporcionalmente;
	list<Candidatos> eleitosProporcionalmente;
	// ArrayList <Candidatos> maisVotados;
	list<Candidatos> maisVotados;
	// ArrayList <Candidatos> eleitosMajoritariamente;
	list<Candidatos> eleitosMajoritariamente;
	// ArrayList <Candidatos> naoEleitosMajoritariamente; 
	list<Candidatos> naoEleitosMajoritariamente;
	Date dataEleicao;
	int qtdVagas; 
	

	public:
	Eleicao() {
		this.numeroVagasEleicao = numeroVagasEleicao;
		this.partidosEleicao = partidosEleicao;
		this.eleitosProporcionalmente = eleitosProporcionalmente;
		this.maisVotados = maisVotados;
		this.eleitosMajoritariamente = eleitosMajoritariamente;
		this.naoEleitosMajoritariamente = naoEleitosMajoritariamente;
		this.dataEleicao = dataEleicao;
	}

	int getNumeroVagasEleicao() {
		return numeroVagasEleicao;
	}

	void setNumeroVagasEleicao(int numeroVagasEleicao) {
		this.numeroVagasEleicao = numeroVagasEleicao;
	}

	list<Partidos> getPartidosEleicao() {
		return partidosEleicao;
	}

	void setPartidosEleicao(list<Partidos> partidosEleicao) {
		this.partidosEleicao = partidosEleicao;
	}

	list<Candidatos> getEleitosProporcionalmente() {
		return eleitosProporcionalmente;
	}
	void setEleitosProporcionalmente(list<Candidatos> eleitosProporcionalmente) {
		this.eleitosProporcionalmente = eleitosProporcionalmente;
	}
	list<Candidatos> getMaisVotados() {
		return maisVotados;
	}
	void setMaisVotados(list<Candidatos> maisVotados) {
		this.maisVotados = maisVotados;
	}
	list<Candidatos> getEleitosMajoritariamente() {
		return eleitosMajoritariamente;
	}
	void setEleitosMajoritariamente(list<Candidatos> eleitosMajoritariamente) {
		this.eleitosMajoritariamente = eleitosMajoritariamente;
	}
	list<Candidatos> getNaoEleitosMajoritariamente() {
		return naoEleitosMajoritariamente;
	}
	void setNaoEleitosMajoritariamente(list<Candidatos> naoEleitosMajoritariamente) {
		this.naoEleitosMajoritariamente = naoEleitosMajoritariamente;
	}
	Date getDataEleicao() {
		return dataEleicao;
	}
	void setDataEleicao(Date dataEleicao) {
		this.dataEleicao = dataEleicao;
	}
	void addPartido(Partidos p) {
		this.partidosEleicao.add(p);	
	}
	
	Partidos retornaPartidoPeloNum(int x) {
		for(this.partidosEleicao = Partidos.begin(); this.partidosEleicao != Partidos.end(); ++this.partidosEleicao) {
			if(x == p.getNumeroPartido()) {
				return p;
			}
		}
		return NULL;
	}

	int getQtdVagas() {
		return qtdVagas;
	}

	void setQtdVagas(int qtdVagas) {
		this.qtdVagas = qtdVagas;
	}
}
