#include <iostream>
#include <string>
#include <list>
#include "candidato.hpp"

using namespace std;

class partido{
	list<candidato> candidatoPartido; 
	int numeroPartido; 
	int votosLegendaPartido; 
	string nomePartido; 
	string siglaPartido; 
	int votosNominaisTotaisPartido;

	public:
	int getVotosNominaisTotaisPartido() {
		return votosNominaisTotaisPartido;
	}

	void setVotosNominaisTotaisPartido(int votosNominaisTotaisPartido) {
		this->votosNominaisTotaisPartido = votosNominaisTotaisPartido;
	}

	int votosTotaisPartido;
	//int qtdcandidatoEleitos
	
	int getVotosTotaisPartido() {
		return votosTotaisPartido;
	}

	void setVotosTotaisPartido(int votosTotaisPartido) {
		this->votosTotaisPartido = votosTotaisPartido;
	}

	partido(int numeroPartido, int votosLegendaPartido, string nomePartido, string siglaPartido) {
		
		this->candidatoPartido = candidatoPartido;
		this->numeroPartido = numeroPartido;
		this->votosLegendaPartido = votosLegendaPartido;
		this->nomePartido = nomePartido;
		this->siglaPartido = siglaPartido;
	}

	list<candidato> getcandidatoPartido() {
		return candidatoPartido;
	}

	int getNumeroPartido() {
		return numeroPartido;
	}

	int getVotosLegendaPartido() {
		return votosLegendaPartido;
	}

	string getNomePartido() {
		return nomePartido;
	}

	string getSiglaPartido() {
		return siglaPartido;
	}
	
	void addCandidato(candidato c){
		this->candidatoPartido.insert(this->candidatoPartido.end(), c);
	}

	// @Override
	int compareTo(partido o) {
		// TODO Auto-generated method stub
		return 0;
	}
	
	
};