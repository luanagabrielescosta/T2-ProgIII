/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ hpp da classe de lib (library)
*/

#ifndef lib_h_
#define lib_h_

#include <string>
#include <list>
#include "Date.hpp"
#include "Candidato.hpp"

// A classe Lib foi feita para organizar funções que não eram
// específicas de nenhuma outra classe (com exceção de uma que
// mexe com Candidato e era similar a outra dessa classe)
class Lib{
    public:
    // Constructor
    Lib();
    // Destructor
    ~Lib();

    // Métodos

    // Função que muda o tipo da string para int
	// Obs: -
    int stringToInt(std::string &old);

    // Função que muda o tipo da string para Date
	// Obs: -
    Date stringToDate(std:: string &old);

    // Função que muda o tipo da string para char
	// Obs: -
    char stringToChar(std:: string &old);

    // Função que muda o tipo da int para char
	// Obs: Função principal desta classe
    char intToChar(int old);

    // Retorna um int de uma lista pelo index
	// Obs: -
    int returnInt(list< int, allocator<int> > &list, int one);

    // Retorna um Candidato de uma lista pelo index
	// Obs: -
    Candidato returnCandidato(list<Candidato> lista, Candidato &c, int one);

    // Função que retorna a posição de um Candidato na lista
	// Obs: -
    int returnPosicao(list<Candidato> lista, string nome);
};


#endif /* lib_h_ */
