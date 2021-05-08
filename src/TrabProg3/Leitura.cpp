#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <iterator>
#include "leitura.hpp"
#include "lib.hpp"
#include "eleicao.hpp"
#include "date.hpp"

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
		string line;
        ifstream myfile (path); // ifstream = padrão ios:in
        int bit = 0;

        if (myfile.is_open()){
            while (! myfile.eof()){ //enquanto end of file for false continua
                getline (myfile,line); // como foi aberto em modo texto(padrão)
                // cout << line << endl; // delete
                if(bit == 0){
                    bit++;
                } else{
                    list<string> tokens;
                    // stringstream class check1
                    stringstream check1(line);
                    string intermediate;
                    
                    // Tokenizing w.r.t. comma ','
                    while(getline(check1, intermediate, ',')){
                        tokens.push_back(intermediate);
                    }
                    
                    list <string> :: iterator it;
                    int nPartido;
                    int vLegenda;

                    for(it = tokens.begin(); it != tokens.end(); ++it){
                        lib help = lib();

                        nPartido = help.string_to_int(*it);
                        // cout << nPartido << " *===* ";
                        it++;

                        vLegenda = help.string_to_int(*it); 
                        // cout << vLegenda << " &===& ";
                        it++;

                        totalVotosLegenda += vLegenda; 
                        // cout << totalVotosLegenda << " a===a ";

                        string nomePartido = *it;
                        // cout << nomePartido << " (===) ";
                        it++; 

                        string siglaPartido = *it; 
                        // cout << siglaPartido << " m===m ";
                    }

                    partido x = partido(nPartido, vLegenda, nomePartido, siglaPartido); 
                    vereadores.addPartido(x);
                    cout << endl;
                }
            }
            myfile.close();

        } else{ 
            cout << "Unable to open file";
        }
	}

    void leitura::leCandidatos(eleicao vereadores, string path){
		string line;
        ifstream myfile (path); // ifstream = padrão ios:in
        int bit = 0;

        if (myfile.is_open()){
            while (! myfile.eof()){ //enquanto end of file for false continua
                getline (myfile,line); // como foi aberto em modo texto(padrão)
                // cout << line << endl; // delete
                if(bit == 0){
                    bit++;
                } else{
                    list<string> tokens;
                    // stringstream class check1
                    stringstream check1(line);
                    string intermediate;
                    
                    // Tokenizing w.r.t. comma ','
                    while(getline(check1, intermediate, ',')){
                        tokens.push_back(intermediate);
                    }
                    
                    list <string> :: iterator it;
                    int numCandidato;
                    int vNominaisCandidato;

                    for(it = tokens.begin(); it != tokens.end(); ++it){
                        lib help = lib();

                        numCandidato = help.string_to_int(*it);
                        // cout << numCandidato << " *===* ";
                        it++;
                        // numCandidato = st.nextToken().trim(); used to be

                        vNominaisCandidato = help.string_to_int(*it);
                        // cout << vNominaisCandidato << " *===* ";
                        it++;
                        // vNominaisCandidato = st.nextToken().trim();  used to be
                        totalVotosNominais += vNominaisCandidato; 
                        
                        // situCandidato = st.nextToken().trim();
                        // if(situCandidato.equals(comparaSituacao)) {
                        //     qtdVagas+=1; 
                        // }
                        // noCandidato = st.nextToken().trim(); 
                        // noUrnaCandidato = st.nextToken().trim(); 
                        // sexCandidato = st.nextToken().trim(); 
                        // if(situCandidato.equals(comparaSituacao) && sexCandidato.equals(comparaSexof)) {
                        //     qtdMulheresEleitas++;
                        // }else if(situCandidato.equals(comparaSituacao) && sexCandidato.equals(comparaSexom)) {
                        //     qtdHomensEleitos++; 
                        // }
                        // datNascCandidato = st.nextToken().trim(); 
                        // SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy");
                        // date data = formato.parse(datNascCandidato);
                        // destVotoCandidato = st.nextToken().trim(); 
                        // nPartidoCandidato = st.nextToken().trim();
                        // int numeroPartidoCandidato = Integer.parseInt(nPartidoCandidato); 
                        
                        
                        // partido p = vereadores.retornaPartidoPeloNum(numeroPartidoCandidato); 
                        // candidato c = candidato(numeroCandidato,votosNominaisCandidato,situCandidato,noCandidato,noUrnaCandidato,sexCandidato,data,destVotoCandidato,numeroPartidoCandidato); 
                        // p.addCandidato(c);
                    }

                    cout << endl;
                }
            }
            myfile.close();

        } else{ 
            cout << "Unable to open file";
        }
	}
	
	
	// void leitura::leCandidatos(eleicao vereadores, string path){
	// 	BufferedReader buffRead = new BufferedReader(new InputStreamReader(new FileInputStream(path), "UTF-8"));
    //     string linha = "";
    //     buffRead.readLine();
    //     while (true) {
    //     	linha = buffRead.readLine();
    //         if (linha == null) {
    //            break;

    //         }
    //         stringTokenizer st = new stringTokenizer(linha,",");
    //  while (st.hasMoreTokens()) {
         
    //      numCandidato = st.nextToken().trim();
    //      int numeroCandidato = Integer.parseInt(numCandidato); 
    //      vNominaisCandidato = st.nextToken().trim(); 
    //      int votosNominaisCandidato = Integer.parseInt(vNominaisCandidato); 
    //      totalVotosNominais += votosNominaisCandidato; 
    //      situCandidato = st.nextToken().trim();
    //      if(situCandidato.equals(comparaSituacao)) {
    //     	 qtdVagas+=1; 
    //      }
    //      noCandidato = st.nextToken().trim(); 
    //      noUrnaCandidato = st.nextToken().trim(); 
    //      sexCandidato = st.nextToken().trim(); 
    //      if(situCandidato.equals(comparaSituacao) && sexCandidato.equals(comparaSexof)) {
    //     	 qtdMulheresEleitas++;
    //      }else if(situCandidato.equals(comparaSituacao) && sexCandidato.equals(comparaSexom)) {
    //     	 qtdHomensEleitos++; 
    //      }
    //      datNascCandidato = st.nextToken().trim(); 
    //      SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy");
    //      date data = formato.parse(datNascCandidato);
    //      destVotoCandidato = st.nextToken().trim(); 
    //      nPartidoCandidato = st.nextToken().trim();
    //      int numeroPartidoCandidato = Integer.parseInt(nPartidoCandidato); 
         
         
    //      partido p = vereadores.retornaPartidoPeloNum(numeroPartidoCandidato); 
    //      candidato c = candidato(numeroCandidato,votosNominaisCandidato,situCandidato,noCandidato,noUrnaCandidato,sexCandidato,data,destVotoCandidato,numeroPartidoCandidato); 
    //      p.addCandidato(c);
    //  }
     
    //     }
    //     buffRead.close();
    //     totalVotos = totalVotosLegenda + totalVotosNominais; 
	// }