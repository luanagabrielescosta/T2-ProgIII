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

void Leitura::lePartidos(Eleicao &vereadores, string &path){
    string line;
    ifstream myfile (path); // ifstream = padrão ios:in
    int bit = 0;

    if (myfile.is_open()){
        while (!myfile.eof()){ //enquanto end of file for false continua
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

                Partido x = Partido(nPartido, vLegenda, nomePartido, siglaPartido); 
                
                vereadores.addPartido(x);
                // cout << x.getNumeroPartido() << " - " << x.getVotosLegendaPartido() << " - " << x.getNomePartido() << " - " << x.getSiglaPartido() << endl;
                cout << endl;
            }
        }
        myfile.close();

    } else{ 
        cout << "Unable to open file";
    }
}

void Leitura::leCandidatos(Eleicao &vereadores, string &path){
    string line;
    ifstream myfile (path); // ifstream = padrão ios:in
    int bit = 0;
    int deleteAfter = 0;
    list<Candidato> desespero;

    if (myfile.is_open()){
        while (! myfile.eof()){ //enquanto end of file for false continua
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

                // desespero = vereadores.retornaPartidoPeloNum(nPartidoCandidato).getcandidatoPartido();
                Candidato c = Candidato(numCandidato, vNominaisCandidato, situCandidato, noCandidato, noUrnaCandidato, sexCandidato, datNascCandidato, destVotoCandidato, nPartidoCandidato); 
                // vereadores.insereCandidatos(nPartidoCandidato, c);
                // desespero.insert(desespero.end(), c);
                // desespero.insert(desespero.end(), c);

                // list< Candidato, allocator<Candidato> > :: iterator it3;

                // cout << desespero.size() << endl;
                // for(it3 = desespero.begin(); it3 != desespero.end(); ++it3){
                //     Candidato a = *it3;
                //     a.printCandidato();
                // }

                // vereadores.insereCandidatos(nPartidoCandidato, desespero);


                // p.addCandidato(c);
                // Partido p = vereadores.retornaPartidoPeloNum(nPartidoCandidato); 
                // c.printCandidato();
                
                // p.printPartido();
	            // cout << p.getNumeroPartido();
	            // cout << endl;
                deleteAfter++;
                if(deleteAfter == 2) break;
            }
        }
        myfile.close();
        totalVotos = totalVotosLegenda + totalVotosNominais; 
        // vereadores.printEleicao();

    } else{ 
        cout << "Unable to open file";
    }
}