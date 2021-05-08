#ifndef partido_hpp_
#define partido_hpp_

#include <list>
#include "candidato.hpp"

using namespace std;

class partido{
	// Atributos
	list<candidato> candidatoPartido; 
	int numeroPartido; 
	int votosLegendaPartido; 
	string nomePartido; 
	string siglaPartido; 
	int votosNominaisTotaisPartido;

	public:
	// Constructor
	partido(int numeroPartido, int votosLegendaPartido, string &nomePartido, string &siglaPartido);

	// Metodos 
	int getVotosNominaisTotaisPartido();

	void setVotosNominaisTotaisPartido(int votosNominaisTotaisPartido);

	int votosTotaisPartido;;
	
	int getVotosTotaisPartido();

	void setVotosTotaisPartido(int votosTotaisPartido);

	list<candidato> getcandidatoPartido();

	int getNumeroPartido();

	int getVotosLegendaPartido();

	string getNomePartido();

	string getSiglaPartido();
	
	void addCandidato(candidato c);
};

#endif /* partido_hpp_ */