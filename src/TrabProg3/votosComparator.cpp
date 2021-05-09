#include "votosComparator.hpp"
#include "date.hpp"

using namespace std;

	// int votosComparator::compare(candidato o1, candidato o2) {
	// 	if(o1.getVotosNominaisCandidato() - o2.getVotosNominaisCandidato() == 0) {
	// 		return o2.getDataNascimentoCandidato().compareTo(o1.getDataNascimentoCandidato());
	// 	} else{
	// 		return o1.getVotosNominaisCandidato() - o2.getVotosNominaisCandidato();	
	// 	}
		
	// }
bool votosComparator::compare(candidato first, candidato second){
	if(first.getVotosNominaisCandidato() == second.getVotosNominaisCandidato()){
		aaaaa;
	}

	return first.getVotosNominaisCandidato() - second.getVotosNominaisCandidato();
}

bool votosComparator::compare2(candidato o1, candidato o2) {
		if(o1.getVotosNominaisCandidato() - o2.getVotosNominaisCandidato() == 0) {
			return o2.getNumeroPartidoCandidato() - o1.getNumeroPartidoCandidato();
		}else {
			return o1.getVotosNominaisCandidato() - o2.getVotosNominaisCandidato();	
		}
}

bool votosComparator::comparePartido(partido o1, partido o2) {
		return o1.getVotosTotaisPartido() - o2.getVotosTotaisPartido();
}