#include <iostream>
#include <string>
#include <list>

#include "Eleicao.hpp"

using namespace std;

Eleicao::Eleicao(){
	// this->numeroVagaseleicao = numeroVagaseleicao;
	// this->partidoeleicao = partidoeleicao;
	// this->eleitosProporcionalmente = eleitosProporcionalmente;
	// this->maisVotados = maisVotados;
	// this->eleitosMajoritariamente = eleitosMajoritariamente;
	// this->naoEleitosMajoritariamente = naoEleitosMajoritariamente;
	// this->dataeleicao = dataeleicao;
}

int Eleicao::getNumeroVagaseleicao(){
	return numeroVagaseleicao;
}

void Eleicao::setNumeroVagaseleicao(int numeroVagaseleicao){
	this->numeroVagaseleicao = numeroVagaseleicao;
}

list<Partido> Eleicao::getpartidoeleicao(){
	return partidoeleicao;
}

void Eleicao::setpartidoeleicao(list<Partido> partidoeleicao){
	this->partidoeleicao = partidoeleicao;
}

list<Candidato> Eleicao::getEleitosProporcionalmente(){
	return eleitosProporcionalmente;
}
void Eleicao::setEleitosProporcionalmente(list<Candidato> eleitosProporcionalmente){
	this->eleitosProporcionalmente = eleitosProporcionalmente;
}
list<Candidato> Eleicao::getMaisVotados(){
	return maisVotados;
}
void Eleicao::setMaisVotados(list<Candidato> maisVotados){
	this->maisVotados = maisVotados;
}
list<Candidato> Eleicao::getEleitosMajoritariamente(){
	return eleitosMajoritariamente;
}
void Eleicao::setEleitosMajoritariamente(list<Candidato> eleitosMajoritariamente){
	this->eleitosMajoritariamente = eleitosMajoritariamente;
}
list<Candidato> Eleicao::getNaoEleitosMajoritariamente(){
	return naoEleitosMajoritariamente;
}
void Eleicao::setNaoEleitosMajoritariamente(list<Candidato> naoEleitosMajoritariamente){
	this->naoEleitosMajoritariamente = naoEleitosMajoritariamente;
}
Date Eleicao::getDataeleicao(){
	return dataeleicao;
}
void Eleicao::setDataeleicao(Date dataeleicao){
	this->dataeleicao = dataeleicao;
}

void Eleicao::addPartido(Partido p){
	this->partidoeleicao.insert(this->partidoeleicao.end(), p);	
}

Partido Eleicao::retornaPartidoPeloNum(int x){
	list<Partido> :: iterator it;
	string a = "inexistente";
	Partido trash = Partido(0, 0, a, a);

	for(it = partidoeleicao.begin(); it != partidoeleicao.end(); ++it){
		Partido aux = *it;
		if(x == aux.getNumeroPartido()){
			return *it;
		}
	}
	
	return trash;
}

int Eleicao::getQtdVagas(){
	return qtdVagas;
}

void Eleicao::setQtdVagas(int qtdVagas){
	this->qtdVagas = qtdVagas;
}
