#ifndef candidato_hpp_
#define candidato_hpp_
// #pragma once

#include <iostream>
#include <string>
#include "date.hpp"

using namespace std;
class candidato{
	private:
	// Atributos
	int numeroCandidato;
	int votosNominaisCandidato; 
	string situacaoCandidato; 
	string nomeCandidato;
	string nomeUrnaCandidato;
	char sexoCandidato; 
	date dataNascimentoCandidato; 
	string destinoVoto; 
	int numeroPartidoCandidato;
	
	public:
	// Constructor
	candidato(int &numeroCandidato, int &votosNominaisCandidato,string &situacaoCandidato,string &nomeCandidato,string &nomeUrnaCandidato,
			char &sexoCandidato, date &dataNascimentoCandidato, string &destinoVoto, int &numeroPartidoCandidato);

	// Métodos
	int getNumeroCandidato();

	int getVotosNominaisCandidato();

	string getSituacaoCandidato();

	string getNomeCandidato();

	string getNomeUrnaCandidato();

	char getSexoCandidato();

	date getDataNascimentoCandidato();

	string getDestinoVoto();

	int getNumeroPartidoCandidato();

	int compareTo(candidato o);
};

#endif /* candidato_hpp_ */