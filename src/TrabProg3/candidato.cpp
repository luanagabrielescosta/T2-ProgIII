#include <iostream>
#include <istream>
#include <string>
#include "Candidato.hpp"

using namespace std;

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

Candidato::~Candidato(){
	// TODO Auto-generated destructor stub
}


int Candidato::getNumeroCandidato(){
	return numeroCandidato;
}

int Candidato::getVotosNominaisCandidato(){
	return votosNominaisCandidato;
}

string Candidato::getSituacaoCandidato(){
	return situacaoCandidato;
}

string Candidato::getNomeCandidato(){
	return nomeCandidato;
}

string Candidato::getNomeUrnaCandidato(){
	return nomeUrnaCandidato;
}

char Candidato::getSexoCandidato(){
	return sexoCandidato;
}

Date Candidato::getDataNascimentoCandidato(){
	return dataNascimentoCandidato;
}

string Candidato::getDestinoVoto(){
	return destinoVoto;
}

int Candidato::getNumeroPartidoCandidato(){
	return numeroPartidoCandidato;
}

int Candidato::compare_candidato(Candidato &o){
	if(this->numeroCandidato == o.getNumeroCandidato()){
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