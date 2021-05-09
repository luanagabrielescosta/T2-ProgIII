// package TrabProg3;

#include <iostream>
#include <string>
#include "candidato.hpp"
// #include "date.hpp"

using namespace std;

candidato::candidato(int numeroCandidato, int votosNominaisCandidato,string &situacaoCandidato,string &nomeCandidato,string &nomeUrnaCandidato,
		char &sexoCandidato, date &dataNascimentoCandidato, string &destinoVoto, int numeroPartidoCandidato){
	this->numeroCandidato = numeroCandidato;
	this->votosNominaisCandidato = votosNominaisCandidato;
	this->situacaoCandidato = situacaoCandidato;
	this->nomeCandidato = nomeCandidato;
	this->nomeUrnaCandidato = nomeUrnaCandidato;
	this->sexoCandidato = sexoCandidato;
	this->dataNascimentoCandidato = date();
	this->dataNascimentoCandidato.turn_into(dataNascimentoCandidato);
	this->destinoVoto = destinoVoto;
	this->numeroPartidoCandidato = numeroPartidoCandidato;
}

int candidato::getNumeroCandidato(){
	return numeroCandidato;
}

int candidato::getVotosNominaisCandidato(){
	return votosNominaisCandidato;
}

string candidato::getSituacaoCandidato(){
	return situacaoCandidato;
}

string candidato::getNomeCandidato(){
	return nomeCandidato;
}

string candidato::getNomeUrnaCandidato(){
	return nomeUrnaCandidato;
}

char candidato::getSexoCandidato(){
	return sexoCandidato;
}

date candidato::getDataNascimentoCandidato(){
	return dataNascimentoCandidato;
}

string candidato::getDestinoVoto(){
	return destinoVoto;
}

int candidato::getNumeroPartidoCandidato(){
	return numeroPartidoCandidato;
}

int candidato::compare_candidato(candidato o){
	if(this->numeroCandidato == o.getNumeroCandidato()){
		if(this->votosNominaisCandidato == o.getVotosNominaisCandidato()){
			if(this->situacaoCandidato.compare(o.getSituacaoCandidato()) == 0){
				if(this->nomeCandidato.compare(o.getNomeCandidato()) == 0){
					if(this->nomeUrnaCandidato.compare(o.getNomeUrnaCandidato()) == 0){
						if(this->sexoCandidato == o.getSexoCandidato()){
							if(this->dataNascimentoCandidato.compare_date(this->dataNascimentoCandidato, o.getDataNascimentoCandidato()) == 0){
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
