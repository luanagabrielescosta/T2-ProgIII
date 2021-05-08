#ifndef leitura_hpp_
#define leitura_hpp_

#include <string>
#include "eleicao.hpp"

class leitura {
	// Atributos
	// Partidos 
	string nPartido;
	string vLegenda;
	string nomePartido; 
	string siglaPartido; 
	// Candidatos
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
    leitura();
	
	// Métodos
    void lePartidos(eleicao vereadores, string path);
	
	void leCandidatos(eleicao vereadores, string path);
};

#endif /* leitura_hpp_ */