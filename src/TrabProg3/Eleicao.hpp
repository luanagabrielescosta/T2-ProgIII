#ifndef eleicao_h_
#define eleicao_h_

#include <iostream>
#include <string>
#include <list>

#include "Date.hpp"
#include "Candidato.hpp"
#include "Partido.hpp"

using namespace std;

class Eleicao{
	private:
	int numeroVagaseleicao; 
	// ArrayList <partido> partidoeleicao;
	list<Partido> partidoeleicao;
	// ArrayList <candidato> eleitosProporcionalmente;
	list<Candidato> eleitosProporcionalmente;
	// ArrayList <Candidato> maisVotados;
	list<Candidato> maisVotados;
	// ArrayList <Candidato> eleitosMajoritariamente;
	list<Candidato> eleitosMajoritariamente;
	// ArrayList <Candidato> naoEleitosMajoritariamente; 
	list<Candidato> naoEleitosMajoritariamente;
	Date dataeleicao;
	int qtdVagas; 
	

	public:
	Eleicao();

	int getNumeroVagaseleicao();

	void setNumeroVagaseleicao(int numeroVagaseleicao);

	list<Partido> getpartidoeleicao();

	void setpartidoeleicao(list<Partido> &partidoeleicao);

	list<Candidato> getEleitosProporcionalmente();

	void setEleitosProporcionalmente(list<Candidato> &eleitosProporcionalmente);

	list<Candidato> getMaisVotados();

	void setMaisVotados(list<Candidato> &maisVotados);

	list<Candidato> getEleitosMajoritariamente();

	void setEleitosMajoritariamente(list<Candidato> &eleitosMajoritariamente);

	list<Candidato> getNaoEleitosMajoritariamente();

	void setNaoEleitosMajoritariamente(list<Candidato> &naoEleitosMajoritariamente);

	Date getDataeleicao();

	void setDataeleicao(Date &dataeleicao);

	void addPartido(Partido &p);
	
	Partido retornaPartidoPeloNum(int x);

	int getQtdVagas();

	void setQtdVagas(int qtdVagas);

	void printEleicao();

	void insereCandidatos(int numero, list<Candidato> &c);

};


#endif /* eleicao_h_ */