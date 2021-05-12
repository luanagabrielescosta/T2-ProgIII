/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ cpp da classe de data
*/

#include <iostream>
#include <string>
#include "Date.hpp"

using namespace std;

// Constructor
Date::Date(){
}

// Destructor 
Date::~Date(){
	// TODO Auto-generated destructor stub
}

// Função simples explicada no .hpp
void Date::enterDate(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}

// Função simples explicada no .hpp
void Date::printDate(){
    cout<<this->day<<"/"<<this->month<<"/"<<year;
} 

// Função simples explicada no .hpp
int Date::returnDay(){
    return this->day;
}

// Função simples explicada no .hpp
int Date::returnMonth(){
    return this->month;
}

// Função simples explicada no .hpp
int Date::returnYear(){
    return this->year;
}

// Função simples explicada no .hpp
void Date::turnInto(Date &new_date){
    this->day = new_date.returnDay();
    this->month = new_date.returnMonth();
    this->year = new_date.returnYear();
}

// Função simples explicada no .hpp
int Date::compareDate(Date other, Date another){
    if(other.returnYear() == another.returnYear()){
        if(other.returnMonth() == another.returnMonth()){
            if(other.returnDay() == another.returnDay()){
                return 0;
            }
        }
    }

    return 1;
}

// Função de calculo de idade
int Date::idade(Date &other){
    // Calcula a diferença de anos 
    int idade = other.returnYear() - this->year;

    // Verifica se o mês da eleição é depois do mês do aniversário
    if(other.returnMonth() > this->month){
        // Se for, se reduz a idade pois o Candidato ainda não fez aniversário
        idade--;
    // Se o mês for igual, verifica se o dia da eleição é depois do mês do aniversário
    } else if((other.returnMonth() == this->month) && (other.returnDay() >= this->day)){
        // Se for, se reduz a idade pois o Candidato ainda não fez aniversário
        idade--;
    }

    return idade;
}

// Função de comparação para sort
bool Date::compareTo(Date other){
    // compara o ano, se o primeiro for maior, retorna true
    if(this->returnYear() > other.returnYear()){ 
        return true;
    // se o ano for igual, compara o mês
    } else if((this->returnYear() == other.returnYear()) && (this->returnMonth() > other.returnMonth())){ 
        return true;
    // sem os anteriores forem iguais, compara o dia
    } else if((this->returnYear() == other.returnYear()) && (this->returnMonth() == other.returnMonth()) && (this->returnDay() > other.returnDay())){
        return true;
    }

    return false;
}
