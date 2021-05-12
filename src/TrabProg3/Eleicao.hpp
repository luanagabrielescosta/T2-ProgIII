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
	// Atributos
	int numeroVagaseleicao; 
	list<Partido> partidoeleicao;
	list<Candidato> eleitosProporcionalmente;
	list<Candidato> maisVotados;
	list<Candidato> eleitosMajoritariamente;
	list<Candidato> naoEleitosMajoritariamente;
	Date dataeleicao;
	int qtdVagas; 
	

	public:
	// Constructor
	Eleicao();
	// Destructor
	~Eleicao();

	// Métodos
	int getNumeroVagaseleicao();

	void setNumeroVagaseleicao(int numeroVagaseleicao);

	list<Partido> getPartidoEleicao();

	void setPartidoEleicao(list<Partido> partidoeleicao);

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

	void insereCandidatos(Candidato c);

	int retornaNumeroPartidos();

	int contaVotosValidos(list<Candidato> c);
};


#endif /* eleicao_h_ */