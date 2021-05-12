/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ hpp da classe de candidatos
*/

#ifndef candidato_hpp_
#define candidato_hpp_

#include <iostream>
#include <string>
#include <list>
#include "Date.hpp"
using namespace std;

// A classe de candidatos possui os atributos identificadores de cada
// candidato, sem ligação direta com a Classe partidos, possuindo apenas
// o número.
class Candidato{
	// Atributos
	int numeroCandidato;
	int votosNominaisCandidato; 
	string situacaoCandidato; 
	string nomeCandidato;
	string nomeUrnaCandidato;
	char sexoCandidato; 
	Date dataNascimentoCandidato; 
	string destinoVoto; 
	int numeroPartidoCandidato;
	
	public:
	// Constructor
	Candidato(int numeroCandidato, int votosNominaisCandidato,string &situacaoCandidato,string &nomeCandidato,string &nomeUrnaCandidato,
			char &sexoCandidato, Date &dataNascimentoCandidato, string &destinoVoto, int numeroPartidoCandidato);
	// Destructor
	~Candidato();

	// Métodos
	
	// Função que retorna o número do Candidato 
	// Obs: Atributo - numeroCandidato
	int getNumeroCandidato();

	// Função que retorna o número do votos do Candidato 
	// Obs: Atributo - votosNominaisCandidato
	int getVotosNominaisCandidato();

	// Função que retorna a string que mostra se foi eleito 
	// Obs: Atributo - situacaoCandidato
	string getSituacaoCandidato();

	// Função que retorna o nome do Candidato 
	// Obs: Atributo - nomeCandidato
	string getNomeCandidato();

	// Função que retorna o nome do Candidato na urna 
	// Obs: Atributo - nomeUrnaCandidato
	string getNomeUrnaCandidato();

	// Função que retorna o sexo do Candidato 
	// Obs: Atributo - sexoCandidato
	char getSexoCandidato();

	// Função que retorna a data de nascimento do Candidato 
	// Obs: Atributo - dataNascimentoCandidato
	Date getDataNascimentoCandidato();

	// Função que retorna a validação do Candidato
	// Obs: Atributo - destinoVoto
	string getDestinoVoto();

	// Função que retorna o número do Partido que o Candidato pertence
	// Obs: Atributo - numeroPartidoCandidato
	int getNumeroPartidoCandidato();

	// Função que compara dois Candidatos, procurando equivalência 
	// Obs: igual retorna 0 | diferente retorna 1
	int compareCandidato(Candidato &o);

	// Função que printa o Candidato e seus dados
	// Obs: Função usada apenas em testes
	void printCandidato();
};

#endif /* candidato_hpp_ */