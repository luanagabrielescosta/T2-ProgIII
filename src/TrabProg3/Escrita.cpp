#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "escrita.hpp"
#include "lib.hpp"

using namespace std;

escrita::escrita(){
}

bool escrita::escreveArquivo(string path, date dataeleicao, eleicao vereadores) {
    try{
        // Listas 
        list<partido> listaPartidos = vereadores.getpartidoeleicao(); 
        list<string> infoCandidatoEleito; 
        list<candidato> candidatosEleitos;
        list<candidato> candidatosVotos;
        list<candidato> candidatosMaisVotados; 
        list<candidato> candidatosEleitosMajoritariamente; 
        list<candidato> maisVotadoPartido; 
        list<candidato> menosVotadoPartido;			
        list<int> posicaoRanking;
        list<int> posicaoRankingMenosVotadosEleitos;

        // Variaveis
        int posicaoEleito = 1;
        int totalCandidatos = 0;
        int aux = 0;
        int cont = 0;
        int posicaoCandidato = 1;
        int eleitoMenosVotos = 10000;
        int qtdVagas = 0;
        int comparaPartido; 
        int candidatoMenosVotado = 10000;
        int candidatoMaisVotado = 0;
        int numeroCandidatoMenosVotado;
        int numeroCandidatoMaisVotado;
        int totalVotosNominaisPartido = 0;
        int totalVotosPartido = 0;
        int qtdEleitosPartido = 0;
        int qtdPartidos = 0;
        int totalVotos = 0;
        int totalVotosNominais = 0;
        int totalVotosLegenda = 0;
        int qtdMulheresEleitas = 0;
        int qtdHomensEleitos = 0;
        int idadeAbaixoTrinta = 0;
        int idadeAbaixoQuarenta = 0;
        int idadeAbaixoCinquenta = 0;
        int idadeAbaixoSessenta = 0;
        int idadeAcimaSessenta = 0;

        double porcentagemEleitasF;
        double porcentagemEleitosM;
        double porcentagemVnominais;
        double porcentagemVlegenda;

        char comparaSexoF = 'F';
        char comparaSexoM = 'M'; 

        string comparaSituacao = "Eleito";
        string line;

        lib help = lib();

        list<partido> :: iterator it;

        for(it = listaPartidos.begin(); it != listaPartidos.end(); ++it){
            qtdPartidos++;
            partido p = *it;
            totalVotosLegenda = totalVotosLegenda + p.getVotosLegendaPartido(); 

            list<candidato> :: iterator it2;

            for(it2 = p.getcandidatoPartido().begin(); it2 != p.getcandidatoPartido().end(); ++it2) {
                totalCandidatos++;
                candidato c = *it2;

                // candidato pessoa = candidato(c.getNumeroCandidato(), c.getVotosNominaisCandidato(), c.getSituacaoCandidato(), c.getNomeCandidato(), c.getNomeUrnaCandidato(), c.getSexoCandidato(), c.getDataNascimentoCandidato(), c.getDestinoVoto(), c.getNumeroPartidoCandidato());
                candidato pessoa = candidato(c.getNumeroCandidato(), c.getVotosNominaisCandidato(), c.getSituacaoCandidato(), c.getNomeCandidato(), c.getNomeUrnaCandidato(), c.getSexoCandidato(), c.getDataNascimentoCandidato(), c.getDestinoVoto(), c.getNumeroPartidoCandidato());
                candidatosVotos.insert(candidatosVotos.end(), pessoa); 

                if(c.getSituacaoCandidato().compare(comparaSituacao)){
                    candidatosEleitos.insert(candidatosEleitos.end(), pessoa);
                    qtdVagas++; 
                    infoCandidatoEleito.insert(infoCandidatoEleito.end(), c.getNomeCandidato() + " / " + c.getNomeUrnaCandidato() + " (" + p.getSiglaPartido() + ", " + help.int_to_char(c.getVotosNominaisCandidato()) + " votos)");
                    
                    if(c.getSexoCandidato() == comparaSexoF){
                        qtdMulheresEleitas++; 
                    } else if(c.getSexoCandidato() == comparaSexoM){
                        qtdHomensEleitos++;
                    }   
                } else{
                    totalVotosNominais += c.getVotosNominaisCandidato();	
                }
            }
        }

        ofstream myfile (path); // ifstream = padrão ios:in
        int bit = 0;

        if (myfile.is_open()){
            myfile << "bolinha" << endl;
            myfile.close();

        } else{ 
            cout << "Unable to open file";
        }
    } catch (invalid_argument& e){
        cerr << e.what() << endl;
        return false;
    }

    return true;
}   
