#ifndef votos_comparator_hpp_
#define votos_comparator_hpp_

#include "Candidato.hpp"
#include "Partido.hpp"

class VotosComparator{
	// @Override
	public: 
	bool compare(Candidato first, Candidato second);
	bool compare2(Candidato o1, Candidato o2);
	bool comparePartido(Partido o1, Partido o2);
};

#endif /* votos_comparator_hpp_ */