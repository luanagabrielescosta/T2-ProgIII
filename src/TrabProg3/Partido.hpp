#ifndef partido_hpp_
#define partido_hpp_

#include <list>
#include <vector>
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
	Partido(int numeroPartido, int votosLegendaPartido, string &nomePartido, string &siglaPartido, list<Candidato> candidatoPartido);
	// Destructor
	~Partido();

	// Metodos 
	int getVotosNominaisTotaisPartido();

	int getVotosNominaisPrimeiro();

	void setVotosNominaisTotaisPartido(int votosNominaisTotaisPartido);

	int votosTotaisPartido;;
	
	int getVotosTotaisPartido();

	void setVotosTotaisPartido(int votosTotaisPartido);

	list<Candidato> getCandidatoPartido();

	void setcandidatoPartido(list<Candidato> lista);

	int getNumeroPartido();

	int getVotosLegendaPartido();

	string getNomePartido();

	string getSiglaPartido();
	
	void addCandidato(Candidato c);

	void printPartido();

	int countVotosNominais();

	int countEleitos();

	Candidato getPrimeiroCandidato(Candidato primeiro);

	Candidato getUltimoCandidato(Candidato primeiro);

	int validaSituacao(Candidato c);
	
	int countValidos();
};

#endif /* partido_hpp_ */
