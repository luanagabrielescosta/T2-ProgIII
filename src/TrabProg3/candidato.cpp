/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ cpp da classe de candidatos
*/

#include <iostream>
#include <istream>
#include <string>
#include "Candidato.hpp"

using namespace std;

// Constructor
Candidato::Candidato(int numeroCandidato, int votosNominaisCandidato,string &situacaoCandidato,string &nomeCandidato,string &nomeUrnaCandidato,
		char &sexoCandidato, Date &dataNascimentoCandidato, string &destinoVoto, int numeroPartidoCandidato){
	this->numeroCandidato = numeroCandidato;
	this->votosNominaisCandidato = votosNominaisCandidato;
	this->situacaoCandidato = situacaoCandidato;
	this->nomeCandidato = nomeCandidato;
	this->nomeUrnaCandidato = nomeUrnaCandidato;
	this->sexoCandidato = sexoCandidato;
	this->dataNascimentoCandidato = Date();
	this->dataNascimentoCandidato.turnInto(dataNascimentoCandidato);
	this->destinoVoto = destinoVoto;
	this->numeroPartidoCandidato = numeroPartidoCandidato;
}

// Destructor 
Candidato::~Candidato(){
	// TODO Auto-generated destructor stub
}

// Função simples explicada no .hpp
int Candidato::getNumeroCandidato(){
	return numeroCandidato;
}

// Função simples explicada no .hpp
int Candidato::getVotosNominaisCandidato(){
	return votosNominaisCandidato;
}

// Função simples explicada no .hpp
string Candidato::getSituacaoCandidato(){
	return situacaoCandidato;
}

// Função simples explicada no .hpp
string Candidato::getNomeCandidato(){
	return nomeCandidato;
}

// Função simples explicada no .hpp
string Candidato::getNomeUrnaCandidato(){
	return nomeUrnaCandidato;
}

// Função simples explicada no .hpp
char Candidato::getSexoCandidato(){
	return sexoCandidato;
}

// Função simples explicada no .hpp
Date Candidato::getDataNascimentoCandidato(){
	return dataNascimentoCandidato;
}

// Função simples explicada no .hpp
string Candidato::getDestinoVoto(){
	return destinoVoto;
}

// Função simples explicada no .hpp
int Candidato::getNumeroPartidoCandidato(){
	return numeroPartidoCandidato;
}

// Função simples explicada no .hpp
int Candidato::compareCandidato(Candidato &o){
	if(this->numeroCandidato == o.getNumeroCandidato()){ // compara numero
		if(this->votosNominaisCandidato == o.getVotosNominaisCandidato()){
			if(this->situacaoCandidato.compare(o.getSituacaoCandidato()) == 0){
				if(this->nomeCandidato.compare(o.getNomeCandidato()) == 0){
					if(this->nomeUrnaCandidato.compare(o.getNomeUrnaCandidato()) == 0){
						if(this->sexoCandidato == o.getSexoCandidato()){
							if(this->dataNascimentoCandidato.compareDate(this->dataNascimentoCandidato, o.getDataNascimentoCandidato()) == 0){
								if(this->destinoVoto.compare(o.getDestinoVoto()) == 0){
									if(this->numeroPartidoCandidato == o.getNumeroPartidoCandidato()){
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	} 
	return 1;
}

// Função simples explicada no .hpp
void Candidato::printCandidato(){
	cout << this->numeroCandidato << " - ";
	cout << this->votosNominaisCandidato << " - "; 
	cout << this->situacaoCandidato << " - "; 
	cout << this->nomeCandidato << " - ";
	cout << this->nomeUrnaCandidato << " - ";
	cout << this->sexoCandidato << " - "; 
	this->dataNascimentoCandidato.printDate();
	cout << " - ";
	cout << this->destinoVoto << " - "; 
	cout << this->numeroPartidoCandidato << endl;
}