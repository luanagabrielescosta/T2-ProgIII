#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <algorithm>
#include <iomanip> 
#include <list>
#include "escrita.hpp"
#include "lib.hpp"
#include "votosComparator.hpp"

using namespace std;

escrita::escrita(){
}

bool escrita::escreveArquivo(string path, date dataeleicao, eleicao vereadores){
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

        lib library = lib();
        votosComparator comparator = votosComparator();

        list<partido> :: iterator it;
        list<candidato> :: iterator it2;

        for(it = listaPartidos.begin(); it != listaPartidos.end(); ++it){
            qtdPartidos++;
            partido p = *it;
            totalVotosLegenda = totalVotosLegenda + p.getVotosLegendaPartido(); 


            for(it2 = p.getcandidatoPartido().begin(); it2 != p.getcandidatoPartido().end(); ++it2){
                totalCandidatos++;
                candidato c = *it2;
                int vNumeroCandidato = c.getNumeroCandidato();
                int vVotosNominaisCandidato = c.getVotosNominaisCandidato();
                string vSituacaoCandidato = c.getSituacaoCandidato();
                string vNomeCandidato = c.getNomeCandidato();
                string vNomeUrnaCandidato = c.getNomeUrnaCandidato();
                char vSexoCandidato = c.getSexoCandidato();
                date vDataNascimentoCandidato = c.getDataNascimentoCandidato();
                string vDestinoVoto = c.getDestinoVoto();
                int vNumeroPartidoCandidato = c.getNumeroPartidoCandidato();

                candidato pessoa = candidato(vNumeroCandidato, vVotosNominaisCandidato, vSituacaoCandidato, vNomeCandidato, vNomeUrnaCandidato, vSexoCandidato, vDataNascimentoCandidato, vDestinoVoto, vNumeroPartidoCandidato);
                // candidato pessoa = candidato(c.getNumeroCandidato(), c.getVotosNominaisCandidato(), c.getSituacaoCandidato(), c.getNomeCandidato(), c.getNomeUrnaCandidato(), c.getSexoCandidato(), c.getDataNascimentoCandidato(), c.getDestinoVoto(), c.getNumeroPartidoCandidato());
                candidatosVotos.insert(candidatosVotos.end(), pessoa); 

                if(c.getSituacaoCandidato().compare(comparaSituacao)){
                    candidatosEleitos.insert(candidatosEleitos.end(), pessoa);
                    qtdVagas++; 
                    infoCandidatoEleito.insert(infoCandidatoEleito.end(), c.getNomeCandidato() + " / " + c.getNomeUrnaCandidato() + " (" + p.getSiglaPartido() + ", " + library.int_to_char(c.getVotosNominaisCandidato()) + " votos)");
                    
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

        // PERGUNTAR
        candidatosEleitos.sort(comparator.compare);
        // Collections.sort(candidatosEleitos, new votosComparator());

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
                    candidato c = *it2;

					if(qtdVagas != aux && cont == 0){
					    qtdVagas--; 
					} else if(qtdVagas != aux && cont > 0){
						qtdVagas++;
					}

					if(qtdVagas == aux){
						
						// Calendar dataNascimento = Calendar.getInstance();
						// dataNascimento.setTime(c.getDataNascimentoCandidato());
						// Calendar dataeleicaoAux = Calendar.getInstance();
						// dataeleicaoAux.setTime(dataeleicao);

                        int idade = c.getDataNascimentoCandidato().idade(dataeleicao);

						// Integer diferencaMes = dataeleicaoAux.get(Calendar.MONTH) - dataNascimento.get(Calendar.MONTH);
						// Integer diferencaDia = dataeleicaoAux.get(Calendar.DAY_OF_MONTH) - dataNascimento.get(Calendar.DAY_OF_MONTH);
						// Integer idade = (dataeleicaoAux.get(Calendar.YEAR) - dataNascimento.get(Calendar.YEAR));
                        // if(c.getDataNascimentoCandidato().return_month() != dataeleicao.return_month()){
						// // if(diferencaMes < 0 || (diferencaMes == 0 && diferencaDia < 0)){
						// 	idade--;
						// } else if(c.getDataNascimentoCandidato().return_day() != dataeleicao.return_day()){
                        //     idade--;
                        // }
						
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
						
						partido p = vereadores.retornaPartidoPeloNum(c.getNumeroPartidoCandidato());

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

            candidatosVotos.sort(comparator.compare());
            // Collections.sort(candidatosVotos, new votosComparator());
			candidatosVotos.reverse();
			// Collections.sort(candidatosVotos,Collections.reverseOrder());

            myfile << endl;
            myfile << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;
			
			comparaSituacao = "Eleito";

            while(cont < qtdVagas){
                for(it2 = candidatosVotos.begin(); it2 != candidatosVotos.end(); ++it2){
                    candidato c = *it2;

                    if(totalCandidatos != aux && cont == 0){
                        totalCandidatos--; 
                    } else if(totalCandidatos != aux && cont > 0){
                        totalCandidatos++;
                    }
                    if(totalCandidatos == aux){ 
                        candidatosMaisVotados.insert(candidatosMaisVotados.end(), c); 

                        if(!c.getSituacaoCandidato().compare(comparaSituacao)){
                            candidatosEleitosMajoritariamente.insert(candidatosEleitosMajoritariamente.end(), c);
                            posicaoRanking.insert(posicaoRanking.end(), posicaoCandidato);
                        }

                        partido p = vereadores.retornaPartidoPeloNum(c.getNumeroPartidoCandidato()); 

                        myfile << posicaoCandidato << " - " << c.getNomeCandidato() << " / " << c.getNomeUrnaCandidato() << " (" << p.getSiglaPartido() << ", " << c.getVotosNominaisCandidato() << " votos)" << endl; 
                        
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
                candidato c = *it2;
				partido p = vereadores.retornaPartidoPeloNum(c.getNumeroPartidoCandidato());

                myfile << library.return_int(posicaoRanking, posicaoCandidato) << " - " << c.getNomeCandidato() << " / " << c.getNomeUrnaCandidato() << " (" << p.getSiglaPartido() << ", " << c.getVotosNominaisCandidato() << " votos)" << endl;
                // myfile << posicaoRanking.get(posicaoCandidato) + " - " + c.getNomeCandidato() + " / " + c.getNomeUrnaCandidato() + " (" + p.getSiglaPartido() + ", " + c.getVotosNominaisCandidato() + " votos)");
                posicaoCandidato++;
			}

            for(it2 = candidatosMaisVotados.begin(); it2 != candidatosMaisVotados.end(); ++it2){
                candidato c = *it2;
				if(c.getVotosNominaisCandidato() < eleitoMenosVotos){
					eleitoMenosVotos = c.getVotosNominaisCandidato();
				}
			}

            int naoEleitoMenosVotos = 2147483647;

            for(it2 = candidatosEleitosMajoritariamente.begin(); it2 != candidatosEleitosMajoritariamente.end(); ++it2){
                candidato c = *it2;

				if(c.getVotosNominaisCandidato() < naoEleitoMenosVotos && !c.getSituacaoCandidato().compare("Eleito")){
					naoEleitoMenosVotos = c.getVotosNominaisCandidato();
				}
			}
			
			totalCandidatos = aux2;
			aux = 0;
            cont = 0;

            while(cont < aux2){
                for(it2 = candidatosVotos.begin(); it2 != candidatosVotos.end(); ++it2){
                    candidato c = *it2;
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
                candidato c = *it2;
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
                candidato c = *it2;
				if(c.getVotosNominaisCandidato() < naoEleitoMenosVotos){
					numCandidatosMenosVotos++;
				}
			}

            int encontrados = 0;
			while (encontrados < candidatosEleitosMajoritariamente.size()){
				candidato c = library.return_candidato(candidatosEleitos, (candidatosEleitosMajoritariamente.size() - encontrados -1));
				int pos = -qtdVagas;

                for(it2 = candidatosMaisVotados.begin(); it2 != candidatosMaisVotados.end(); ++it2){
                    candidato k = *it2;

					if(c.compare_candidato(k) == 0){
						partido p = vereadores.retornaPartidoPeloNum(c.getNumeroPartidoCandidato());
						myfile << pos+1 << " - " << c.getNomeCandidato() << " / " << c.getNomeUrnaCandidato() << " (" << p.getSiglaPartido() << ", " << c.getVotosNominaisCandidato() << " votos)" << endl;
						encontrados++;
						break;
					}

					pos++;
				}
			}

			myfile << endl;
			myfile << "Votação dos partidos e número de candidatos eleitos:" << endl;

            for(it = listaPartidos.begin(); it != listaPartidos.end(); ++it){
                partido p = *it;
				totalVotosNominaisPartido = 0;

                for(it2 = p.getcandidatoPartido().begin(); it2 != p.getcandidatoPartido().end(); ++it2){
                    candidato c = *it2;
                    
					if(!c.getDestinoVoto().compare("Válido"))
						totalVotosNominaisPartido += c.getVotosNominaisCandidato();
				}

				totalVotosPartido = totalVotosNominaisPartido + p.getVotosLegendaPartido();
				p.setVotosNominaisTotaisPartido(totalVotosNominaisPartido);
				p.setVotosTotaisPartido(totalVotosPartido);
			}
			
			listaPartidos.sort(comparator.comparePartido());
			// Collections.sort(listaPartidos, new votosPartidosComparator());

            cont = qtdPartidos;
			aux2 = 0;
			
			while(aux2 < qtdPartidos){
                for(it = listaPartidos.begin(); it != listaPartidos.end(); ++it){
                    partido p = *it;
                    cont--;

                    if(cont == aux2){
                        for(it2 = p.getcandidatoPartido().begin(); it2 != p.getcandidatoPartido().end(); ++it2){ // nao seii
                            candidato c = *it2;

                            if(c.getSituacaoCandidato().compare(comparaSituacao)){
                                qtdEleitosPartido++;
                            }
                        }

                    myfile << cont+1 << " - " <<p.getSiglaPartido() << " - " << p.getNumeroPartido() << ", " << p.getVotosTotaisPartido() << " voto" << (p.getVotosTotaisPartido() > 1 ? "s" : "") <<  " (" << p.getVotosNominaisTotaisPartido() << (p.getVotosNominaisTotaisPartido() > 1 ? " nominais" : " nominal") << " e " << p.getVotosLegendaPartido() << " de legenda), " << qtdEleitosPartido << " candidato" << (qtdEleitosPartido > 1 ? "s": "") << " eleito" << (qtdEleitosPartido > 1 ? "s": "") << endl; 
                    qtdEleitosPartido = 0;
                    aux2++;
                    cont = (qtdPartidos-1)+aux2;

                        if(cont >= (qtdPartidos*2)-1){
                            break;
                        }
                    }
                }
			}

            cont = 0;

			myfile << endl;
			myfile << "Primeiro e último colocados de cada partido:" << endl;

            for(it = listaPartidos.begin(); it != listaPartidos.end(); ++it){
                partido p = *it;
				cont++;

				if(p.getVotosTotaisPartido() == 0){
					cont--;
					continue;
				}
                
                for(it2 = p.getcandidatoPartido().begin(); it2 != p.getcandidatoPartido().end(); ++it2){ // nao seii
                    candidato c = *it2;

					if(!c.getDestinoVoto().compare("Válido")){
                        continue;
                    } 

					if(c.getVotosNominaisCandidato() < candidatoMenosVotado){
						candidatoMenosVotado = c.getVotosNominaisCandidato(); 
					}

					if(c.getVotosNominaisCandidato() > candidatoMaisVotado){
						candidatoMaisVotado = c.getVotosNominaisCandidato();
					}
				}

                for(it2 = p.getcandidatoPartido().begin(); it2 != p.getcandidatoPartido().end(); ++it2){ // nao seii
                    candidato c = *it2;

					if(c.getVotosNominaisCandidato() == candidatoMaisVotado){
						maisVotadoPartido.insert(maisVotadoPartido.end(), c);
					}
				}
				
                for(it2 = p.getcandidatoPartido().begin(); it2 != p.getcandidatoPartido().end(); ++it2){ // nao seii
                    candidato c = *it2;

					if(c.getVotosNominaisCandidato() == candidatoMenosVotado){						
							menosVotadoPartido.insert(menosVotadoPartido.end(), c);						
						//myfile << c.getNomeCandidato() + " (" + c.getNumeroCandidato() + ", " + c.getVotosNominaisCandidato() +" votos)");
					}
				}

				candidatoMaisVotado = 0; 
				candidatoMenosVotado = 10000;
			}
			
			maisVotadoPartido.sort(comparator.compare2());
			// Collections.sort(maisVotadoPartido, new votosComparator2());

            qtdPartidos=cont;
			aux2 = cont;
			aux = 0;
            cont = 0; 
		
			while(cont < aux2){
                for(it2 = maisVotadoPartido.begin(); it2 != maisVotadoPartido.end(); ++it2){ // nao seii
                    candidato c = *it2;

					if(qtdPartidos != aux && cont == 0){
					    qtdPartidos--; 
					}else if(qtdPartidos != aux && cont > 0){
						qtdPartidos++;
					}
					if(qtdPartidos == aux){ 
						cont++;
						aux = aux2-cont; 
						qtdPartidos = 0;
						partido p = vereadores.retornaPartidoPeloNum(c.getNumeroPartidoCandidato());

						myfile << cont << " - " << p.getSiglaPartido() << " - " << p.getNumeroPartido() << ", " << c.getNomeUrnaCandidato() << " (" << c.getNumeroCandidato() << ", " << c.getVotosNominaisCandidato() <<" voto" << (c.getVotosNominaisCandidato() > 1 ? "s" : "") << ")" << " / " << endl;
						
                        comparaPartido = c.getNumeroPartidoCandidato();

						list<candidato> menosVotados;

                        for(it2 = menosVotadoPartido.begin(); it2 != menosVotadoPartido.end(); ++it2){ // nao seii
                            candidato x = *it2;

							if(comparaPartido == x.getNumeroPartidoCandidato()){								
								menosVotados.insert(menosVotados.end(), x);								
							}
						}	

                        menosVotados.sort(comparator.compare());
                        // Collections.sort(menosVotados, new votosComparator());

                        myfile << library.return_candidato(menosVotados,0).getNomeUrnaCandidato() << " (" << library.return_candidato(menosVotados,0).getNumeroCandidato() << ", " << library.return_candidato(menosVotados,0).getVotosNominaisCandidato() <<" voto" << (library.return_candidato(menosVotados,0).getVotosNominaisCandidato() > 1 ? "s" : "") << ")" << endl;						
						
                        if(cont <= aux2){
							break;
						}
					}
				}
            }

            // DecimalFormat df = new DecimalFormat("0.00");
			myfile << endl;
			myfile << "Eleitos, por faixa etária (na data da eleição):" << endl;
			// myfile << "      Idade < 30: " << idadeAbaixoTrinta << " (" << df.format((idadeAbaixoTrinta/(double)qtdVagas)*100) << "%)" << endl;
			// myfile << "30 <= Idade < 40: " << idadeAbaixoQuarenta << " (" << df.format((idadeAbaixoQuarenta/(double)qtdVagas)*100) << "%)" << endl;
			// myfile << "40 <= Idade < 50: " << idadeAbaixoCinquenta << " (" << df.format((idadeAbaixoCinquenta/(double)qtdVagas)*100) << "%)" << endl;
			// myfile << "50 <= Idade < 60: " << idadeAbaixoSessenta << " (" << df.format((idadeAbaixoSessenta/(double)qtdVagas)*100) << "%)" << endl;
			// myfile << "60 <= Idade     : " << idadeAcimaSessenta << " (" << df.format((idadeAcimaSessenta/(double)qtdVagas)*100) << "%)" << endl;

            myfile << "      Idade < 30: " << idadeAbaixoTrinta << " (" << setprecision(2) <<((idadeAbaixoTrinta/(double)qtdVagas)*100) << "%)" << endl;
			myfile << "30 <= Idade < 40: " << idadeAbaixoQuarenta << " (" << setprecision(2) <<((idadeAbaixoQuarenta/(double)qtdVagas)*100) << "%)" << endl;
			myfile << "40 <= Idade < 50: " << idadeAbaixoCinquenta << " (" << setprecision(2) <<((idadeAbaixoCinquenta/(double)qtdVagas)*100) << "%)" << endl;
			myfile << "50 <= Idade < 60: " << idadeAbaixoSessenta << " (" << setprecision(2) <<((idadeAbaixoSessenta/(double)qtdVagas)*100) << "%)" << endl;
			myfile << "60 <= Idade     : " << idadeAcimaSessenta << " (" << setprecision(2) <<((idadeAcimaSessenta/(double)qtdVagas)*100) << "%)" << endl;

            // setprecision(5)
			myfile << endl;
			
			
			porcentagemEleitasF = (qtdMulheresEleitas/(double)qtdVagas)*100;
			porcentagemEleitosM = (qtdHomensEleitos/(double)qtdVagas)*100; 

			myfile << "Eleitos, por sexo:" << endl; 
			myfile << "Feminino:  " << qtdMulheresEleitas << " (" << setprecision(2) << porcentagemEleitasF << "%)" << endl;
			myfile << "Masculino: " << qtdHomensEleitos << " (" << setprecision(2) << porcentagemEleitosM << "%)" << endl;
			myfile << endl;

			totalVotos = totalVotosLegenda + totalVotosNominais; 

			myfile << "Total de votos válidos:    " << totalVotos << endl; 

			porcentagemVnominais = (totalVotosNominais/(double)totalVotos)*100; 
			porcentagemVlegenda = (totalVotosLegenda/(double)totalVotos)*100; 

			myfile << "Total de votos nominais:   " << totalVotosNominais << " (" << setprecision(2) << porcentagemVnominais << "%)" << endl; 
			myfile << "Total de votos de Legenda: " << totalVotosLegenda << " (" << setprecision(2) << porcentagemVlegenda << "%)\n" << endl; 

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
