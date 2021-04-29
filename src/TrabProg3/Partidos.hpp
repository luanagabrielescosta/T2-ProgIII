#ifndef partidos_hpp_
#define partidos_hpp_

#include <list>
#include "Candidatos.hpp"

using namespace std;

class Partidos{
	list<Candidatos> candidatosPartido; 
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

	Partidos(int numeroPartido, int votosLegendaPartido, string nomePartido, string siglaPartido);

	list<Candidatos> getCandidatosPartido();

	int getNumeroPartido();

	int getVotosLegendaPartido();

	string getNomePartido();

	string getSiglaPartido();
	
	void addCandidato(Candidatos c);

	int compareTo(Partidos o);
	
};

#endif /* partidos_hpp_ */