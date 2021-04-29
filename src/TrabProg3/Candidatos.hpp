#ifndef candidatos_hpp_
#define candidatos_hpp_

#include <iostream>
#include <string>
#include "Candidatos.hpp"

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
			string sexoCandidato,Date dataNascimentoCandidato, string destinoVoto, int numeroPartidoCandidato);

	int getNumeroCandidato();

	int getVotosNominaisCandidato();

	string getSituacaoCandidato();

	string getNomeCandidato();

	string getNomeUrnaCandidato();

	string getSexoCandidato();

	Date getDataNascimentoCandidato();

	string getDestinoVoto();

	int getNumeroPartidoCandidato();

	int compareTo(Candidatos o);
};

#endif /* candidatos_hpp_ */