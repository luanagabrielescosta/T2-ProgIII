#ifndef eleicao_h_
#define eleicao_h_

#include <iostream>
#include <string>
#include <list>
#include "date.hpp"

#include "candidato.hpp"
#include "partido.hpp"

using namespace std;

class eleicao {
	private:
	int numeroVagaseleicao; 
	// ArrayList <partido> partidoeleicao;
	list<partido> partidoeleicao;
	// ArrayList <candidato> eleitosProporcionalmente;
	list<candidato> eleitosProporcionalmente;
	// ArrayList <candidato> maisVotados;
	list<candidato> maisVotados;
	// ArrayList <candidato> eleitosMajoritariamente;
	list<candidato> eleitosMajoritariamente;
	// ArrayList <candidato> naoEleitosMajoritariamente; 
	list<candidato> naoEleitosMajoritariamente;
	date dataeleicao;
	int qtdVagas; 
	

	public:
	eleicao();

	int getNumeroVagaseleicao();

	void setNumeroVagaseleicao(int numeroVagaseleicao);

	list<partido> getpartidoeleicao();

	void setpartidoeleicao(list<partido> partidoeleicao);

	list<candidato> getEleitosProporcionalmente();

	void setEleitosProporcionalmente(list<candidato> eleitosProporcionalmente);

	list<candidato> getMaisVotados();

	void setMaisVotados(list<candidato> maisVotados);

	list<candidato> getEleitosMajoritariamente();

	void setEleitosMajoritariamente(list<candidato> eleitosMajoritariamente);

	list<candidato> getNaoEleitosMajoritariamente();

	void setNaoEleitosMajoritariamente(list<candidato> naoEleitosMajoritariamente);

	date getDataeleicao();

	void setDataeleicao(date dataeleicao);

	void addPartido(partido p);
	
	partido retornaPartidoPeloNum(int x);

	int getQtdVagas();

	void setQtdVagas(int qtdVagas);
};


#endif /* eleicao_h_ */