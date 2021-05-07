package TrabProg3;

import TrabProg3.Eleicao.*;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Date;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.List;
import java.util.StringTokenizer;

public class leitura {
	
	String nPartido,vLegenda,nomePartido,siglaPartido; 
	String numCandidato,vNominaisCandidato,situCandidato,noCandidato,noUrnaCandidato,sexCandidato,datNascCandidato,destVotoCandidato,nPartidoCandidato;
	String comparaSituacao = "Eleito",comparaSexof = "F",comparaSexom = "M"; 
	int qtdVagas=0,qtdMulheresEleitas=0,qtdHomensEleitos=0,totalVotos=0,totalVotosNominais=0,totalVotosLegenda=0; 
	
	
	public void lePartidos(Eleicao vereadores, String path) throws IOException {
		
//		String path = "/home/joaogobeti/Downloads/afonso-claudio-partidos.csv"; 
		BufferedReader buffRead = new BufferedReader(new InputStreamReader(new FileInputStream(path), "UTF-8"));
        String linha = "";
        buffRead.readLine();
        while (true) {
        	linha = buffRead.readLine();
            if (linha == null) {
               break;

            }
            StringTokenizer st = new StringTokenizer(linha,",");
     while (st.hasMoreTokens()) {
         
         nPartido = st.nextToken().trim();
         int numeroPartido = Integer.parseInt(nPartido); 
         vLegenda = st.nextToken().trim(); 
         int votosLegenda = Integer.parseInt(vLegenda);  
         totalVotosLegenda += votosLegenda; 
         
         nomePartido = st.nextToken(",").trim(); 
         siglaPartido = st.nextToken(",").trim(); 
         
         
        // System.out.println("Numero Partido: " + numeroPartido + " Votos legenda: " + votosLegenda + " Nome Partido: " + nomePartido + " Sigla Partido: " + siglaPartido) ;
         Partidos x = new Partidos(numeroPartido,votosLegenda,nomePartido,siglaPartido); 
         vereadores.addPartido(x);
         
     }
        }
        buffRead.close();
	}
	
	public void leCandidatos(Eleicao vereadores, String path) throws IOException, ParseException{
		
//		String path = "/home/joaogobeti/Downloads/afonso-claudio-candidatos.csv"; 
		BufferedReader buffRead = new BufferedReader(new InputStreamReader(new FileInputStream(path), "UTF-8"));
        String linha = "";
        buffRead.readLine();
        while (true) {
        	linha = buffRead.readLine();
            if (linha == null) {
               break;

            }
            StringTokenizer st = new StringTokenizer(linha,",");
     while (st.hasMoreTokens()) {
         
         numCandidato = st.nextToken().trim();
         int numeroCandidato = Integer.parseInt(numCandidato); 
         vNominaisCandidato = st.nextToken().trim(); 
         int votosNominaisCandidato = Integer.parseInt(vNominaisCandidato); 
         totalVotosNominais += votosNominaisCandidato; 
         situCandidato = st.nextToken().trim();
         if(situCandidato.equals(comparaSituacao)) {
        	 qtdVagas+=1; 
         }
         noCandidato = st.nextToken().trim(); 
         noUrnaCandidato = st.nextToken().trim(); 
         sexCandidato = st.nextToken().trim(); 
         if(situCandidato.equals(comparaSituacao) && sexCandidato.equals(comparaSexof)) {
        	 qtdMulheresEleitas++;
         }else if(situCandidato.equals(comparaSituacao) && sexCandidato.equals(comparaSexom)) {
        	 qtdHomensEleitos++; 
         }
         datNascCandidato = st.nextToken().trim(); 
         SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy");
         Date data = formato.parse(datNascCandidato);
         destVotoCandidato = st.nextToken().trim(); 
         nPartidoCandidato = st.nextToken().trim();
         int numeroPartidoCandidato = Integer.parseInt(nPartidoCandidato); 
         
         
         Partidos p = vereadores.retornaPartidoPeloNum(numeroPartidoCandidato); 
         Candidatos c = new Candidatos(numeroCandidato,votosNominaisCandidato,situCandidato,noCandidato,noUrnaCandidato,sexCandidato,data,destVotoCandidato,numeroPartidoCandidato); 
         p.addCandidato(c);
         
         //System.out.println("numero Candidato: " + numeroCandidato); 
           
     }
     
        }
        buffRead.close();
        totalVotos = totalVotosLegenda + totalVotosNominais; 
        //System.out.println("VotosLegenda: " + totalVotosLegenda + "VotosNominais: " + totalVotosNominais + "'VotosTotais: " + totalVotos);
        //System.out.println("quantidade de vagas: " + qtdVagas); 
        //System.out.println("quantidade de mulheres eleitas: " + qtdMulheresEleitas); 
        //System.out.println("quantidade de homens eleitos: " + qtdHomensEleitos); 
	}
}
	
	
//Eleic�o --> Lista de partidos --> Partido x --> x.numero x.nome x.sigla
