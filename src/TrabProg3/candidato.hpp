#ifndef candidato_hpp_
#define candidato_hpp_
// #pragma once

#include <iostream>
#include <string>
#include "date.hpp"

using namespace std;
class candidato{

	private:
	int numeroCandidato;
	int votosNominaisCandidato; 
	string situacaoCandidato; 
	string nomeCandidato;
	string nomeUrnaCandidato;
	string sexoCandidato; 
	date dataNascimentoCandidato; 
	string destinoVoto; 
	int numeroPartidoCandidato;
	
	public:
	candidato(int &numeroCandidato, int &votosNominaisCandidato,string &situacaoCandidato,string &nomeCandidato,string &nomeUrnaCandidato,
			string &sexoCandidato, date &dataNascimentoCandidato, string &destinoVoto, int &numeroPartidoCandidato);

	int getNumeroCandidato();

	int getVotosNominaisCandidato();

	string getSituacaoCandidato();

	string getNomeCandidato();

	string getNomeUrnaCandidato();

	string getSexoCandidato();

	date getDataNascimentoCandidato();

	string getDestinoVoto();

	int getNumeroPartidoCandidato();

	int compareTo(candidato o);
};

#endif /* candidato_hpp_ */