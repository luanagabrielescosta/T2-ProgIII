#ifndef eleicao_h_
#define eleicao_h_

#include <iostream>
#include <string>
#include <list>

#include "Candidatos.hpp"
#include "Partidos.hpp"

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
	Eleicao();

	int getNumeroVagasEleicao();

	void setNumeroVagasEleicao(int numeroVagasEleicao);

	list<Partidos> getPartidosEleicao();

	void setPartidosEleicao(list<Partidos> partidosEleicao);

	list<Candidatos> getEleitosProporcionalmente();

	void setEleitosProporcionalmente(list<Candidatos> eleitosProporcionalmente);

	list<Candidatos> getMaisVotados();

	void setMaisVotados(list<Candidatos> maisVotados);

	list<Candidatos> getEleitosMajoritariamente();

	void setEleitosMajoritariamente(list<Candidatos> eleitosMajoritariamente);

	list<Candidatos> getNaoEleitosMajoritariamente();

	void setNaoEleitosMajoritariamente(list<Candidatos> naoEleitosMajoritariamente);

	Date getDataEleicao();

	void setDataEleicao(Date dataEleicao);

	void addPartido(Partidos p);
	
	Partidos retornaPartidoPeloNum(int x);

	int getQtdVagas();

	void setQtdVagas(int qtdVagas);
};


#endif /* eleicao_h_ */