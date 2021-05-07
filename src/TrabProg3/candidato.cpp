// package TrabProg3;

#include <iostream>
#include <string>
#include "candidato.hpp"
// #include "date.hpp"

using namespace std;

	candidato::candidato(int &numeroCandidato, int &votosNominaisCandidato,string &situacaoCandidato,string &nomeCandidato,string &nomeUrnaCandidato,
			string &sexoCandidato, date &dataNascimentoCandidato, string &destinoVoto, int &numeroPartidoCandidato){
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

	string candidato::getSexoCandidato(){
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

	// @Override
	// int candidato::compareTo(candidato o){
	// 	// TODO Auto-generated method stub
	// 	return 0;
	// }

