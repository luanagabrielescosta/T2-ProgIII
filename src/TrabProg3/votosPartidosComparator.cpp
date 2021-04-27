package TrabProg3;

import java.util.Comparator;

public class votosPartidosComparator implements Comparator<Partidos>{

	@Override
	public int compare(Partidos o1, Partidos o2) {
		return o1.getVotosTotaisPartido() - o2.getVotosTotaisPartido();
	}
	
}
