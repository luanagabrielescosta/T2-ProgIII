#include <iostream>
#include <string>
#include <list>
#include "Candidato.hpp"
#include "Partido.hpp"

using namespace std;

Partido::Partido(int numeroPartido, int votosLegendaPartido, string &nomePartido, string &siglaPartido){
	// this->candidatoPartido = candidatoPartido;
	this->numeroPartido = numeroPartido;
	this->votosLegendaPartido = votosLegendaPartido;
	this->nomePartido = nomePartido;
	this->siglaPartido = siglaPartido;
}

int Partido::getVotosNominaisTotaisPartido() {
	return votosNominaisTotaisPartido;
}

void Partido::setVotosNominaisTotaisPartido(int votosNominaisTotaisPartido) {
	this->votosNominaisTotaisPartido = votosNominaisTotaisPartido;
}

int votosTotaisPartido;
//int qtdcandidatoEleitos

int Partido::getVotosTotaisPartido() {
	return votosTotaisPartido;
}

void Partido::setVotosTotaisPartido(int votosTotaisPartido) {
	this->votosTotaisPartido = votosTotaisPartido;
}

list< Candidato, allocator<Candidato> > Partido::getcandidatoPartido(){
	return candidatoPartido;
}

void Partido::setcandidatoPartido(list<Candidato> &lista){
	this->candidatoPartido = lista;
}


int Partido::getNumeroPartido() {
	return numeroPartido;
}

int Partido::getVotosLegendaPartido() {
	return votosLegendaPartido;
}

string Partido::getNomePartido() {
	return nomePartido;
}

string Partido::getSiglaPartido() {
	return siglaPartido;
}

list<Candidato> Partido::addCandidato(Candidato &c){
	list<Candidato> lista;
	
	lista = this->candidatoPartido;
	lista.insert(lista.end(), c);
	// printPartido();
	// cout << endl;
	return lista;
}

void Partido::printPartido(){
	list< Candidato, allocator<Candidato> > :: iterator it;

	for(it = this->candidatoPartido.begin(); it != this->candidatoPartido.end(); ++it){
		Candidato a = *it;
		a.printCandidato();
	}

	cout << this->numeroPartido << endl;
	cout << this->votosLegendaPartido << endl;
	cout << this->nomePartido << endl;
	cout << this->siglaPartido << endl;
}
