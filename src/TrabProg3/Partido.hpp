/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ hpp da classe de partidos
*/

#ifndef partido_hpp_
#define partido_hpp_

#include <list>
#include <vector>
#include "Candidato.hpp"

using namespace std;

// A classe de partidos armazena os dados do partido e seus dados específicos
// com vários métodos auxiliares para a classe de eleicao
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

	// Função que retorna os votos nominais do Partido
	// Obs: -
	int getVotosNominaisTotaisPartido();

	// Função que retorna os votos nominais do primeiro candidato do Partido
	// Obs: -
	int getVotosNominaisPrimeiro();

	// Função que atribui valor aos votos nominais do Partido
	// Obs: -
	void setVotosNominaisTotaisPartido(int votosNominaisTotaisPartido);

	// Variável de votos
	int votosTotaisPartido;
	
	// Função que retorna o valor dos votos totais
	// Obs: Atributo - votosTotaisPartido
	int getVotosTotaisPartido();

	// Função que atribui o valor dos votos totais
	// Obs: Atributo - votosTotaisPartido
	void setVotosTotaisPartido(int votosTotaisPartido);

	// Função que retorna a lista de Candidatos do partido
	// Obs: -
	list<Candidato> getCandidatoPartido();

	// Função que atribui uma lista à lista de Candidatos do partido
	// Obs: -
	void setcandidatoPartido(list<Candidato> lista);

	// Função que retorna o número do partido
	// Obs: Atributo - numeroPartido
	int getNumeroPartido();

	// Função que retorna o número de votos de legenda do partido
	// Obs: Atributo - votosLegendaPartido
	int getVotosLegendaPartido();

	// Função que retorna o nome do partido
	// Obs: Atributo - nomePartido
	string getNomePartido();

	// Função que retorna a sigla do partido
	// Obs: Atributo - siglaPartido
	string getSiglaPartido();
	
	// Função que adiciona um candidato
	// Obs: -
	void addCandidato(Candidato c);

	// Função que imprime o Partido
	// Obs: -
	void printPartido();

	// Função de recontagem dos votos nominais
	// Obs: -
	int countVotosNominais();

	// Função que conta o número de eleitos
	// Obs: -
	int countEleitos();

	// Função que retorna o primeiro Candidato da lista
	// Obs: -
	Candidato getPrimeiroCandidato(Candidato primeiro);

	// Função que retorna o último Candidato da lista
	// Obs: -
	Candidato getUltimoCandidato(Candidato primeiro);

	// Verifica se um candidato é válido
	// Obs:  igual retorna 0 | diferente retorna 1
	int validaSituacao(Candidato c);
	
	// Função que conta o número de Válidos
	// Obs: -
	int countValidos();
};

#endif /* partido_hpp_ */
