#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <algorithm>
#include <iomanip> 
#include <list>

#include "Escrita.hpp"
#include "Lib.hpp"

using namespace std;

Escrita::Escrita(){
}

Escrita::~Escrita(){
	// TODO Auto-generated destructor stub
}

bool compare(Candidato first, Candidato second){
    if(first.getVotosNominaisCandidato() > second.getVotosNominaisCandidato()){
        return false;
    }
	if (first.getVotosNominaisCandidato() == second.getVotosNominaisCandidato()){
		return first.getDataNascimentoCandidato().compareTo(second.getDataNascimentoCandidato());
	} 

	return true;	
}

bool compare2(Candidato first, Candidato second){
    if(first.getVotosNominaisCandidato() == second.getVotosNominaisCandidato()){
        if(first.getNumeroPartidoCandidato() > second.getNumeroPartidoCandidato()){
            return false;
        }
    }
    if(first.getVotosNominaisCandidato() > second.getVotosNominaisCandidato()){
        return false;	
    }

    return true;
}

bool comparePartido(Partido first, Partido second){
    return first.getVotosTotaisPartido() > second.getVotosTotaisPartido();
}

bool Escrita::escreveArquivo(string path, Date dataeleicao, Eleicao vereadores){
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

        Lib library = Lib();

        list< Partido, allocator<Partido> > :: iterator it;
        list< Candidato, allocator<Candidato> > :: iterator it2;
        list< Candidato, allocator<Candidato> > :: iterator it3;

        for(it = listaPartidos.begin(); it != listaPartidos.end(); ++it){
            qtdPartidos++;
            totalVotosLegenda = totalVotosLegenda + it->getVotosLegendaPartido(); 
            list<Candidato> c = it->getCandidatoPartido();
            for(it2 = c.begin(); it2 != c.end(); ++it2){
                totalCandidatos++;
                int vNumeroCandidato = it2->getNumeroCandidato();
                int vVotosNominaisCandidato = it2->getVotosNominaisCandidato();
                string vSituacaoCandidato = it2->getSituacaoCandidato();
                string vNomeCandidato = it2->getNomeCandidato();
                string vNomeUrnaCandidato = it2->getNomeUrnaCandidato();
                char vSexoCandidato = it2->getSexoCandidato();
                Date vDataNascimentoCandidato = it2->getDataNascimentoCandidato();
                string vDestinoVoto = it2->getDestinoVoto();
                int vNumeroPartidoCandidato = it2->getNumeroPartidoCandidato();

                Candidato pessoa = Candidato(vNumeroCandidato, vVotosNominaisCandidato, vSituacaoCandidato, vNomeCandidato, vNomeUrnaCandidato, vSexoCandidato, vDataNascimentoCandidato, vDestinoVoto, vNumeroPartidoCandidato);
                candidatosVotos.push_back(pessoa); 

                if(it2->getSituacaoCandidato().compare(comparaSituacao) == 0){
                    candidatosEleitos.push_back(pessoa);
                    qtdVagas++; 
                    infoCandidatoEleito.push_back(it2->getNomeCandidato() + " / " + it2->getNomeUrnaCandidato() + " (" + it->getSiglaPartido() + ", " + library.intToChar(it2->getVotosNominaisCandidato()) + " votos)");
                    
                    if(it2->getSexoCandidato() == comparaSexoF){
                        qtdMulheresEleitas++; 
                    } else if(it2->getSexoCandidato() == comparaSexoM){
                        qtdHomensEleitos++;
                    }   
                } else{
                    totalVotosNominais += it2->getVotosNominaisCandidato();	
                }
            }
        }

        candidatosEleitos.sort(compare);

        int aux2 = qtdVagas; 
        ofstream myfile (path); // ifstream = padrão ios:in
        int bit = 0;

        if (myfile.is_open()){
            //escrita da quantidade de vagas; 
            myfile << "Número de vagas: " << qtdVagas << endl;
            myfile << endl;
            myfile << "Vereadores eleitos:" << endl;

            while(cont < aux2){
				for(it2 = candidatosEleitos.begin(); it2 != candidatosEleitos.end(); ++it2){
                    Candidato c = *it2;

					if(qtdVagas != aux && cont == 0){
					    qtdVagas--; 
					} else if(qtdVagas != aux && cont > 0){
						qtdVagas++;
					}

					if(qtdVagas == aux){
                        int idade = c.getDataNascimentoCandidato().idade(dataeleicao);

						if(idade < 30){
							idadeAbaixoTrinta++;
						} else if(idade < 40){
							idadeAbaixoQuarenta++;
						} else if(idade < 50){
							idadeAbaixoCinquenta++;
						} else if(idade < 60){
							idadeAbaixoSessenta++;
						}else{
							idadeAcimaSessenta++;
						}
						
						Partido p = vereadores.retornaPartidoPeloNum(c.getNumeroPartidoCandidato());

						myfile << posicaoCandidato << " - " << c.getNomeCandidato() << " / " << c.getNomeUrnaCandidato() << " (" << p.getSiglaPartido() << ", " << c.getVotosNominaisCandidato() << " votos)" << endl;   

                        aux = aux2 - 1;
						cont++;						
						qtdVagas = 0;
						posicaoCandidato++;

						if(cont == aux2){
							break;
						}
					}
				}
            }

            qtdVagas = aux2; 
            cont = 0;
            aux = 0;
            posicaoCandidato = 1;
			aux2 = totalCandidatos;

            candidatosVotos.sort(compare);

            myfile << endl;
            myfile << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;
			
			comparaSituacao = "Eleito";

            while(cont < qtdVagas){
                for(it2 = candidatosVotos.begin(); it2 != candidatosVotos.end(); ++it2){
                    if(totalCandidatos != aux && cont == 0){
                        totalCandidatos--; 
                    } else if(totalCandidatos != aux && cont > 0){
                        totalCandidatos++;
                    }
                    if(totalCandidatos == aux){ 
                        candidatosMaisVotados.push_back(*it2); 

                        if(it2->getSituacaoCandidato().compare(comparaSituacao) != 0){
                            candidatosEleitosMajoritariamente.push_back(*it2);
                            posicaoRanking.push_back(posicaoCandidato);
                        }

                        Partido p = vereadores.retornaPartidoPeloNum(it2->getNumeroPartidoCandidato()); 

                        myfile << posicaoCandidato << " - " << it2->getNomeCandidato() << " / " << it2->getNomeUrnaCandidato() << " (" << p.getSiglaPartido() << ", " << it2->getVotosNominaisCandidato() << " votos)" << endl; 
                        
                        aux += aux2; 
                        totalCandidatos+=1; 
                        cont++;
                        posicaoCandidato++;

                        if(cont == qtdVagas){
                            break;
                        }
                    }
                }
			}

            posicaoCandidato = 0;

			myfile << endl;
			myfile << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
			myfile << "(com sua posição no ranking de mais votados)" << endl;

            for(it2 = candidatosEleitosMajoritariamente.begin(); it2 != candidatosEleitosMajoritariamente.end(); ++it2){
				Partido p = vereadores.retornaPartidoPeloNum(it2->getNumeroPartidoCandidato());

                myfile << posicaoRanking[posicaoCandidato] << " - " << it2->getNomeCandidato() << " / " << it2->getNomeUrnaCandidato() << " (" << p.getSiglaPartido() << ", " << it2->getVotosNominaisCandidato() << " votos)" << endl;
                posicaoCandidato++;
			}

            for(it2 = candidatosMaisVotados.begin(); it2 != candidatosMaisVotados.end(); ++it2){
				if(it2->getVotosNominaisCandidato() < eleitoMenosVotos){
					eleitoMenosVotos = it2->getVotosNominaisCandidato();
				}
			}

            int naoEleitoMenosVotos = 2147483647;

            for(it2 = candidatosEleitosMajoritariamente.begin(); it2 != candidatosEleitosMajoritariamente.end(); ++it2){
				if(it2->getVotosNominaisCandidato() < naoEleitoMenosVotos && !it2->getSituacaoCandidato().compare("Eleito")){
					naoEleitoMenosVotos = it2->getVotosNominaisCandidato();
				}
			}
			
			totalCandidatos = aux2;
			aux = 0;
            cont = 0;

            while(cont < aux2){
                for(it2 = candidatosVotos.begin(); it2 != candidatosVotos.end(); ++it2){
                    Candidato c = *it2;
					if(totalCandidatos != aux && cont == 0){
					totalCandidatos--; 
					}else if(totalCandidatos != aux && cont > 0){
						totalCandidatos++;
					}
					if(totalCandidatos == aux){ 
						candidatosMaisVotados.insert(candidatosMaisVotados.end(), c); 
						cont++;
						aux = aux2-cont; 
						totalCandidatos = 0;

						if(cont <= aux2){
							break;
						}
					}
				}
            }

            cont = 0; 
            aux = totalCandidatos;

            for(it2 = candidatosVotos.begin(); it2 != candidatosVotos.end(); ++it2){
                Candidato c = *it2;
                cont=aux; 
                aux--;
            }

            cont= -qtdVagas;
			aux  = 0;
			comparaSituacao = "Eleito";

			myfile << endl;
			myfile << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
			myfile << "(com sua posição no ranking de mais votados)" << endl;
			
			int numCandidatosMenosVotos = 0;
            for(it2 = candidatosEleitos.begin(); it2 != candidatosEleitos.end(); ++it2){
				if(it2->getVotosNominaisCandidato() < naoEleitoMenosVotos){
					numCandidatosMenosVotos++;
				}
			}

            int counterEleitos = 0;
            int counter;
            int notFound;

            candidatosEleitos.reverse();
            
            for(it2 = candidatosEleitos.begin(); it2 != candidatosEleitos.end(); ++it2){
                counter = 0;
                for(it3 = candidatosMaisVotados.begin(); it3 != candidatosMaisVotados.end(); ++it3){

                    if(it3->compare_candidato(*it2) == 0){
                        notFound++;
                    }

                    counter++;
                    if(counter == qtdVagas){
                        break;
                    }
                }

                if(notFound == 0){
                    Partido p = vereadores.retornaPartidoPeloNum(it2->getNumeroPartidoCandidato());
                    myfile << library.returnPosicao(candidatosMaisVotados, it2->getNomeCandidato()) + 1 << " - " << it2->getNomeCandidato() << " / " << it2->getNomeUrnaCandidato() << " (" << p.getSiglaPartido() << ", " << it2->getVotosNominaisCandidato() << " votos)" << endl;
                    posicaoCandidato++;
                }

                notFound = 0;
                counterEleitos++;
                if(counterEleitos == qtdVagas){
                    break;
                }
            }

			myfile << endl;
			myfile << "Votação dos partidos e número de candidatos eleitos:" << endl;

            for(it = listaPartidos.begin(); it != listaPartidos.end(); ++it){
				totalVotosNominaisPartido = it->countVotosNominais();
				totalVotosPartido = totalVotosNominaisPartido + it->getVotosLegendaPartido();
				it->setVotosNominaisTotaisPartido(totalVotosNominaisPartido);
				it->setVotosTotaisPartido(totalVotosPartido);
			}
			
			listaPartidos.sort(comparePartido);

            cont = 1;

            for(it = listaPartidos.begin(); it != listaPartidos.end(); ++it){
                qtdEleitosPartido = it->countEleitos();
                myfile << cont << " - " <<it->getSiglaPartido() << " - " << it->getNumeroPartido() << ", " << it->getVotosTotaisPartido() << " voto" << (it->getVotosTotaisPartido() > 1 ? "s" : "") <<  " (" << it->getVotosNominaisTotaisPartido() << (it->getVotosNominaisTotaisPartido() > 1 ? " nominais" : " nominal") << " e " << it->getVotosLegendaPartido() << " de legenda), " << qtdEleitosPartido << " candidato" << (qtdEleitosPartido > 1 ? "s": "") << " eleito" << (qtdEleitosPartido > 1 ? "s": "") << endl; 
                cont++;
            }

            cont = 1;

			myfile << endl;
			myfile << "Primeiro e último colocados de cada partido:" << endl;

            list<Candidato> auxPrintPartido;

            for(it = listaPartidos.begin(); it != listaPartidos.end(); ++it){
                auxPrintPartido = it->getCandidatoPartido();
                auxPrintPartido.sort(compare);
                auxPrintPartido.reverse();
                Candidato primeiro = *auxPrintPartido.begin();
                
                myfile << cont << " - " << it->getSiglaPartido() << " - " << it->getNumeroPartido() << ", " << primeiro.getNomeUrnaCandidato();
                myfile << " (" << primeiro.getNumeroCandidato() << ", " << primeiro.getVotosNominaisCandidato() << " votos) / "; 

                auxPrintPartido.reverse();
                
                Candidato ultimo = *auxPrintPartido.begin();

                myfile << ultimo.getNomeUrnaCandidato() << " (" << ultimo.getNumeroCandidato() << ", " << ultimo.getVotosNominaisCandidato() << " votos)" << endl;             // id - sigla - npartido, nomeM (ncandidato, x votos) / nomem (ncandidato, x votos)
                auxPrintPartido.clear();

                cont++;
            }

            myfile << endl;
			myfile << "Eleitos, por faixa etária (na data da eleição):" << endl;

            myfile << "      Idade < 30: " << idadeAbaixoTrinta << " (" << fixed <<  setprecision(2) <<((idadeAbaixoTrinta/(double)qtdVagas)*100) << "%)" << endl;
			myfile << "30 <= Idade < 40: " << idadeAbaixoQuarenta << " (" << fixed <<  setprecision(2) <<((idadeAbaixoQuarenta/(double)qtdVagas)*100) << "%)" << endl;
			myfile << "40 <= Idade < 50: " << idadeAbaixoCinquenta << " (" << fixed <<  setprecision(2) <<((idadeAbaixoCinquenta/(double)qtdVagas)*100) << "%)" << endl;
			myfile << "50 <= Idade < 60: " << idadeAbaixoSessenta << " (" << fixed <<  setprecision(2) <<((idadeAbaixoSessenta/(double)qtdVagas)*100) << "%)" << endl;
			myfile << "60 <= Idade     : " << idadeAcimaSessenta << " (" << fixed <<  setprecision(2) <<((idadeAcimaSessenta/(double)qtdVagas)*100) << "%)" << endl;

			myfile << endl;
			
			
			porcentagemEleitasF = (qtdMulheresEleitas/(double)qtdVagas)*100;
			porcentagemEleitosM = (qtdHomensEleitos/(double)qtdVagas)*100; 

			myfile << "Eleitos, por sexo:" << endl; 
			myfile << "Feminino:  " << qtdMulheresEleitas << " (" << fixed <<  setprecision(2) << porcentagemEleitasF << "%)" << endl;
			myfile << "Masculino: " << qtdHomensEleitos << " (" << fixed <<  setprecision(2) << porcentagemEleitosM << "%)" << endl;
			myfile << endl;

			totalVotos = totalVotosLegenda + totalVotosNominais; 

			myfile << "Total de votos válidos:    " << totalVotos << endl; 

			porcentagemVnominais = (totalVotosNominais/(double)totalVotos)*100; 
			porcentagemVlegenda = (totalVotosLegenda/(double)totalVotos)*100; 

			myfile << "Total de votos nominais:   " << totalVotosNominais << " (" << fixed << setprecision(2) << porcentagemVnominais << "%)" << endl; 
			myfile << "Total de votos de Legenda: " << totalVotosLegenda << " (" << fixed << setprecision(2) << porcentagemVlegenda << "%)\n" << endl; 

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
