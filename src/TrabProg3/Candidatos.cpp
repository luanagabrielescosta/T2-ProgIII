// package TrabProg3;

#include <iostream>
#include <string>

using namespace std;
class Candidatos{

	private:
	int numeroCandidato;
	int votosNominaisCandidato; 
	string situacaoCandidato; 
	string nomeCandidato;
	string nomeUrnaCandidato;
	string sexoCandidato; 
	Date dataNascimentoCandidato; 
	string destinoVoto; 
	int numeroPartidoCandidato;
	
	public:
	Candidatos(int numeroCandidato, int votosNominaisCandidato,string situacaoCandidato,string nomeCandidato,string nomeUrnaCandidato,
			string sexoCandidato,Date dataNascimentoCandidato, string destinoVoto, int numeroPartidoCandidato) {
		this->numeroCandidato = numeroCandidato;
		this->votosNominaisCandidato = votosNominaisCandidato;
		this->situacaoCandidato = situacaoCandidato;
		this->nomeCandidato = nomeCandidato;
		this->nomeUrnaCandidato = nomeUrnaCandidato;
		this->sexoCandidato = sexoCandidato;
		this->dataNascimentoCandidato = dataNascimentoCandidato;
		this->destinoVoto = destinoVoto;
		this->numeroPartidoCandidato = numeroPartidoCandidato;
	}

	int getNumeroCandidato() {
		return numeroCandidato;
	}

	int getVotosNominaisCandidato() {
		return votosNominaisCandidato;
	}

	string getSituacaoCandidato() {
		return situacaoCandidato;
	}

	string getNomeCandidato() {
		return nomeCandidato;
	}

	string getNomeUrnaCandidato() {
		return nomeUrnaCandidato;
	}

	string getSexoCandidato() {
		return sexoCandidato;
	}

	Date getDataNascimentoCandidato() {
		return dataNascimentoCandidato;
	}

	string getDestinoVoto() {
		return destinoVoto;
	}

	int getNumeroPartidoCandidato() {
		return numeroPartidoCandidato;
	}

	// @Override
	int compareTo(Candidatos o) {
		// TODO Auto-generated method stub
		return 0;
	}
	
	
	
	
};
