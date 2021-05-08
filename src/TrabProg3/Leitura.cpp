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
        this->comparaSexof = 'F';
        this->comparaSexom = 'M';
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
                    string nomePartido;
                    string siglaPartido;

                    for(it = tokens.begin(); it != tokens.end(); ++it){
                        lib help = lib();

                        nPartido = help.string_to_int(*it);
                        // cout << nPartido;
                        it++;

                        vLegenda = help.string_to_int(*it); 
                        // cout << vLegenda;
                        it++;

                        totalVotosLegenda += vLegenda; 
                        // cout << totalVotosLegenda;

                        nomePartido = *it;
                        // cout << nomePartido;
                        it++; 

                        siglaPartido = *it; 
                        // cout << siglaPartido;
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
                    string situCandidato;
                    string noCandidato;
                    string noUrnaCandidato;
                    char sexCandidato;
                    date datNascCandidato;
                    string destVotoCandidato;
                    int nPartidoCandidato;

                    for(it = tokens.begin(); it != tokens.end(); ++it){
                        lib help = lib();

                        numCandidato = help.string_to_int(*it);
                        // cout << numCandidato << " ";
                        it++;

                        vNominaisCandidato = help.string_to_int(*it);
                        // cout << vNominaisCandidato << " ";
                        it++;

                        totalVotosNominais += vNominaisCandidato; 
                        
                        situCandidato = *it;
                        // cout << situCandidato << " ";
                        it++;

                        if(situCandidato.compare(comparaSituacao) == 0){
                            qtdVagas++; 
                        }

                        noCandidato = *it;
                        // cout << noCandidato << " ";
                        it++;

                        noUrnaCandidato = *it;
                        // cout << noUrnaCandidato << " ";
                        it++;

                        sexCandidato = help.string_to_char(*it);
                        // cout << sexCandidato << " ";
                        it++;

                        if(situCandidato.compare(comparaSituacao) == 0 && sexCandidato == comparaSexof) {
                            qtdMulheresEleitas++;
                        }else if(situCandidato.compare(comparaSituacao) == 0 && sexCandidato == comparaSexom) {
                            qtdHomensEleitos++; 
                        }

                        datNascCandidato = help.string_to_date(*it);
                        // datNascCandidato.print_date();
                        it++;

                        destVotoCandidato = *it;
                        // cout << destVotoCandidato;
                        it++;

                        nPartidoCandidato = help.string_to_int(*it);
                        // cout << nPartidoCandidato;

                    }
                    // partido p = vereadores.retornaPartidoPeloNum(numeroPartidoCandidato); 
                    // candidato c = candidato(numeroCandidato,votosNominaisCandidato,situCandidato,noCandidato,noUrnaCandidato,sexCandidato,data,destVotoCandidato,numeroPartidoCandidato); 
                    // p.addCandidato(c);

                    cout << endl;
                }
            }
            myfile.close();
            totalVotos = totalVotosLegenda + totalVotosNominais; 

        } else{ 
            cout << "Unable to open file";
        }
	}