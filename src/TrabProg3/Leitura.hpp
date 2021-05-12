#ifndef leitura_hpp_
#define leitura_hpp_

#include <string>
#include "Eleicao.hpp"

class Leitura{
	// Atributos
	string nPartido;
	string vLegenda;
	string nomePartido; 
	string siglaPartido; 
	string numCandidato;
	string vNominaisCandidato;
	string situCandidato;
	string noCandidato;
	string noUrnaCandidato;
	string sexCandidato;
	string datNascCandidato;
	string destVotoCandidato;
	string nPartidoCandidato;
	string comparaSituacao;
	char comparaSexof;
	char comparaSexom; 
	// Quantificadores
	int qtdVagas;
	int qtdMulheresEleitas;
	int qtdHomensEleitos;
	int totalVotos;
	int totalVotosNominais;
	int totalVotosLegenda; 
	
	public:
	// Constructor
    Leitura();
	// Destructor
    ~Leitura();
	
	// Métodos
    void lePartidos(Eleicao &vereadores, string &path, list<Candidato> c);
	
	list<Candidato> leCandidatos(Eleicao &vereadores, string &path);
};

#endif /* leitura_hpp_ */