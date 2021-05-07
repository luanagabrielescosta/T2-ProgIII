#include <iostream>
#include <string>
#include <list>
#include "date.hpp"
#include "eleicao.hpp"
#include "candidato.hpp"
#include "partido.hpp"

using namespace std;

// class eleicao {
// 	private:
// 	int numeroVagaseleicao; 
// 	// ArrayList <partido> partidoeleicao;
// 	list<partido> partidoeleicao;
// 	// ArrayList <candidato> eleitosProporcionalmente;
// 	list<candidato> eleitosProporcionalmente;
// 	// ArrayList <candidato> maisVotados;
// 	list<candidato> maisVotados;
// 	// ArrayList <candidato> eleitosMajoritariamente;
// 	list<candidato> eleitosMajoritariamente;
// 	// ArrayList <candidato> naoEleitosMajoritariamente; 
// 	list<candidato> naoEleitosMajoritariamente;
// 	date dataeleicao;
// 	int qtdVagas; 
	

// 	public:
	eleicao::eleicao(){
		// this->numeroVagaseleicao = numeroVagaseleicao;
		// this->partidoeleicao = partidoeleicao;
		// this->eleitosProporcionalmente = eleitosProporcionalmente;
		// this->maisVotados = maisVotados;
		// this->eleitosMajoritariamente = eleitosMajoritariamente;
		// this->naoEleitosMajoritariamente = naoEleitosMajoritariamente;
		// this->dataeleicao = dataeleicao;
	}

	int eleicao::getNumeroVagaseleicao(){
		return numeroVagaseleicao;
	}

	void eleicao::setNumeroVagaseleicao(int numeroVagaseleicao){
		this->numeroVagaseleicao = numeroVagaseleicao;
	}

	list<partido> eleicao::getpartidoeleicao(){
		return partidoeleicao;
	}

	void eleicao::setpartidoeleicao(list<partido> partidoeleicao){
		this->partidoeleicao = partidoeleicao;
	}

	list<candidato> eleicao::getEleitosProporcionalmente(){
		return eleitosProporcionalmente;
	}
	void eleicao::setEleitosProporcionalmente(list<candidato> eleitosProporcionalmente){
		this->eleitosProporcionalmente = eleitosProporcionalmente;
	}
	list<candidato> eleicao::getMaisVotados(){
		return maisVotados;
	}
	void eleicao::setMaisVotados(list<candidato> maisVotados){
		this->maisVotados = maisVotados;
	}
	list<candidato> eleicao::getEleitosMajoritariamente(){
		return eleitosMajoritariamente;
	}
	void eleicao::setEleitosMajoritariamente(list<candidato> eleitosMajoritariamente){
		this->eleitosMajoritariamente = eleitosMajoritariamente;
	}
	list<candidato> eleicao::getNaoEleitosMajoritariamente(){
		return naoEleitosMajoritariamente;
	}
	void eleicao::setNaoEleitosMajoritariamente(list<candidato> naoEleitosMajoritariamente){
		this->naoEleitosMajoritariamente = naoEleitosMajoritariamente;
	}
	date eleicao::getDataeleicao(){
		return dataeleicao;
	}
	void eleicao::setDataeleicao(date dataeleicao){
		this->dataeleicao = dataeleicao;
	}

	void eleicao::addPartido(partido p){
		this->partidoeleicao.insert(this->partidoeleicao.end(), p);	
	}
	
	partido eleicao::retornaPartidoPeloNum(int x){
		// for(auto & partido : p){
		// 	if(x == partido.getNumeroPartido()){
		// 		return partido;
		// 	}
		// }
		// return NULL;
	}

	int eleicao::getQtdVagas(){
		return qtdVagas;
	}

	void eleicao::setQtdVagas(int qtdVagas){
		this->qtdVagas = qtdVagas;
	}
// };
