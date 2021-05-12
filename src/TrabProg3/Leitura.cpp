/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ hpp da classe de leitura
*/

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

// Constructor
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

// Destructor 
Leitura::~Leitura(){
	// TODO Auto-generated destructor stub
}

// Função de verificação do número de linhas do arquivo
int getNumeroLinhas(string path){
    int c = 0; // Contador inicializado
    string line;
    ifstream myfile (path); // ifstream = padrão ios:in

    if (myfile.is_open()){
        while (!myfile.eof()){
            getline (myfile,line); // Pega a linha
            c++; // Incrementa
        }
        myfile.close();
    }
    
    return c;
}

// Função de leitura do arquivo de partidos
void Leitura::lePartidos(Eleicao &vereadores, string &path, list<Candidato> c){
    string line; // string para getline
    ifstream myfile (path); // ifstream = padrão ios:in
    int bit = 0; // Variavel auxiliar para eliminar a primeira linha
    list<Candidato> nova; // lista de Candidatos auxiliar

    int numeroLinhas = getNumeroLinhas(path) - 1; // Armazena o número de linhas eliminando a primeira

    if (myfile.is_open()){
        while(numeroLinhas != 0){
            getline (myfile,line); // Pega a linha

            if(bit == 0){ //Ent ra se for a primeira linha
                bit++; // Incrementa o bit
            } else{
                list< string, allocator<string> > tokens; // Cria uma lista de tokens (string)

                stringstream check1(line);
                string intermediate;
                
                // Tokenizing com ','
                while(getline(check1, intermediate, ',')){
                    tokens.push_back(intermediate); // Colocando as informações sem ',' numa lista
                }

                list < string, allocator<string> > :: iterator it;
                int nPartido;
                int vLegenda;
                string nomePartido;
                string siglaPartido;

                for(it = tokens.begin(); it != tokens.end(); ++it){
                    Lib help = Lib(); // Lib tem funções auxiliares

                    nPartido = help.stringToInt(*it); // Converte a string pra int
                    it++;

                    vLegenda = help.stringToInt(*it); // Converte a string pra int
                    it++;

                    totalVotosLegenda += vLegenda; // Já soma os votos de legenda no total

                    nomePartido = *it; // Atribui o nome de partido
                    it++; 

                    siglaPartido = *it; // Atribui a sigla de partido
                }

                list < Candidato, allocator<Candidato> > :: iterator it2;
                // Loop na lista de candidatos passada de parâmetro
                for(it2 = c.begin(); it2 != c.end(); ++it2){
                    // Verifica o número do partido do candidato
                    if(it2->getNumeroPartidoCandidato() == nPartido){
                        nova.push_back(*it2); // Se for igual adiciona na lista auxiliar de candidatos do partido
                    }
                }

                // Inicializa o partido já com a lista de candidatos 
                Partido x = Partido(nPartido, vLegenda, nomePartido, siglaPartido, nova); 
                vereadores.addPartido(x); // Adiciona o partido na eleição
                nova.clear(); // Limpa a lista auxiliar
            }

            numeroLinhas--; // Decrementa o número de linhas
        }

        myfile.close(); // Fecha o arquivo de entrada
    } else{ 
        cout << "Unable to open partidos file" << endl;
    }
}

// Função de leitura do arquivo de candidatos
list<Candidato> Leitura::leCandidatos(Eleicao &vereadores, string &path){
    string line; // string para getline
    ifstream myfile (path); // ifstream = padrão ios:in
    int bit = 0; // Variavel auxiliar para eliminar a primeira linha
    list<Candidato> lista; // lista de Candidatos para retorno

    int numeroLinhas = getNumeroLinhas(path) - 1;// Armazena o número de linhas eliminando a primeira

    if (myfile.is_open()){
        while(numeroLinhas != 0){ 
            getline (myfile,line); // Pega a linha

            if(bit == 0){ //Ent ra se for a primeira linha
                bit++; // Incrementa o bit
            } else{
                list< string, allocator<string> > tokens; // Cria uma lista de tokens (string)

                stringstream check1(line);
                string intermediate;
                
                // Tokenizing com ','
                while(getline(check1, intermediate, ',')){
                    tokens.push_back(intermediate); // Colocando as informações sem ',' numa lista
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
                    Lib help = Lib(); // Lib tem funções auxiliares

                    numCandidato = help.stringToInt(*it); // Converte a string pra int
                    it++;

                    vNominaisCandidato = help.stringToInt(*it); // Converte a string pra int
                    it++;

                    totalVotosNominais += vNominaisCandidato; // Já soma os votos nominais no total
                    
                    situCandidato = *it; // Atribui a situação do candidato
                    it++;

                    if(situCandidato.compare(comparaSituacao) == 0){
                        qtdVagas++; // Incrementa se for candidato eleito
                    }

                    noCandidato = *it; // Atribui o nome do candidato
                    it++;

                    noUrnaCandidato = *it; // Atribui o nome de urna do candidato
                    it++;

                    sexCandidato = help.stringToChar(*it); // Converte a string pra char
                    it++;

                    if(situCandidato.compare(comparaSituacao) == 0 && sexCandidato == comparaSexof) {
                        qtdMulheresEleitas++; // Incrementa se for candidato do sexo feminino
                    }else if(situCandidato.compare(comparaSituacao) == 0 && sexCandidato == comparaSexom) {
                        qtdHomensEleitos++; // Incrementa se for candidato do sexo masculino
                    }

                    datNascCandidato = help.stringToDate(*it); // Converte a string pra Date (class autoral)
                    // datNascCandidato.print_date();
                    it++;

                    destVotoCandidato = *it; // Atribui a situação da validação do candidato
                    it++;

                    nPartidoCandidato = help.stringToInt(*it); // Converte a string pra int

                }

                // Inicializa o candidato com os dados obtidos
                Candidato c = Candidato(numCandidato, vNominaisCandidato, situCandidato, noCandidato, noUrnaCandidato, sexCandidato, datNascCandidato, destVotoCandidato, nPartidoCandidato); 
                lista.push_back(c); // Adiciona no fim da lista de retorno
               
            }
            
            numeroLinhas--;
        }
        
        myfile.close();// Fecha o arquivo de entrada
        totalVotos = totalVotosLegenda + totalVotosNominais; 
    } else{ 
        cout << "Unable to open candidatos file" << endl;
    }

    return lista;
}