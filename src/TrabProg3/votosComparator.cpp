#include "Candidatos.hpp"

class votosComparator{
	// @Override
	public: 
	int compare(Candidatos o1, Candidatos o2) {
		if(o1.getVotosNominaisCandidato() - o2.getVotosNominaisCandidato() == 0) {
			return o2.getDataNascimentoCandidato().compareTo(o1.getDataNascimentoCandidato());
		}else {
			return o1.getVotosNominaisCandidato() - o2.getVotosNominaisCandidato();	
		}
		
	}

};
