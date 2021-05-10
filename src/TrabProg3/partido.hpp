#ifndef partido_hpp_
#define partido_hpp_

#include <list>
#include "Candidato.hpp"

using namespace std;

class Partido{
	// Atributos
	list<Candidato> candidatoPartido; 
	int numeroPartido; 
	int votosLegendaPartido; 
	string nomePartido; 
	string siglaPartido; 
	int votosNominaisTotaisPartido;

	public:
	// Constructor
	Partido(int numeroPartido, int votosLegendaPartido, string &nomePartido, string &siglaPartido);

	// Metodos 
	int getVotosNominaisTotaisPartido();

	void setVotosNominaisTotaisPartido(int votosNominaisTotaisPartido);

	int votosTotaisPartido;;
	
	int getVotosTotaisPartido();

	void setVotosTotaisPartido(int votosTotaisPartido);

	list<Candidato> getcandidatoPartido();

	int getNumeroPartido();

	int getVotosLegendaPartido();

	string getNomePartido();

	string getSiglaPartido();
	
	void addCandidato(Candidato c);
};

#endif /* partido_hpp_ */