/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ cpp da classe de escrita
*/

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <algorithm>
#include <iomanip> 
#include <list>
#include <locale>
#include "Escrita.hpp"
#include "Lib.hpp"

using namespace std;

// Constructor
Escrita::Escrita(){
}

// Desconstructor
Escrita::~Escrita(){
	// TODO Auto-generated destructor stub
}

// Função local de comparação de votos(nascimento como desempate) - usada em sort
bool compare(Candidato first, Candidato second){
    if(first.getVotosNominaisCandidato() > second.getVotosNominaisCandidato()){
        return false;
    }
	if (first.getVotosNominaisCandidato() == second.getVotosNominaisCandidato()){
		return first.getDataNascimentoCandidato().compareTo(second.getDataNascimentoCandidato());
	} 

	return true;	
}

// Funcão local de comparação de votos do partido - usada em sort
bool comparePartido(Partido first, Partido second){
    return first.getVotosTotaisPartido() > second.getVotosTotaisPartido();
}

// Funcão local de comparação de votos nominais do primeiro colocado do partido - usada em sort
bool compareVotosPartido(Partido first, Partido second){
    if(first.getVotosNominaisPrimeiro() > second.getVotosNominaisPrimeiro()){
        return true;
    }

    return false;
}

// Função de escrita - gerenciadora
bool Escrita::escreveArquivo(Date dataeleicao, Eleicao vereadores){
    // Try exception catch
    try{
        // Listas 
        list<Partido> listaPartidos = vereadores.getPartidoEleicao(); 
        list<string> infoCandidatoEleito; 
        list<Candidato> candidatosEleitos;
        list<Candidato> candidatosVotos;
        list<Candidato> candidatosMaisVotados; 
        list<Candidato> candidatosEleitosMajoritariamente; 
        list<Candidato> maisVotadoPartido; 
        list<Candidato> menosVotadoPartido;			
        vector<int> posicaoRanking;
        list<int> posicaoRankingMenosVotadosEleitos;

        // Variaveis
        int totalCandidatos = 0;
        int aux = 0;
        int cont = 0;
        int posicaoCandidato = 1;
        int eleitoMenosVotos = 10000;
        int qtdVagas = 0;
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

        Lib library = Lib(); // Lib inicializado

        // Variáveis iterator gerais 
        list< Partido, allocator<Partido> > :: iterator it;
        list< Candidato, allocator<Candidato> > :: iterator it2;
        list< Candidato, allocator<Candidato> > :: iterator it3;

        // Loop da lista de partido
        for(it = listaPartidos.begin(); it != listaPartidos.end(); ++it){
            qtdPartidos++; // Incrementa a quantidade de partidos
            totalVotosLegenda = totalVotosLegenda + it->getVotosLegendaPartido();
            list<Candidato> c = it->getCandidatoPartido();

            // Loop da lista de candidato
            for(it2 = c.begin(); it2 != c.end(); ++it2){
                totalCandidatos++; // Incrementa a quantidade de candidatos
                int vNumeroCandidato = it2->getNumeroCandidato();
                int vVotosNominaisCandidato = it2->getVotosNominaisCandidato();
                string vSituacaoCandidato = it2->getSituacaoCandidato();
                string vNomeCandidato = it2->getNomeCandidato();
                string vNomeUrnaCandidato = it2->getNomeUrnaCandidato();
                char vSexoCandidato = it2->getSexoCandidato();
                Date vDataNascimentoCandidato = it2->getDataNascimentoCandidato();
                string vDestinoVoto = it2->getDestinoVoto();
                int vNumeroPartidoCandidato = it2->getNumeroPartidoCandidato();

                // Inicializa um candidato auxiliar
                Candidato pessoa = Candidato(vNumeroCandidato, vVotosNominaisCandidato, vSituacaoCandidato, vNomeCandidato, vNomeUrnaCandidato, vSexoCandidato, vDataNascimentoCandidato, vDestinoVoto, vNumeroPartidoCandidato);
                candidatosVotos.push_back(pessoa); // Adiciona na lista de candidatos

                if(it2->getSituacaoCandidato().compare(comparaSituacao) == 0){ // Verifica se o candidato é eleito
                    candidatosEleitos.push_back(pessoa); // Adiciona o candidato à lista de candidatos eleitos
                    qtdVagas++; // Incremeta o número de vagas

                    // Adiciona na lista de info uma grande string
                    infoCandidatoEleito.push_back(it2->getNomeCandidato() + " / " + it2->getNomeUrnaCandidato() + " (" + it->getSiglaPartido() + ", " + library.intToChar(it2->getVotosNominaisCandidato()) + " votos)");
                    
                    if(it2->getSexoCandidato() == comparaSexoF){ // Verifica se é mulher
                        qtdMulheresEleitas++; // Incrementa a quantidade de mulheres
                    } else if(it2->getSexoCandidato() == comparaSexoM){ // Verifica se é homem
                        qtdHomensEleitos++; // Incrementa a quantidade de homens
                    } 

                } else{
                    totalVotosNominais += it2->getVotosNominaisCandidato();	// Incrementa a quantidade de votos nominais
                }
            }
        }

        // Ordena a lista de eleitos pelos votos
        candidatosEleitos.sort(compare);

        int aux2 = qtdVagas; 

        // Impressão do output 
        cout << "Número de vagas: " << qtdVagas << endl;
        cout << endl;
        cout << "Vereadores eleitos:" << endl;

        while(cont < aux2){ // Enquanto for menor ou igual à quantidade de eleitos
            for(it2 = candidatosEleitos.begin(); it2 != candidatosEleitos.end(); ++it2){
                
                // Altera a quantidade de vagas
                if(qtdVagas != aux && cont == 0){ 
                    qtdVagas--; 
                } else if(qtdVagas != aux && cont > 0){
                    qtdVagas++;
                }

                // Se for igual
                if(qtdVagas == aux){
                    int idade = it2->getDataNascimentoCandidato().idade(dataeleicao); // Calcula a idade

                    if(idade < 30){ // Se for menor que 30
                        idadeAbaixoTrinta++;
                    } else if(idade < 40){ // Se for menor que 40
                        idadeAbaixoQuarenta++;
                    } else if(idade < 50){ // Se for menor que 50
                        idadeAbaixoCinquenta++;
                    } else if(idade < 60){ // Se for menor que 60
                        idadeAbaixoSessenta++;
                    }else{
                        idadeAcimaSessenta++;
                    }
                    
                    // Adiciona o valor em um partido
                    Partido p = vereadores.retornaPartidoPeloNum(it2->getNumeroPartidoCandidato());

                    // Impressão do output 
                    cout << posicaoCandidato << " - " << it2->getNomeCandidato() << " / " << it2->getNomeUrnaCandidato() << " (" << p.getSiglaPartido() << ", " << it2->getVotosNominaisCandidato() << " votos)" << endl;   

                    aux = aux2 - 1;
                    cont++;						
                    qtdVagas = 0;
                    posicaoCandidato++;

                    if(cont == aux2){ // Compara os contadores
                        break; // Sai do loop
                    }
                }
            }
        }

        // Reset de variáveis auxiliares
        qtdVagas = aux2; 
        cont = 0;
        aux = 0;
        posicaoCandidato = 1;
        aux2 = totalCandidatos;

        // Ordena a lista de eleitos pelos votos
        candidatosVotos.sort(compare);

        // Impressão do output 
        cout << endl;
        cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;
        
        comparaSituacao = "Eleito";

        while(cont < qtdVagas){ // Enquanto o contador for menor que o número de eleitos
            for(it2 = candidatosVotos.begin(); it2 != candidatosVotos.end(); ++it2){
                // Altera os contadores
                if(totalCandidatos != aux && cont == 0){ 
                    totalCandidatos--; 
                } else if(totalCandidatos != aux && cont > 0){
                    totalCandidatos++;
                }

                if(totalCandidatos == aux){ // Se for igual ao contador
                    candidatosMaisVotados.push_back(*it2); // Adiciona à lista de mais votados

                    if(it2->getSituacaoCandidato().compare(comparaSituacao) != 0){ // Se não for Eleito
                        candidatosEleitosMajoritariamente.push_back(*it2); // Adiciona na lista de majoritários
                        posicaoRanking.push_back(posicaoCandidato); // Adiciona a lista de posições
                    }

                    // Retorna o partido pelo index
                    Partido p = vereadores.retornaPartidoPeloNum(it2->getNumeroPartidoCandidato()); 

                    // Impressão do output 
                    cout << posicaoCandidato << " - " << it2->getNomeCandidato() << " / " << it2->getNomeUrnaCandidato() << " (" << p.getSiglaPartido() << ", " << it2->getVotosNominaisCandidato() << " votos)" << endl; 
                    
                    // Reset de variáveis auxiliares
                    aux += aux2; 
                    totalCandidatos+=1; 
                    cont++;
                    posicaoCandidato++;

                    if(cont == qtdVagas){ // If para sair do loop se der o número
                        break;
                    }
                }
            }
        }

        posicaoCandidato = 0;

        // Impressão do output
        cout << endl;
        cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
        cout << "(com sua posição no ranking de mais votados)" << endl;

        for(it2 = candidatosEleitosMajoritariamente.begin(); it2 != candidatosEleitosMajoritariamente.end(); ++it2){
            Partido p = vereadores.retornaPartidoPeloNum(it2->getNumeroPartidoCandidato()); 

            // Impressão do output
            cout << posicaoRanking[posicaoCandidato] << " - " << it2->getNomeCandidato() << " / " << it2->getNomeUrnaCandidato() << " (" << p.getSiglaPartido() << ", " << it2->getVotosNominaisCandidato() << " votos)" << endl;
            posicaoCandidato++;
        }

        for(it2 = candidatosMaisVotados.begin(); it2 != candidatosMaisVotados.end(); ++it2){
            if(it2->getVotosNominaisCandidato() < eleitoMenosVotos){
                eleitoMenosVotos = it2->getVotosNominaisCandidato(); // Procura o com menos votos
            }
        }

        int naoEleitoMenosVotos = 2147483647;

        for(it2 = candidatosEleitosMajoritariamente.begin(); it2 != candidatosEleitosMajoritariamente.end(); ++it2){
            if(it2->getVotosNominaisCandidato() < naoEleitoMenosVotos && !it2->getSituacaoCandidato().compare("Eleito")){
                naoEleitoMenosVotos = it2->getVotosNominaisCandidato(); // Procura o com menos votos não eleito
            }
        }
        
        // Reset de variáveis auxiliares
        totalCandidatos = aux2;
        aux = 0;
        cont = 0;

        while(cont < aux2){ // Enquanto for dentro do número de candidatos
            for(it2 = candidatosVotos.begin(); it2 != candidatosVotos.end(); ++it2){

                if(totalCandidatos != aux && cont == 0){
                    totalCandidatos--; // Decrementa pra manter o loop
                }else if(totalCandidatos != aux && cont > 0){
                    totalCandidatos++;
                }

                if(totalCandidatos == aux){  // Se for igual
                    // Insere na lista de cantidatos mais votados
                    candidatosMaisVotados.insert(candidatosMaisVotados.end(), *it2); 
                    cont++; // Incrementa o contador
                    aux = aux2 - cont; 
                    totalCandidatos = 0;

                    if(cont <= aux2){
                        break; // Sai do loop
                    }
                }
            }
        }

        // Reset de variáveis auxiliares
        cont = 0; 
        aux = totalCandidatos;

        for(it2 = candidatosVotos.begin(); it2 != candidatosVotos.end(); ++it2){
            cont = aux; // Iguala os contadores
            aux--;
        }


        // Reset de variáveis auxiliares
        cont= -qtdVagas;
        aux  = 0;
        comparaSituacao = "Eleito";

        // Impressão do output 
        cout << endl;
        cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
        cout << "(com sua posição no ranking de mais votados)" << endl;
        
        int numCandidatosMenosVotos = 0;

        for(it2 = candidatosEleitos.begin(); it2 != candidatosEleitos.end(); ++it2){
            if(it2->getVotosNominaisCandidato() < naoEleitoMenosVotos){
                numCandidatosMenosVotos++; // Incrementa o número de candidatos
            }
        }

        // Reset de variáveis auxiliares
        int counterEleitos = 0;
        int counter;
        int notFound;

        // Inverte a lista
        candidatosEleitos.reverse();
        
        for(it2 = candidatosEleitos.begin(); it2 != candidatosEleitos.end(); ++it2){
            counter = 0; // Contador inicializado
            for(it3 = candidatosMaisVotados.begin(); it3 != candidatosMaisVotados.end(); ++it3){

                if(it3->compareCandidato(*it2) == 0){ // Se o candidato ão estiver na lista de eleitos
                    notFound++;
                }

                counter++;
                if(counter == qtdVagas){ // Sai do loop
                    break;
                }
            }

            if(notFound == 0){ // Se o contador for 0, ele é majoritário
                Partido p = vereadores.retornaPartidoPeloNum(it2->getNumeroPartidoCandidato());

                // Impressão do output 
                cout << library.returnPosicao(candidatosMaisVotados, it2->getNomeCandidato()) - (qtdVagas - 1) << " - " << it2->getNomeCandidato() << " / " << it2->getNomeUrnaCandidato() << " (" << p.getSiglaPartido() << ", " << it2->getVotosNominaisCandidato() << " votos)" << endl;
                posicaoCandidato++;
            }

            // Reset de variáveis
            notFound = 0;
            counterEleitos++;

            if(counterEleitos == qtdVagas){ // Sai do loop
                break;
            }
        }

        // Impressão do output 
        cout << endl;
        cout << "Votação dos partidos e número de candidatos eleitos:" << endl;

        // Reset de variáveis
        for(it = listaPartidos.begin(); it != listaPartidos.end(); ++it){
            totalVotosNominaisPartido = it->countVotosNominais();
            totalVotosPartido = totalVotosNominaisPartido + it->getVotosLegendaPartido();
            it->setVotosNominaisTotaisPartido(totalVotosNominaisPartido);
            it->setVotosTotaisPartido(totalVotosPartido);
        }
        
        // Ordenação dos partidos pelo voto total 
        listaPartidos.sort(comparePartido);

        cont = 1;

        for(it = listaPartidos.begin(); it != listaPartidos.end(); ++it){
            qtdEleitosPartido = it->countEleitos(); // Seta a quantidade de eleitos
            // Impressão do output 
            cout << cont << " - " <<it->getSiglaPartido() << " - " << it->getNumeroPartido() << ", " << it->getVotosTotaisPartido() << " voto" << (it->getVotosTotaisPartido() > 1 ? "s" : "") <<  " (" << it->getVotosNominaisTotaisPartido() << (it->getVotosNominaisTotaisPartido() > 1 ? " nominais" : " nominal") << " e " << it->getVotosLegendaPartido() << " de legenda), " << qtdEleitosPartido << " candidato" << (qtdEleitosPartido > 1 ? "s": "") << " eleito" << (qtdEleitosPartido > 1 ? "s": "") << endl; 
            cont++; // Incrementa o contador
        }

        cont = 1;

        // Impressão do output 
        cout << endl;
        cout << "Primeiro e último colocados de cada partido:" << endl;

        list<Candidato> auxPrintPartido; // Lista de Candidato auxiliar

        // Ordenação dos partidos pelo voto nominal
        listaPartidos.sort(compareVotosPartido);

        // Seta string para mudança quantitativa do termo
        string singular = " voto)";
        string plural = " votos)";

        for(it = listaPartidos.begin(); it != listaPartidos.end(); ++it){
            auxPrintPartido = it->getCandidatoPartido(); // Pega a lista de candidatos do partido
            auxPrintPartido.sort(compare); // Ordena pelos votos nominais
            auxPrintPartido.reverse(); // Inverte a lista

            // Variaveis para controle do primeiro e do último
            Candidato primeiro = *auxPrintPartido.begin();
            Candidato ultimo = *auxPrintPartido.begin();

            for(it2 = auxPrintPartido.begin(); it2 != auxPrintPartido.end(); ++it2){
                if(it->validaSituacao(*it2) == 0){ // Verifica a validação
                    primeiro = *it2; // Sai do loop
                    break;
                }
            }

            string actual;

            if(primeiro.getVotosNominaisCandidato() <= 1){ // Se for 1 ou 0 é no singular
                actual = singular;
            } else{ // Caso contrário é plural
                actual = plural;
            }
            
            // Impressão do output 
            cout << cont << " - " << it->getSiglaPartido() << " - " << it->getNumeroPartido() << ", " << primeiro.getNomeUrnaCandidato();
            cout << " (" << primeiro.getNumeroCandidato() << ", " << primeiro.getVotosNominaisCandidato() << actual << " / "; 

            // Inverte a lista 
            auxPrintPartido.reverse();

            for(it2 = auxPrintPartido.begin(); it2 != auxPrintPartido.end(); ++it2){
                if(it->validaSituacao(*it2) == 0){ // Verifica a validação
                    ultimo = *it2; // Sai do loop
                    break;
                }
            }

            if(ultimo.getVotosNominaisCandidato() <= 1){ // Se for 1 ou 0 é no singular
                actual = singular;
            } else{ // Caso contrário é plural
                actual = plural;
            }
            
            // Impressão do output 
            cout << ultimo.getNomeUrnaCandidato() << " (" << ultimo.getNumeroCandidato() << ", " << ultimo.getVotosNominaisCandidato() << actual << endl;             // id - sigla - npartido, nomeM (ncandidato, x votos) / nomem (ncandidato, x votos)
            auxPrintPartido.clear();

            cont++;
        }

        // Seta pra UTF-8
        cout.imbue(locale("pt_BR.UTF-8"));

        // Impressão do output 
        cout << endl;
        cout << "Eleitos, por faixa etária (na data da eleição):" << endl;

        // Impressão do output 
        cout << "      Idade < 30: " << to_string(idadeAbaixoTrinta) << " (" << fixed <<  setprecision(2) <<((idadeAbaixoTrinta/(double)qtdVagas)*100) << "%)" << endl;
        cout << "30 <= Idade < 40: " << to_string(idadeAbaixoQuarenta) << " (" << fixed <<  setprecision(2) <<((idadeAbaixoQuarenta/(double)qtdVagas)*100) << "%)" << endl;
        cout << "40 <= Idade < 50: " << to_string(idadeAbaixoCinquenta) << " (" << fixed <<  setprecision(2) <<((idadeAbaixoCinquenta/(double)qtdVagas)*100) << "%)" << endl;
        cout << "50 <= Idade < 60: " << to_string(idadeAbaixoSessenta) << " (" << fixed <<  setprecision(2) <<((idadeAbaixoSessenta/(double)qtdVagas)*100) << "%)" << endl;
        cout << "60 <= Idade     : " << to_string(idadeAcimaSessenta) << " (" << fixed <<  setprecision(2) <<((idadeAcimaSessenta/(double)qtdVagas)*100) << "%)" << endl;

        // Impressão do output 
        cout << endl;
        
        // Calculo da porcentagem de eleitos por sexo
        porcentagemEleitasF = (qtdMulheresEleitas/(double)qtdVagas)*100;
        porcentagemEleitosM = (qtdHomensEleitos/(double)qtdVagas)*100; 

        // Impressão do output 
        cout << "Eleitos, por sexo:" << endl; 
        cout << "Feminino:  " << to_string(qtdMulheresEleitas) << " (" << fixed <<  setprecision(2) << porcentagemEleitasF << "%)" << endl;
        cout << "Masculino: " << to_string(qtdHomensEleitos) << " (" << fixed <<  setprecision(2) << porcentagemEleitosM << "%)" << endl;
        cout << endl;

        // Conta total de votos nominais 
        totalVotosNominais = vereadores.contaVotosValidos(candidatosEleitos);

        // Calcula total de votos
        totalVotos = totalVotosLegenda + totalVotosNominais; 

        // Impressão do output 
        cout << "Total de votos válidos:    " << to_string(totalVotos) << endl; 

        // Calculo da porcentagem de votos nominais e legenda
        porcentagemVnominais = (totalVotosNominais/(double)totalVotos)*100; 
        porcentagemVlegenda = (totalVotosLegenda/(double)totalVotos)*100; 

        // Impressão do output 
        cout << "Total de votos nominais:   " << to_string(totalVotosNominais) << " (" << fixed << setprecision(2) << porcentagemVnominais << "%)" << endl; 
        cout << "Total de votos de Legenda: " << to_string(totalVotosLegenda) << " (" << fixed << setprecision(2) << porcentagemVlegenda << "%)\n" << endl; 

    } catch (invalid_argument& e){
        cerr << e.what() << endl;
        return false;
    }

    return true;
}   
