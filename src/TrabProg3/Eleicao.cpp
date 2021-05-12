#include <iostream>
#include <string>
#include <list>

#include "Eleicao.hpp"

using namespace std;

Eleicao::Eleicao(){
}

Eleicao::~Eleicao(){
	// TODO Auto-generated destructor stub
}

int Eleicao::getNumeroVagaseleicao(){
	return numeroVagaseleicao;
}

void Eleicao::setNumeroVagaseleicao(int numeroVagaseleicao){
	this->numeroVagaseleicao = numeroVagaseleicao;
}

list< Partido, allocator<Partido> > Eleicao::getPartidoEleicao(){
	return partidoeleicao;
}

void Eleicao::setPartidoEleicao(list< Partido, allocator<Partido> > partidoeleicao){
	this->partidoeleicao = partidoeleicao;
}

list< Candidato, allocator<Candidato> > Eleicao::getEleitosProporcionalmente(){
	return eleitosProporcionalmente;
}
void Eleicao::setEleitosProporcionalmente(list< Candidato, allocator<Candidato> > &eleitosProporcionalmente){
	this->eleitosProporcionalmente = eleitosProporcionalmente;
}
list< Candidato, allocator<Candidato> > Eleicao::getMaisVotados(){
	return maisVotados;
}
void Eleicao::setMaisVotados(list< Candidato, allocator<Candidato> > &maisVotados){
	this->maisVotados = maisVotados;
}
list< Candidato, allocator<Candidato> > Eleicao::getEleitosMajoritariamente(){
	return eleitosMajoritariamente;
}
void Eleicao::setEleitosMajoritariamente(list< Candidato, allocator<Candidato> > &eleitosMajoritariamente){
	this->eleitosMajoritariamente = eleitosMajoritariamente;
}
list< Candidato, allocator<Candidato> > Eleicao::getNaoEleitosMajoritariamente(){
	return naoEleitosMajoritariamente;
}
void Eleicao::setNaoEleitosMajoritariamente(list< Candidato, allocator<Candidato> > &naoEleitosMajoritariamente){
	this->naoEleitosMajoritariamente = naoEleitosMajoritariamente;
}
Date Eleicao::getDataeleicao(){
	return dataeleicao;
}
void Eleicao::setDataeleicao(Date &dataeleicao){
	this->dataeleicao = dataeleicao;
}

void Eleicao::addPartido(Partido &p){
	this->partidoeleicao.insert(this->partidoeleicao.end(), p);	
}

Partido Eleicao::retornaPartidoPeloNum(int x){
	list< Partido, allocator<Partido> > :: iterator it;
	list<Candidato> c;
	string a = "inexistente";
	Partido trash = Partido(0, 0, a, a, c);

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

void Eleicao::printEleicao(){
	list< Partido, allocator<Partido> > :: iterator it;

	for(it = this->partidoeleicao.begin(); it != this->partidoeleicao.end(); ++it){
		Partido a = *it;
		a.printPartido();
	}

}

void Eleicao::insereCandidatos(Candidato c){
	list<Partido> :: iterator it;

	for(it = partidoeleicao.begin(); it != partidoeleicao.end(); ++it){
		Partido p = *it;
		if(c.getNumeroPartidoCandidato() == p.getNumeroPartido()){
			p.addCandidato(c);
		}
	}
}

int Eleicao::retornaNumeroPartidos(){
	list< Partido, allocator<Partido> > :: iterator it;
	int count = 0;

	for(it = partidoeleicao.begin(); it != partidoeleicao.end(); ++it){
		count++;
	}
	
	return count;
}

int Eleicao::contaVotosValidos(){
	int count = 0;
	list< Partido, allocator<Partido> > :: iterator it;
	for(it = partidoeleicao.begin(); it != partidoeleicao.end(); ++it){
		count = count + it->countValidos();
	}

	return count;
}
