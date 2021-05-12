#ifndef candidato_hpp_
#define candidato_hpp_

#include <iostream>
#include <string>
#include <list>
#include "Date.hpp"

using namespace std;
class Candidato{
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
	// Destructor
	~Candidato();

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

	int compare_candidato(Candidato &o);

	void printCandidato();

};

#endif /* candidato_hpp_ */