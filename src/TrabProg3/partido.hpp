#ifndef partido_hpp_
#define partido_hpp_

#include <list>
#include <vector>
#include "Candidato.hpp"

using namespace std;

class Partido{
	// Atributos
	list<Candidato*> candidatoPartido; 
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

	list<Candidato*> getcandidatoPartido();

	void setcandidatoPartido(list<Candidato*> lista);

	int getNumeroPartido();

	int getVotosLegendaPartido();

	string getNomePartido();

	string getSiglaPartido();
	
	void addCandidato(Candidato *c);

	void printPartido();
};

#endif /* partido_hpp_ */