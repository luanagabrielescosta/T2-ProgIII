#include "Partidos.hpp"

class votosPartidosComparator{
	// @Override
	public:
	int compare(Partidos o1, Partidos o2) {
		return o1.getVotosTotaisPartido() - o2.getVotosTotaisPartido();
	}
};
