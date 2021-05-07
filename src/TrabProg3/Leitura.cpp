#include "leitura.hpp"
#include <string>

using namespace std;

    leitura::leitura(){
        this->comparaSituacao = "Eleito";
        this->comparaSexof = "F";
        this->comparaSexom = "M";
        this->qtdVagas = 0;
        this->qtdMulheresEleitas = 0;
        this->qtdHomensEleitos = 0;
        this-> totalVotos = 0;
        this->totalVotosNominais = 0;
        this->totalVotosLegenda = 0;
    }
	
	void leitura::lePartidos(eleicao vereadores, string path){
		BufferedReader buffRead = new BufferedReader(new InputStreamReader(new FileInputStream(path), "UTF-8"));
        string linha = "";
        buffRead.readLine();
        while (true) {
        	linha = buffRead.readLine();
            if (linha == null) {
               break;

            }
            stringTokenizer st = new stringTokenizer(linha,",");
     while (st.hasMoreTokens()) {
         
         nPartido = st.nextToken().trim();
         int numeroPartido = Integer.parseInt(nPartido); 
         vLegenda = st.nextToken().trim(); 
         int votosLegenda = Integer.parseInt(vLegenda);  
         totalVotosLegenda += votosLegenda; 
         
         nomePartido = st.nextToken(",").trim(); 
         siglaPartido = st.nextToken(",").trim(); 
         
         
        // System.out.println("Numero Partido: " + numeroPartido + " Votos legenda: " + votosLegenda + " Nome Partido: " + nomePartido + " Sigla Partido: " + siglaPartido) ;
         partido x = partido(numeroPartido, votosLegenda, nomePartido, siglaPartido); 
         vereadores.addPartido(x);
         
     }
        }
        buffRead.close();
	}
	
	void leitura::leCandidatos(eleicao vereadores, string path){
		BufferedReader buffRead = new BufferedReader(new InputStreamReader(new FileInputStream(path), "UTF-8"));
        string linha = "";
        buffRead.readLine();
        while (true) {
        	linha = buffRead.readLine();
            if (linha == null) {
               break;

            }
            stringTokenizer st = new stringTokenizer(linha,",");
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
         date data = formato.parse(datNascCandidato);
         destVotoCandidato = st.nextToken().trim(); 
         nPartidoCandidato = st.nextToken().trim();
         int numeroPartidoCandidato = Integer.parseInt(nPartidoCandidato); 
         
         
         partido p = vereadores.retornaPartidoPeloNum(numeroPartidoCandidato); 
         candidato c = candidato(numeroCandidato,votosNominaisCandidato,situCandidato,noCandidato,noUrnaCandidato,sexCandidato,data,destVotoCandidato,numeroPartidoCandidato); 
         p.addCandidato(c);
     }
     
        }
        buffRead.close();
        totalVotos = totalVotosLegenda + totalVotosNominais; 
	}