/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ hpp da classe de data
*/

#ifndef date_h_
#define date_h_

#include <iostream>
#include <string>
using namespace std;

// A classe de data foi implementada pelos alunos para simplificar a utilização
// e assemelhar à metodologia utilizada no trabalho de java
class Date{
	// Atributos
    int day;
    int month;
    int year;
    
    public:
	// Constructor
    Date();
	// Destructor
    ~Date();

	// Métodos

    // Função que atribui inteiros numa data 
	// Obs: Criada para que o constructor fosse livre de parâmetros
    void enterDate(int d, int m, int y);

    // Função que imprime a data
	// Obs: Função usada apenas em testes
    void printDate();

    // Função que retorna o dia da data
	// Obs: Atributo - day
    int returnDay();

    // Função que retorna o mês da data 
	// Obs: Atributo - month
    int returnMonth();

    // Função que retorna o dia da ano 
	// Obs: Atributo - year
    int returnYear();

    // Função que atribui uma data em outra 
	// Obs: -
    void turnInto(Date &new_date);

    // Função que compara duas datas
	// Obs: igual retorna 0 | diferente retorna 1
    int compareDate(Date other, Date another);

    // Função que retorna a idade de um Candidato 
	// Obs: -
    int idade(Date &other);

    // Função que compara para sort 
	// Obs: -
    bool compareTo(Date other);
};

#endif /* date_h_ */