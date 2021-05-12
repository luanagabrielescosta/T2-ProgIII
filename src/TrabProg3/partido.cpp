#include <iostream>
#include <string>
#include <list>
#include "Candidato.hpp"
#include "Partido.hpp"

using namespace std;

Partido::Partido(int numeroPartido, int votosLegendaPartido, string &nomePartido, string &siglaPartido, list<Candidato> candidatoPartido){
	this->candidatoPartido = candidatoPartido;
	this->numeroPartido = numeroPartido;
	this->votosLegendaPartido = votosLegendaPartido;
	this->nomePartido = nomePartido;
	this->siglaPartido = siglaPartido;
}

Partido::~Partido(){
	// TODO Auto-generated destructor stub
}

int Partido::getVotosNominaisTotaisPartido(){
	return votosNominaisTotaisPartido;
}

int Partido::getVotosNominaisPrimeiro(){
	int maisVotado = 0;
	list< Candidato, allocator<Candidato> > :: iterator it2;

	for(it2 = this->candidatoPartido.begin(); it2 != this->candidatoPartido.end(); ++it2){
		if(it2->getVotosNominaisCandidato() > maisVotado){
			maisVotado = it2->getVotosNominaisCandidato();
		}
	}

	return maisVotado;
}

void Partido::setVotosNominaisTotaisPartido(int votosNominaisTotaisPartido){
	this->votosNominaisTotaisPartido = votosNominaisTotaisPartido;
}

int votosTotaisPartido;
//int qtdcandidatoEleitos

int Partido::getVotosTotaisPartido(){
	return votosTotaisPartido;
}

void Partido::setVotosTotaisPartido(int votosTotaisPartido){
	this->votosTotaisPartido = votosTotaisPartido;
}

list<Candidato> Partido::getCandidatoPartido(){
	return candidatoPartido;
}

void Partido::setcandidatoPartido(list<Candidato> lista){
	this->candidatoPartido = lista;
}


int Partido::getNumeroPartido(){
	return numeroPartido;
}

int Partido::getVotosLegendaPartido(){
	return votosLegendaPartido;
}

string Partido::getNomePartido(){
	return nomePartido;
}

string Partido::getSiglaPartido(){
	return siglaPartido;
}

void Partido::addCandidato(Candidato c){
	this->candidatoPartido.push_back(c);
}

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

int Partido::countVotosNominais(){
	int totalVotosNominaisPartido = 0;
	list< Candidato, allocator<Candidato> > :: iterator it2;

	for(it2 = this->candidatoPartido.begin(); it2 != this->candidatoPartido.end(); ++it2){
		if(it2->getDestinoVoto().compare("Válido") == 0){
			int help = it2->getVotosNominaisCandidato();
			totalVotosNominaisPartido = totalVotosNominaisPartido + help;
		}
	}

	return totalVotosNominaisPartido;
}

int Partido::countEleitos(){
	int eleitos = 0;
	list< Candidato, allocator<Candidato> > :: iterator it2;

	for(it2 = this->candidatoPartido.begin(); it2 != this->candidatoPartido.end(); ++it2){
		if(it2->getSituacaoCandidato().compare("Eleito") == 0){
			eleitos++;
		}
	}

	return eleitos;
}

int Partido::validaSituacao(Candidato c){
	if(c.getDestinoVoto().compare("Válido") == 0){
		return 0;
	}

	return 1;
}