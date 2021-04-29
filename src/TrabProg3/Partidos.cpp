#include <iostream>
#include <string>
#include <list>
#include "Candidatos.hpp"

using namespace std;

class Partidos{
	list<Candidatos> candidatosPartido; 
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
	//int qtdCandidatosEleitos
	
	int getVotosTotaisPartido() {
		return votosTotaisPartido;
	}

	void setVotosTotaisPartido(int votosTotaisPartido) {
		this->votosTotaisPartido = votosTotaisPartido;
	}

	Partidos(int numeroPartido, int votosLegendaPartido, string nomePartido, string siglaPartido) {
		
		this->candidatosPartido = candidatosPartido;
		this->numeroPartido = numeroPartido;
		this->votosLegendaPartido = votosLegendaPartido;
		this->nomePartido = nomePartido;
		this->siglaPartido = siglaPartido;
	}

	list<Candidatos> getCandidatosPartido() {
		return candidatosPartido;
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
	
	void addCandidato(Candidatos c){
		this->candidatosPartido.insert(this->candidatosPartido.end(), c);
	}

	// @Override
	int compareTo(Partidos o) {
		// TODO Auto-generated method stub
		return 0;
	}
	
	
};