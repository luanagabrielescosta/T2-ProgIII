/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ hpp da classe de eleicao
*/

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

// Função simples explicada no .hpp
int Eleicao::getNumeroVagaseleicao(){
	return numeroVagaseleicao;
}

// Função simples explicada no .hpp
void Eleicao::setNumeroVagaseleicao(int numeroVagaseleicao){
	this->numeroVagaseleicao = numeroVagaseleicao;
}

// Função simples explicada no .hpp
list< Partido, allocator<Partido> > Eleicao::getPartidoEleicao(){
	return partidoeleicao;
}

// Função simples explicada no .hpp
void Eleicao::setPartidoEleicao(list< Partido, allocator<Partido> > partidoeleicao){
	this->partidoeleicao = partidoeleicao;
}

// Função simples explicada no .hpp
list< Candidato, allocator<Candidato> > Eleicao::getEleitosProporcionalmente(){
	return eleitosProporcionalmente;
}

// Função simples explicada no .hpp
void Eleicao::setEleitosProporcionalmente(list< Candidato, allocator<Candidato> > &eleitosProporcionalmente){
	this->eleitosProporcionalmente = eleitosProporcionalmente;
}

// Função simples explicada no .hpp
list< Candidato, allocator<Candidato> > Eleicao::getMaisVotados(){
	return maisVotados;
}

// Função simples explicada no .hpp
void Eleicao::setMaisVotados(list< Candidato, allocator<Candidato> > &maisVotados){
	this->maisVotados = maisVotados;
}

// Função simples explicada no .hpp
list< Candidato, allocator<Candidato> > Eleicao::getEleitosMajoritariamente(){
	return eleitosMajoritariamente;
}

// Função simples explicada no .hpp
void Eleicao::setEleitosMajoritariamente(list< Candidato, allocator<Candidato> > &eleitosMajoritariamente){
	this->eleitosMajoritariamente = eleitosMajoritariamente;
}

// Função simples explicada no .hpp
list< Candidato, allocator<Candidato> > Eleicao::getNaoEleitosMajoritariamente(){
	return naoEleitosMajoritariamente;
}

// Função simples explicada no .hpp
void Eleicao::setNaoEleitosMajoritariamente(list< Candidato, allocator<Candidato> > &naoEleitosMajoritariamente){
	this->naoEleitosMajoritariamente = naoEleitosMajoritariamente;
}

// Função simples explicada no .hpp
Date Eleicao::getDataeleicao(){
	return dataeleicao;
}

// Função simples explicada no .hpp
void Eleicao::setDataeleicao(Date &dataeleicao){
	this->dataeleicao = dataeleicao;
}

// Função simples explicada no .hpp
void Eleicao::addPartido(Partido &p){
	this->partidoeleicao.insert(this->partidoeleicao.end(), p);	
}

// Função que retorna um partido através do número
Partido Eleicao::retornaPartidoPeloNum(int numero){
	list< Partido, allocator<Partido> > :: iterator it;

	list<Candidato> c; // Lista vazia para inicialização
	string a = " "; // String para inicialização
	Partido trash = Partido(0, 0, a, a, c); // Partido auxiliar inicializado

	// Loop que percorre os partidos da eleição
	for(it = partidoeleicao.begin(); it != partidoeleicao.end(); ++it){
		if(numero == it->getNumeroPartido()){ // Verificação do número
			return *it;
		}
	}
	
	return trash;
}

// Função simples explicada no .hpp
int Eleicao::getQtdVagas(){
	return qtdVagas;
}

// Função simples explicada no .hpp
void Eleicao::setQtdVagas(int qtdVagas){
	this->qtdVagas = qtdVagas;
}

// Função simples explicada no .hpp
void Eleicao::printEleicao(){
	list< Partido, allocator<Partido> > :: iterator it;

	for(it = this->partidoeleicao.begin(); it != this->partidoeleicao.end(); ++it){
		Partido a = *it;
		a.printPartido();
	}

}

// Função de inserção de Candidatos no partido
void Eleicao::insereCandidatos(Candidato c){
	list<Partido> :: iterator it;

	// Loop na lista de partidos 
	for(it = partidoeleicao.begin(); it != partidoeleicao.end(); ++it){
		if(c.getNumeroPartidoCandidato() == it->getNumeroPartido()){ // Verificação do número do partido
			it->addCandidato(c);
		}
	}
}

// Função que funciona como contador de partidos
int Eleicao::retornaNumeroPartidos(){
	list< Partido, allocator<Partido> > :: iterator it;
	int count = 0; // Contador inicializado

	// Loop na lista de partidos 
	for(it = partidoeleicao.begin(); it != partidoeleicao.end(); ++it){
		count++; // Contador incrementado
	}
	
	return count;
}

// Função de contagem de votos nominais
int Eleicao::contaVotosValidos(list<Candidato> c){
	int count = 0; // Contador inicializado
	list< Partido, allocator<Partido> > :: iterator it;

	// Loop na lista de partidos 
	for(it = partidoeleicao.begin(); it != partidoeleicao.end(); ++it){
		count = count + it->countValidos(); // Incrementa o contador com a função de contagem
	}

	return count;
}
