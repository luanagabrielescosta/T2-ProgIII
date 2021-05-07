#include "votosComparator2.hpp"
 
	int votosComparator2::compare(candidato o1, candidato o2) {
		if(o1.getVotosNominaisCandidato() - o2.getVotosNominaisCandidato() == 0) {
			return o2.getNumeroPartidoCandidato() - o1.getNumeroPartidoCandidato();
		}else {
			return o1.getVotosNominaisCandidato() - o2.getVotosNominaisCandidato();	
		}
	}