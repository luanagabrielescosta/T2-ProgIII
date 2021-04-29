#include "Candidatos.hpp"

class votosComparator2{
	// @Override
	public: 
	int compare(Candidatos o1, Candidatos o2) {
		if(o1.getVotosNominaisCandidato() - o2.getVotosNominaisCandidato() == 0) {
			return o2.getNumeroPartidoCandidato() - o1.getNumeroPartidoCandidato();
		}else {
			return o1.getVotosNominaisCandidato() - o2.getVotosNominaisCandidato();	
		}
	}
};