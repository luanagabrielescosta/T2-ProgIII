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

list<Candidato> Partido::getcandidatoPartido() {
	return candidatoPartido;
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

void Partido::addCandidato(Candidato c){
	this->candidatoPartido.insert(this->candidatoPartido.end(), c);
}