#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <iterator>

#include "Leitura.hpp"
#include "Lib.hpp"
#include "Date.hpp"

using namespace std;

Leitura::Leitura(){
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

Leitura::~Leitura(){
	// TODO Auto-generated destructor stub
}

int getNumeroLinhas(string path){
    int c = 0;
    string line;
    ifstream myfile (path); // ifstream = padrão ios:in

    if (myfile.is_open()){
        while (!myfile.eof()){ //enquanto end of file for false continua
            getline (myfile,line); // como foi aberto em modo texto(padrão)
            c++;
        }
        myfile.close();
    }
    
    return c;
}

void Leitura::lePartidos(Eleicao &vereadores, string &path, list<Candidato> c){
    string line;
    ifstream myfile (path); // ifstream = padrão ios:in
    int bit = 0;
    list<Candidato> nova;

    int numeroLinhas = getNumeroLinhas(path) - 1;

    if (myfile.is_open()){
        // while (!myfile.eof()){ //enquanto end of file for false continua
        while(numeroLinhas != 0){
            getline (myfile,line); // como foi aberto em modo texto(padrão)
            // cout << line << endl; // delete
            if(bit == 0){
                bit++;
            } else{
                list< string, allocator<string> > tokens;
                // stringstream class check1
                stringstream check1(line);
                string intermediate;
                
                // Tokenizing w.r.t. comma ','
                while(getline(check1, intermediate, ',')){
                    tokens.push_back(intermediate);
                }

                list < string, allocator<string> > :: iterator it;
                int nPartido;
                int vLegenda;
                string nomePartido;
                string siglaPartido;

                for(it = tokens.begin(); it != tokens.end(); ++it){
                    Lib help = Lib();

                    nPartido = help.stringToInt(*it);
                    // cout << nPartido;
                    it++;

                    vLegenda = help.stringToInt(*it); 
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

                list < Candidato, allocator<Candidato> > :: iterator it2;
                for(it2 = c.begin(); it2 != c.end(); ++it2){
                    Candidato a = *it2;
                    if(a.getNumeroPartidoCandidato() == nPartido){
                        // a.printCandidato();
                        nova.push_back(a);
                    }
                }

                // cout << " == " << nPartido << " == " << endl;
                for(it2 = nova.begin(); it2 != nova.end(); ++it2){
                    Candidato a = *it2;
                    if(a.getNumeroPartidoCandidato() == nPartido){
                        // a.printCandidato();
                    }
                }

                Partido x = Partido(nPartido, vLegenda, nomePartido, siglaPartido, nova); 
                // x.printPartido();
                vereadores.addPartido(x);
                nova.clear();
                // cout << x.getNumeroPartido() << " - " << x.getVotosLegendaPartido() << " - " << x.getNomePartido() << " - " << x.getSiglaPartido() << endl;
                cout << endl;
            }
            numeroLinhas--;
        }
        myfile.close();

    } else{ 
        cout << "Unable to open file";
    }
}

list<Candidato> Leitura::leCandidatos(Eleicao &vereadores, string &path){
    string line;
    ifstream myfile (path); // ifstream = padrão ios:in
    int bit = 0;
    int counter = 0;
    int deleteAfter = 0;
    int countPartidos = vereadores.retornaNumeroPartidos();
    list<Candidato> lista;

    int numeroLinhas = getNumeroLinhas(path) - 1;


    if (myfile.is_open()){
        while(numeroLinhas != 0){ //enquanto end of file for false continua
        // cout << "oh no" << endl;
        // while (! myfile.eof()){ //enquanto end of file for false continua
            getline (myfile,line); // como foi aberto em modo texto(padrão)
            // cout << line << endl; // delete
            if(bit == 0){
                bit++;
            } else{
                list< string, allocator<string> > tokens;
                // stringstream class check1
                stringstream check1(line);
                string intermediate;
                
                // Tokenizing w.r.t. comma ','
                while(getline(check1, intermediate, ',')){
                    tokens.push_back(intermediate);
                }
                
                list < string, allocator<string> > :: iterator it;
                int numCandidato;
                int vNominaisCandidato;
                string situCandidato;
                string noCandidato;
                string noUrnaCandidato;
                char sexCandidato;
                Date datNascCandidato;
                string destVotoCandidato;
                int nPartidoCandidato;


                for(it = tokens.begin(); it != tokens.end(); ++it){
                    Lib help = Lib();

                    numCandidato = help.stringToInt(*it);
                    // cout << numCandidato << " ";
                    it++;

                    vNominaisCandidato = help.stringToInt(*it);
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

                    sexCandidato = help.stringToChar(*it);
                    // cout << sexCandidato << " ";
                    it++;

                    if(situCandidato.compare(comparaSituacao) == 0 && sexCandidato == comparaSexof) {
                        qtdMulheresEleitas++;
                    }else if(situCandidato.compare(comparaSituacao) == 0 && sexCandidato == comparaSexom) {
                        qtdHomensEleitos++; 
                    }

                    datNascCandidato = help.stringToDate(*it);
                    // datNascCandidato.print_date();
                    it++;

                    destVotoCandidato = *it;
                    // cout << destVotoCandidato;
                    it++;

                    nPartidoCandidato = help.stringToInt(*it);
                    // cout << nPartidoCandidato;

                }

                Candidato c = Candidato(numCandidato, vNominaisCandidato, situCandidato, noCandidato, noUrnaCandidato, sexCandidato, datNascCandidato, destVotoCandidato, nPartidoCandidato); 
             
                // vereadores.insereCandidatos(&c);
                // lista.insert(lista.end(), c);
                lista.push_back(c);
               
            }
            numeroLinhas--;
        }
        myfile.close();
        totalVotos = totalVotosLegenda + totalVotosNominais; 

                // vereadores.printEleicao();

    } else{ 
        cout << "Unable to open file";
    }

    return lista;
}