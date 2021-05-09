#ifndef votos_comparator_hpp_
#define votos_comparator_hpp_

#include "candidato.hpp"
#include "partido.hpp"

class votosComparator{
	// @Override
	public: 
	bool compare(candidato first, candidato second);
	bool compare2(candidato o1, candidato o2);
	bool comparePartido(partido o1, partido o2);
};

#endif /* votos_comparator_hpp_ */