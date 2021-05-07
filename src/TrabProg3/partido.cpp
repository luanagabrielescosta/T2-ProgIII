#include <iostream>
#include <string>
#include <list>
#include "candidato.hpp"
#include "partido.hpp"

using namespace std;

	int partido::getVotosNominaisTotaisPartido() {
		return votosNominaisTotaisPartido;
	}

	void partido::setVotosNominaisTotaisPartido(int votosNominaisTotaisPartido) {
		this->votosNominaisTotaisPartido = votosNominaisTotaisPartido;
	}

	int votosTotaisPartido;
	//int qtdcandidatoEleitos
	
	int partido::getVotosTotaisPartido() {
		return votosTotaisPartido;
	}

	void partido::setVotosTotaisPartido(int votosTotaisPartido) {
		this->votosTotaisPartido = votosTotaisPartido;
	}

	partido::partido(int &numeroPartido, int &votosLegendaPartido, string &nomePartido, string &siglaPartido){
		// this->candidatoPartido = candidatoPartido;
		this->numeroPartido = numeroPartido;
		this->votosLegendaPartido = votosLegendaPartido;
		this->nomePartido = nomePartido;
		this->siglaPartido = siglaPartido;
	}

	list<candidato> partido::getcandidatoPartido() {
		return candidatoPartido;
	}

	int partido::getNumeroPartido() {
		return numeroPartido;
	}

	int partido::getVotosLegendaPartido() {
		return votosLegendaPartido;
	}

	string partido::getNomePartido() {
		return nomePartido;
	}

	string partido::getSiglaPartido() {
		return siglaPartido;
	}
	
	void partido::addCandidato(candidato c){
		this->candidatoPartido.insert(this->candidatoPartido.end(), c);
	}

	// @Override
	int partido::compareTo(partido o) {
		// TODO Auto-generated method stub
		return 0;
	}