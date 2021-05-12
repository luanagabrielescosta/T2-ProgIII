/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ hpp da classe de eleicao
*/

#ifndef eleicao_h_
#define eleicao_h_

#include <iostream>
#include <string>
#include <list>
#include "Date.hpp"
#include "Candidato.hpp"
#include "Partido.hpp"
using namespace std;

// A classe de eleicao possui a gama de listas e dados utilizados durante o codigo
// Apesar de não haver uma lista geral de candidatos, estão todos dentro de seus
// respectivos partidos
class Eleicao{
	// Atributos
	int numeroVagaseleicao; 
	list<Partido> partidoeleicao;
	list<Candidato> eleitosProporcionalmente;
	list<Candidato> maisVotados;
	list<Candidato> eleitosMajoritariamente;
	list<Candidato> naoEleitosMajoritariamente;
	Date dataeleicao;
	int qtdVagas; 
	

	public:
	// Constructor
	Eleicao();
	// Destructor
	~Eleicao();

	// Métodos

	// Função que retorna o número de vagas da eleicao 
	// Obs: Atributo - numeroVagaseleicao
	int getNumeroVagaseleicao();

	// Função que atribui valor ao número de vagas
	// Obs: -
	void setNumeroVagaseleicao(int numeroVagaseleicao);

	// Função que retorna a lista de Partidos da eleição
	// Obs: -
	list<Partido> getPartidoEleicao();

	// Função que atribui valor à lista de partidos
	// Obs: -
	void setPartidoEleicao(list<Partido> partidoeleicao);

	// Função que retorna a lista de Candidatos Eleitos Efetivamente
	// Obs: -
	list<Candidato> getEleitosProporcionalmente();

	// Função que atribui valor à lista de Candidatos Eleitos Efetivamente
	// Obs: -
	void setEleitosProporcionalmente(list<Candidato> &eleitosProporcionalmente);

	// Função que retorna a lista de Candidatos mais Votados
	// Obs: -
	list<Candidato> getMaisVotados();

	// Função que atribui valor à lista de Candidatos mais Votados
	// Obs: -
	void setMaisVotados(list<Candidato> &maisVotados);

	// Função que retorna a lista de Candidatos Eleitos Majoritariamente
	// Obs: -
	list<Candidato> getEleitosMajoritariamente();

	// Função que atribui valor à lista de Candidatos Eleitos Majoritariamente
	// Obs: -
	void setEleitosMajoritariamente(list<Candidato> &eleitosMajoritariamente);

	// Função que retorna a lista de Partidos Candidatos não Eleitos Majoritariamente
	// Obs: -
	list<Candidato> getNaoEleitosMajoritariamente();

	// Função que atribui valor à lista de Candidatos não Eleitos Majoritariamente
	// Obs: -
	void setNaoEleitosMajoritariamente(list<Candidato> &naoEleitosMajoritariamente);

	// Função que retorna a data da eleição 
	// Obs: -
	Date getDataeleicao();

	// Função que atribui valor à data da eleição 
	// Obs: -
	void setDataeleicao(Date &dataeleicao);

	// Função que adiciona partidos na lista de partidos
	// Obs: -
	void addPartido(Partido &p);

	// Função que busca um partido pelo número
	// Obs: Utilizada na adição de candidatos
	Partido retornaPartidoPeloNum(int x);

	// Função que retorna a quantidade de Vagas
	// Obs: -
	int getQtdVagas();

	// Função que atribui valor à quantidade de Vagas
	// Obs: -
	void setQtdVagas(int qtdVagas);

	// Função que imprime todos os partidos com seus candidatos e dados
	// Obs: Função usada apenas em testes
	void printEleicao();

	// Função que insere candidatos em uma lista genérica
	// Obs: Usada em eleitosProporcionalmente | maisVotados | eleitosMajoritariamente | naoEleitosMajoritariamente
	void insereCandidatos(Candidato c);

	// Função que retorna o número geral de partidos
	// Obs: Função usada em testes e verificações
	int retornaNumeroPartidos();

	// Função que conta todos os votos NOMINAIS - apesar do nome - da eleição
	// Obs: -
	int contaVotosValidos(list<Candidato> c);
};


#endif /* eleicao_h_ */