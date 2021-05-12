/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ hpp da classe de leitura
*/

#ifndef leitura_hpp_
#define leitura_hpp_

#include <string>
#include "Eleicao.hpp"

// A classe de leitura é feita para ler ambos os arquivos (candidatos e
// partidos) e adicioná-los na estrutura estabelecida no eleições
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

	// Função que faz a leitura do arquivo de partidos
	// Obs: Função principal desta classe
    void lePartidos(Eleicao &vereadores, string &path, list<Candidato> c);
	
	// Função que faz a leitura do arquivo de candidatos
	// Obs: -
	list<Candidato> leCandidatos(Eleicao &vereadores, string &path);
};

#endif /* leitura_hpp_ */