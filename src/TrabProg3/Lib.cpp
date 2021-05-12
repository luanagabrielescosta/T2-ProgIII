/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ hpp da classe de lib (library)
*/

#include "Lib.hpp"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

// Constructor
Lib::Lib(){
}

// Destructor 
Lib::~Lib(){
	// TODO Auto-generated destructor stub
}

// Função que transforma string para inteiro 
int Lib::stringToInt(string &old){
    int count = 0; // Contador inicializado

    // Loop pela string
    for(int i = 0; i < old.size(); i++){
        count = count * 10 + (old[i] - 48);
        // count soma ele mesmo vezes 10 [ ex: 0 x 10 = 0, na primeira posição não soma]
        // e soma a string - 48, de acordo com a tabela ascii [ ex: 1 -> 49 - 18 = 1]
    }
    
    return count;
}

// Função que transforma string para Date 
Date Lib::stringToDate(string &old){
    int d, m, y; // Variável para dia, mês e ano
    Date a = Date(); // Date auxilia inicializado

    d = (old[0] - 48) * 10 + (old[1] - 48); // Pega os 2 primeiros caracteres e faz o esquema da função stringToInt
    m = (old[3] - 48) * 10 + (old[4] - 48); // Pula a / (posição 2) e pega os 2 próximos caracteres
    y = (old[6] - 48) * 1000 + (old[7] - 48) * 100 + (old[8] - 48) * 10 + (old[9] - 48); // Pula a / (posição 2) e pega os 4 últimos caracteres

    // Seta a o valor da data 
    a.enterDate(d, m, y);

    return a;
}

// Função simples explicada no .hpp
char Lib::stringToChar(string &old){
    return old[0];
}

// Função simples explicada no .hpp
char Lib::intToChar(int old){
    return (old +'0');
}

// Retorna int de uma lista 
int Lib::returnInt(list< int, allocator<int> > &lista, int one){
    int count = 0; // Contador inicializado
    list< int, allocator<int> > :: iterator it;

    // Loop na lista de int  
    for(it = lista.begin(); it != lista.end();it++){
		if(count == one){ // Verifica se chegou na posição
            return *it; // Se chegou retorna o int
        }

        count++; // Incrementa o contador
	}

    return 0;
}

// Retorna Candidato de uma lista 
Candidato Lib::returnCandidato(list<Candidato> lista, Candidato &c, int one){
    int count = 0; // Contador inicializado
    list< Candidato, allocator<Candidato> > :: iterator it;

    // Loop na lista de Candidato  
    for(it = lista.begin(); it != lista.end();it++){
		if(count == one){ // Verifica se chegou na posição
            return *it; // Se chegou retorna o Candidato
        }

        count++; // Incrementa o contador
	}

    return c;
}

// Retorna a posição de um candidato na lista 
int Lib::returnPosicao(list<Candidato> lista, string nome){
    int c = 0; // Contador inicializado
    list< Candidato, allocator<Candidato> > :: iterator it3;

    // Loop na lista de Candidato  
    for(it3 = lista.begin(); it3 != lista.end(); ++it3){
        if(it3->getNomeCandidato().compare(nome) == 0){ // Verifica o nome
            return c; // Se chegou retorna a posição do Candidato
        }
        
        c++; // Incrementa o contador
    }
    
    return c;
}
