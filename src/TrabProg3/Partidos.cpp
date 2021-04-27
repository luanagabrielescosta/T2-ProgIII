package TrabProg3;

import java.util.ArrayList;


public class Partidos implements Comparable<Partidos>{

	ArrayList <Candidatos> candidatosPartido; 
	int numeroPartido; 
	int votosLegendaPartido; 
	String nomePartido; 
	String siglaPartido; 
	int votosNominaisTotaisPartido;
	public int getVotosNominaisTotaisPartido() {
		return votosNominaisTotaisPartido;
	}

	public void setVotosNominaisTotaisPartido(int votosNominaisTotaisPartido) {
		this.votosNominaisTotaisPartido = votosNominaisTotaisPartido;
	}

	int votosTotaisPartido;
	//int qtdCandidatosEleitos
	
	public int getVotosTotaisPartido() {
		return votosTotaisPartido;
	}

	public void setVotosTotaisPartido(int votosTotaisPartido) {
		this.votosTotaisPartido = votosTotaisPartido;
	}

	public Partidos(int numeroPartido, int votosLegendaPartido,
			String nomePartido, String siglaPartido) {
		super();
		this.candidatosPartido = new ArrayList <Candidatos>();
		this.numeroPartido = numeroPartido;
		this.votosLegendaPartido = votosLegendaPartido;
		this.nomePartido = nomePartido;
		this.siglaPartido = siglaPartido;
	}

	public ArrayList<Candidatos> getCandidatosPartido() {
		return candidatosPartido;
	}

	public int getNumeroPartido() {
		return numeroPartido;
	}

	public int getVotosLegendaPartido() {
		return votosLegendaPartido;
	}

	public String getNomePartido() {
		return nomePartido;
	}

	public String getSiglaPartido() {
		return siglaPartido;
	}
	
	void addCandidato(Candidatos c){
		this.candidatosPartido.add(c);
	}

	@Override
	public int compareTo(Partidos o) {
		// TODO Auto-generated method stub
		return 0;
	}
	
	
}
