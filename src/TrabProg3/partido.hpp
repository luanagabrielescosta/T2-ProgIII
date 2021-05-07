#ifndef partido_hpp_
#define partido_hpp_

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
	int getVotosNominaisTotaisPartido();

	void setVotosNominaisTotaisPartido(int votosNominaisTotaisPartido);

	int votosTotaisPartido;;
	
	int getVotosTotaisPartido();

	void setVotosTotaisPartido(int votosTotaisPartido);

	partido(int &numeroPartido, int &votosLegendaPartido, string &nomePartido, string &siglaPartido);

	list<candidato> getcandidatoPartido();

	int getNumeroPartido();

	int getVotosLegendaPartido();

	string getNomePartido();

	string getSiglaPartido();
	
	void addCandidato(candidato c);

	int compareTo(partido o);
	
};

#endif /* partido_hpp_ */