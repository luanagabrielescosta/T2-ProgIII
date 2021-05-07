#include "votosPartidosComparator.hpp"

	int votosPartidosComparator::compare(partido o1, partido o2) {
		return o1.getVotosTotaisPartido() - o2.getVotosTotaisPartido();
	}
