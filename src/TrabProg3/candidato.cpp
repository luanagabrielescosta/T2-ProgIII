// package TrabProg3;

#include <iostream>
#include <istream>
#include <string>
#include "Candidato.hpp"
// #include "date.hpp"

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
	this->dataNascimentoCandidato.turn_into(dataNascimentoCandidato);
	this->destinoVoto = destinoVoto;
	this->numeroPartidoCandidato = numeroPartidoCandidato;
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

int Candidato::compare_candidato(Candidato o){
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

list<const Candidato> Candidato::retornaConst(list<Candidato> o){
	list<const Candidato> retorno;
	list<Candidato> :: iterator it;

	for(it = o.begin(); it != o.end(); ++it){
		retorno.insert(retorno.end(), *it);
	}

	return retorno;
}
