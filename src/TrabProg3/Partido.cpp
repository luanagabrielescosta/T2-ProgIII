/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ hpp da classe de partidos
*/

#include <iostream>
#include <string>
#include <list>
#include "Candidato.hpp"
#include "Partido.hpp"

using namespace std;

// Constructor
Partido::Partido(int numeroPartido, int votosLegendaPartido, string &nomePartido, string &siglaPartido, list<Candidato> candidatoPartido){
	this->candidatoPartido = candidatoPartido;
	this->numeroPartido = numeroPartido;
	this->votosLegendaPartido = votosLegendaPartido;
	this->nomePartido = nomePartido;
	this->siglaPartido = siglaPartido;
}

// Destructor 
Partido::~Partido(){
	// TODO Auto-generated destructor stub
}

// Função simples explicada no .hpp
int Partido::getVotosNominaisTotaisPartido(){
	return votosNominaisTotaisPartido;
}

// Função que retorna os votos nominais do primeiro 
int Partido::getVotosNominaisPrimeiro(){
	int maisVotado = 0; // Contador inicializado
	list< Candidato, allocator<Candidato> > :: iterator it2;

	// Loop na lista de Candidato
	for(it2 = this->candidatoPartido.begin(); it2 != this->candidatoPartido.end(); ++it2){
		if(it2->getVotosNominaisCandidato() > maisVotado){ // Verifica se o número de votos é maior que o contador
			maisVotado = it2->getVotosNominaisCandidato(); // Se for, altera o valor
		}
	}

	return maisVotado;
}

// Função simples explicada no .hpp
void Partido::setVotosNominaisTotaisPartido(int votosNominaisTotaisPartido){
	this->votosNominaisTotaisPartido = votosNominaisTotaisPartido;
}

// Função simples explicada no .hpp
int Partido::getVotosTotaisPartido(){
	return votosTotaisPartido;
}

// Função simples explicada no .hpp
void Partido::setVotosTotaisPartido(int votosTotaisPartido){
	this->votosTotaisPartido = votosTotaisPartido;
}

// Função simples explicada no .hpp
list<Candidato> Partido::getCandidatoPartido(){
	return candidatoPartido;
}

// Função simples explicada no .hpp
void Partido::setcandidatoPartido(list<Candidato> lista){
	this->candidatoPartido = lista;
}

// Função simples explicada no .hpp
int Partido::getNumeroPartido(){
	return numeroPartido;
}

// Função simples explicada no .hpp
int Partido::getVotosLegendaPartido(){
	return votosLegendaPartido;
}

// Função simples explicada no .hpp
string Partido::getNomePartido(){
	return nomePartido;
}

// Função simples explicada no .hpp
string Partido::getSiglaPartido(){
	return siglaPartido;
}

// Função simples explicada no .hpp
void Partido::addCandidato(Candidato c){
	this->candidatoPartido.push_back(c);
}

// Função simples explicada no .hpp
void Partido::printPartido(){
	list< Candidato, allocator<Candidato> > :: iterator it;
	for(it = this->candidatoPartido.begin(); it != this->candidatoPartido.end(); ++it){
		it->printCandidato();
	}

	cout << this->numeroPartido << endl;
	cout << this->votosLegendaPartido << endl;
	cout << this->nomePartido << endl;
	cout << this->siglaPartido << endl;
	cout << endl << endl << endl;
}

// Função que conta o número de votos nominais da eleicao
int Partido::countVotosNominais(){
	int totalVotosNominaisPartido = 0; // Contador inicializado
	list< Candidato, allocator<Candidato> > :: iterator it2;

	// Loop da lista de Candidato 
	for(it2 = this->candidatoPartido.begin(); it2 != this->candidatoPartido.end(); ++it2){
		if(it2->getDestinoVoto().compare("Válido") == 0){ // Verifica se o candidato é válido
			int help = it2->getVotosNominaisCandidato();
			totalVotosNominaisPartido = totalVotosNominaisPartido + help; // soma os votos no total
		}
	}

	return totalVotosNominaisPartido;
}

// Função que conta o número de eleitos
int Partido::countEleitos(){
	int eleitos = 0; // Constador inicializado
	list< Candidato, allocator<Candidato> > :: iterator it2;

	// Loop da lista de Candidato 
	for(it2 = this->candidatoPartido.begin(); it2 != this->candidatoPartido.end(); ++it2){
		if(it2->getSituacaoCandidato().compare("Eleito") == 0){ // Verifica se o candidato é eleito
			eleitos++; // Incrementa o contador
		}
	}

	return eleitos;
}

// Função que verifica se o candidato é válido
int Partido::validaSituacao(Candidato c){
	if(c.getDestinoVoto().compare("Válido") == 0){ // Verifica se o candidato é válido
		return 0;
	}

	return 1;
}

// Função que conta o número de válidos
int Partido::countValidos(){
	int count = 0; // Contador inicializado
	list< Candidato, allocator<Candidato> > :: iterator it2;

	// Loop da lista de Candidato 
	for(it2 = this->candidatoPartido.begin(); it2 != this->candidatoPartido.end(); ++it2){
		if(it2->getDestinoVoto().compare("Válido") == 0){ // Verifica se o candidato é válido
			count = count + it2->getVotosNominaisCandidato(); // Soma os votos nominais no total
		}
	}

	return count;
}
