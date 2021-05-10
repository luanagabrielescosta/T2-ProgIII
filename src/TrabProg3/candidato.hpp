#ifndef candidato_hpp_
#define candidato_hpp_
// #pragma once

#include <iostream>
#include <string>
#include <list>
#include "Date.hpp"

using namespace std;
class Candidato{
	private:
	// Atributos
	int numeroCandidato;
	int votosNominaisCandidato; 
	string situacaoCandidato; 
	string nomeCandidato;
	string nomeUrnaCandidato;
	char sexoCandidato; 
	Date dataNascimentoCandidato; 
	string destinoVoto; 
	int numeroPartidoCandidato;
	
	public:
	// Constructor
	Candidato(int numeroCandidato, int votosNominaisCandidato,string &situacaoCandidato,string &nomeCandidato,string &nomeUrnaCandidato,
			char &sexoCandidato, Date &dataNascimentoCandidato, string &destinoVoto, int numeroPartidoCandidato);

	// Métodos
	int getNumeroCandidato();

	int getVotosNominaisCandidato();

	string getSituacaoCandidato();

	string getNomeCandidato();

	string getNomeUrnaCandidato();

	char getSexoCandidato();

	Date getDataNascimentoCandidato();

	string getDestinoVoto();

	int getNumeroPartidoCandidato();

	int compare_candidato(Candidato o);

	list<const Candidato> retornaConst(list<Candidato> o);
};

#endif /* candidato_hpp_ */