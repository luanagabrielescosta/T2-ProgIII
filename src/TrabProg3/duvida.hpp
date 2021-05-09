	// bool escrita::escreveArquivo(string Caminho, date dataeleicao, eleicao vereadores) {
		// try {
			// PrintWriter escreverArquivo = new PrintWriter(new OutputStreamWriter (new FileOutputStream (Caminho), "UTF-8")); 
			// list<partido> listaPartidos = vereadores.getPartidoseleicao(); 
			// list<string> infoCandidatoEleito; 
			// list<candidato> candidatosEleitos;
			// list<candidato> candidatosVotos;
			// list<candidato> candidatosMaisVotados; 
			// list<candidato> candidatosEleitosMajoritariamente; 
			// list<candidato> maisVotadoPartido; 
			// list<candidato> menosVotadoPartido;			
			// list <int> posicaoRanking;
			// list <int> posicaoRankingMenosVotadosEleitos;
			
			// int posicaoEleito=1, totalCandidatos=0, aux=0, cont=0, posicaoCandidato=1, eleitoMenosVotos=10000, qtdVagas=0, comparaPartido; 
			// int candidatoMenosVotado = 10000, candidatoMaisVotado = 0, numeroCandidatoMenosVotado, numeroCandidatoMaisVotado;
			// int totalVotosNominaisPartido=0, totalVotosPartido=0, qtdEleitosPartido=0, qtdPartidos=0, totalVotos=0, totalVotosNominais=0, totalVotosLegenda=0, qtdMulheresEleitas=0, qtdHomensEleitos=0;
			// string comparaSituacao = "Eleito", comparaSexoF= "F", comparaSexoM = "M"; 
			// double porcentagemEleitasF, porcentagemEleitosM;
			// double porcentagemVnominais, porcentagemVlegenda;
			// int idadeAbaixoTrinta=0, idadeAbaixoQuarenta=0, idadeAbaixoCinquenta=0, idadeAbaixoSessenta=0, idadeAcimaSessenta=0;
			//vereadores.setDataeleicao("15/11/2020");
			
			//Fun��o de leitura, tamb�m utilizada para descobrir a quantidade de vagas. 
			// for(partido p = listaPartidos.begin(); p != listaPartidos.end(); ++p){
			// 	qtdPartidos++;
			// 	totalVotosLegenda += p.getVotosLegendaPartido(); 
			// 	for(candidato c : p.getCandidatosPartido()) {
			// 		totalCandidatos++;
			// 		if(c.getDestinoVoto().equalsIgnoreCase("Válido")) {
			// 			totalVotosNominais += c.getVotosNominaisCandidato();	
			// 		}
					
			// 		candidato ca = candidato(c.getNumeroCandidato(),c.getVotosNominaisCandidato(),c.getSituacaoCandidato(),c.getNomeCandidato(),c.getNomeUrnaCandidato(),c.getSexoCandidato(),c.getDataNascimentoCandidato(),c.getDestinoVoto(),c.getNumeroPartidoCandidato());
			// 		candidatosVotos.insert(candidatosVotos.end(),ca); 
			// 		if(c.getSituacaoCandidato().equals(comparaSituacao)){
			// 		candidatosEleitos.insert(candidatosEleitos.end(), ca);
			// 		qtdVagas++; 
			// 		infoCandidatoEleito.insert(infoCandidatoEleito.end(), c.getNomeCandidato() + " / " + c.getNomeUrnaCandidato() + " (" + p.getSiglaPartido()+ ", " + c.getVotosNominaisCandidato() + " votos)");
			// 		if(c.getSexoCandidato().equals(comparaSexoF)) {
			// 			qtdMulheresEleitas++; 
			// 		}else if(c.getSexoCandidato().equals(comparaSexoM)) {
			// 			qtdHomensEleitos++;
			// 		}
			// 		}
			// 	}
			// }
			
			// Collections.sort(candidatosEleitos, new votosComparator());
			
			// int aux2 = qtdVagas; 
			
			// //escrita da quantidade de vagas; 
			// escreverArquivo.println("Número de vagas: " + qtdVagas);
			// escreverArquivo.println();
			// //Aqui vamos escrever os candidatos eleitos que foram adicionados a uma lista de eleitos no loop de leitura.
			// escreverArquivo.println("Vereadores eleitos:");
			
			
			// while(cont < aux2) {
			// 	for(Candidatos c : candidatosEleitos) {
			// 		if(qtdVagas != aux && cont == 0) {
			// 		qtdVagas--; 
			// 		}else if(qtdVagas != aux && cont > 0) {
			// 			qtdVagas++;
			// 		}
			// 		if(qtdVagas == aux) {
						
			// 			Calendar dataNascimento = Calendar.getInstance();
			// 			dataNascimento.setTime(c.getDataNascimentoCandidato());
			// 			Calendar dataeleicaoAux = Calendar.getInstance();
			// 			dataeleicaoAux.setTime(dataeleicao);

			// 			Integer diferencaMes = dataeleicaoAux.get(Calendar.MONTH) - dataNascimento.get(Calendar.MONTH);
			// 			Integer diferencaDia = dataeleicaoAux.get(Calendar.DAY_OF_MONTH) - dataNascimento.get(Calendar.DAY_OF_MONTH);
			// 			Integer idade = (dataeleicaoAux.get(Calendar.YEAR) - dataNascimento.get(Calendar.YEAR));

			// 			if(diferencaMes < 0 || (diferencaMes == 0 && diferencaDia < 0)) {
			// 				idade--;
			// 			}
						
			// 			if(idade < 30) {
			// 				idadeAbaixoTrinta++;
			// 			} else if (idade < 40) {
			// 				idadeAbaixoQuarenta++;
			// 			} else if (idade < 50) {
			// 				idadeAbaixoCinquenta++;
			// 			} else if (idade < 60) {
			// 				idadeAbaixoSessenta++;
			// 			}else {
			// 				idadeAcimaSessenta++;
			// 			}
						
			// 			Partidos p = vereadores.retornaPartidoPeloNum(c.getNumeroPartidoCandidato()); 
			// 			escreverArquivo.println(posicaoCandidato + " - " + c.getNomeCandidato() + " / " + c.getNomeUrnaCandidato() + " (" + p.getSiglaPartido() + ", " + c.getVotosNominaisCandidato() + " votos)");   
			// 			aux=aux2-1;
			// 			cont++;						
			// 			qtdVagas = 0;
			// 			posicaoCandidato++;
			// 			if(cont == aux2) {
			// 				break;
			// 			}
			// 		}
			// 	}
			// 	}
			
			// 	qtdVagas = aux2; 
			// 	cont = 0;
			// 	aux = 0;
			// 	posicaoCandidato = 1;
			
			
			
			
			// aux2 = totalCandidatos;
	
			//Aqui � feita a ordena��o por quantidade de votos Nominais dos candidatos. 
			// Collections.sort(candidatosVotos, new votosComparator());
			// Collections.sort(candidatosVotos,Collections.reverseOrder());
			// escreverArquivo.println();
			// escreverArquivo.println("Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):");
			
			// comparaSituacao = "Eleito";
			
			//Aqui foi necess�rio fazer uma pequena "Gambiarra" para que as informa��es fossem escritas em ordem descrescente
			//J� que a fun��o de ordena��o deixou em ordem crescente. 
			// while(cont < qtdVagas){
			// for(Candidatos c : candidatosVotos) { 
			// 	if(totalCandidatos != aux && cont == 0) {
			// 	totalCandidatos--; 
			// 	}else if(totalCandidatos != aux && cont > 0) {
			// 		totalCandidatos++;
			// 	}
			// 	if(totalCandidatos == aux) { 
			// 		candidatosMaisVotados.add(c); 
			// 		if(!c.getSituacaoCandidato().equals(comparaSituacao)) {
			// 		candidatosEleitosMajoritariamente.add(c);
			// 		posicaoRanking.add(posicaoCandidato);
			// 		}
			// 		Partidos p = vereadores.retornaPartidoPeloNum(c.getNumeroPartidoCandidato()); 
			// 		escreverArquivo.println(posicaoCandidato + " - " + c.getNomeCandidato() + " / " + c.getNomeUrnaCandidato() + " (" + p.getSiglaPartido() + ", " + c.getVotosNominaisCandidato() + " votos)"); 
			// 		aux += aux2; 
			// 		totalCandidatos+=1; 
			// 		cont++;
			// 		posicaoCandidato++;
			// 		if(cont == qtdVagas) {
			// 			break;
			// 		}
			// 	}
			// }
			// }
			
			// posicaoCandidato = 0;
			// escreverArquivo.println();
			// escreverArquivo.println("Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n"
			// 		+ "(com sua posição no ranking de mais votados)");
			
			//Aqui n�s apenas escrevemos no arquivo uma lista em que adicionamos os candidatos que se encaixam nessa categoria
			//Eles foram adicionados no while+for logo acima ap�s ser feita uma compara��o.
			// for(Candidatos c : candidatosEleitosMajoritariamente) {
			// 	Partidos p = vereadores.retornaPartidoPeloNum(c.getNumeroPartidoCandidato());
			// 		escreverArquivo.println(posicaoRanking.get(posicaoCandidato) + " - " + c.getNomeCandidato() + " / " + c.getNomeUrnaCandidato() + " (" + p.getSiglaPartido() + ", " + c.getVotosNominaisCandidato() + " votos)");
			// 		posicaoCandidato++;
			// }
			
			//Aqui � feito um loop para obtermos quem foi o candidato menos votado entre os eleitos, ser� �til para descobrirmos
			//quem tirou vantagem do formato proporcional.
			// for(Candidatos c : candidatosMaisVotados) {
			// 	if(c.getVotosNominaisCandidato() < eleitoMenosVotos) {
			// 		eleitoMenosVotos = c.getVotosNominaisCandidato();
			// 	}
			// }
			
			// 2.147.483.647 é o número máximo que um int suporta.
			// int naoEleitoMenosVotos = 2147483647;
			// for (Candidatos c : candidatosEleitosMajoritariamente) {
			// 	if(c.getVotosNominaisCandidato() < naoEleitoMenosVotos && !c.getSituacaoCandidato().equals("Eleito")) {
			// 		naoEleitoMenosVotos = c.getVotosNominaisCandidato();
			// 	}
			// }
			
			// totalCandidatos = aux2;
			// aux=0;cont=0;
			//System.out.println("aux2: " + aux2 + "totalCandidatos: " + totalCandidatos);
			
			//Antes j� tinhamos manipulado a lista CandidatosMaisVotados para imprimir os candidatos de acordo com a quantidade de vagas
			//Agora precisamos adicionar todos os candidatos j� que vamos precisar de suas posi��es na lista geral
			
			// while(cont < aux2) {
			// 	for(Candidatos c : candidatosVotos) { 
			// 		if(totalCandidatos != aux && cont == 0) {
			// 		totalCandidatos--; 
			// 		}else if(totalCandidatos != aux && cont > 0) {
			// 			totalCandidatos++;
			// 		}
			// 		if(totalCandidatos == aux) { 
			// 			candidatosMaisVotados.add(c); 
			// 			cont++;
			// 			aux = aux2-cont; 
			// 			//System.out.println("Valores de aux:" + aux);
			// 			totalCandidatos = 0;
			// 			if(cont <= aux2) {
			// 				break;
			// 			}
			// 		}
			// 	}
			// 	}
			
				// cont=0; 
				// aux=totalCandidatos;
				// for(Candidatos c : candidatosVotos) {
				// 	cont=aux; 
				// 	aux--;
				// 	//System.out.println("Posicao: " + cont +  "Nome: " + c.getNomeCandidato() + "Votos: " + c.getVotosNominaisCandidato());
					
				// }
			
			
			// cont= -qtdVagas;
			// aux  = 0;
			// comparaSituacao = "Eleito";
			// escreverArquivo.println();
			// escreverArquivo.println("Eleitos, que se beneficiaram do sistema proporcional:");
			// escreverArquivo.println("(com sua posição no ranking de mais votados)");
			
			// int numCandidatosMenosVotos = 0;
			
			// for(Candidatos c : candidatosEleitos) {
			// 	if(c.getVotosNominaisCandidato() < naoEleitoMenosVotos) {
			// 		numCandidatosMenosVotos++;
			// 	}
			// }
			// int encontrados = 0;
			// while (encontrados < candidatosEleitosMajoritariamente.size()) {
			// 	Candidatos c = candidatosEleitos.get(candidatosEleitosMajoritariamente.size() - encontrados -1);
			// 	int pos = -qtdVagas;
			// 	for (Candidatos k : candidatosMaisVotados) {
			// 		if(c == k) {
			// 			Partidos p = vereadores.retornaPartidoPeloNum(c.getNumeroPartidoCandidato());
			// 			escreverArquivo.println(pos+1 + " - " + c.getNomeCandidato() + " / " + c.getNomeUrnaCandidato() + " (" + p.getSiglaPartido() + ", " + c.getVotosNominaisCandidato() + " votos)");
			// 			encontrados++;
			// 			break;
			// 		}
			// 		pos++;
			// 	}
			// }

			// escreverArquivo.println();
			// escreverArquivo.println("Votação dos partidos e número de candidatos eleitos:"); 
			// for(Partidos p : listaPartidos) {
			// 	totalVotosNominaisPartido = 0;
			// 	for(Candidatos c: p.getCandidatosPartido()) {
			// 		if(c.getDestinoVoto().equalsIgnoreCase("Válido"))
			// 			totalVotosNominaisPartido += c.getVotosNominaisCandidato();
			// 	}
			// 	totalVotosPartido = totalVotosNominaisPartido + p.getVotosLegendaPartido();
			// 	p.setVotosNominaisTotaisPartido(totalVotosNominaisPartido);
			// 	p.setVotosTotaisPartido(totalVotosPartido);
			// }
			
			// Collections.sort(listaPartidos, new votosPartidosComparator());
//			for(Partidos p: listaPartidos) {
//				//System.out.println("Nome partido: " + p.getSiglaPartido() + "Votos Partido: " + p.getVotosTotaisPartido());
//			}
			
			// cont=qtdPartidos;
			// aux2=0;
			
			
			// while(aux2 < qtdPartidos) {
			// for(Partidos p : listaPartidos) {
			// 	cont--;
			// 	if(cont == aux2) {
			// 	for(Candidatos c: p.candidatosPartido) {
			// 		if(c.getSituacaoCandidato().equals(comparaSituacao)) {
			// 			qtdEleitosPartido++;
			// 		}
			// 	}
			// 	escreverArquivo.println(cont+1 + " - " +p.getSiglaPartido() + " - " + p.getNumeroPartido() + ", " + p.getVotosTotaisPartido() + " voto" + (p.getVotosTotaisPartido() > 1 ? "s" : "") +  " (" + p.getVotosNominaisTotaisPartido() + (p.getVotosNominaisTotaisPartido() > 1 ? " nominais" : " nominal") + " e " + p.getVotosLegendaPartido() + " de legenda), " + qtdEleitosPartido + " candidato" + (qtdEleitosPartido > 1 ? "s": "") + " eleito" + (qtdEleitosPartido > 1 ? "s": "")); 
			// 	qtdEleitosPartido = 0;
			// 	aux2++; 
			// 	cont=(qtdPartidos-1)+aux2;
			// 	if(cont >= (qtdPartidos*2)-1) {
			// 		break;
			// 	}
			// 	}
			// }
			// }
			
			// cont = 0;
			// escreverArquivo.println();
			// escreverArquivo.println("Primeiro e último colocados de cada partido:");
			// for(Partidos p : listaPartidos) {
			// 	cont++;
			// 	if(p.getVotosTotaisPartido() == 0) {
			// 		cont--;
			// 		continue;
			// 	}
			// 	for(Candidatos c : p.getCandidatosPartido()) {
			// 		if(!c.getDestinoVoto().equals("Válido")) continue;
			// 		if(c.getVotosNominaisCandidato() < candidatoMenosVotado) {
			// 			candidatoMenosVotado = c.getVotosNominaisCandidato(); 
			// 		}
			// 		if(c.getVotosNominaisCandidato() > candidatoMaisVotado) {
			// 			candidatoMaisVotado = c.getVotosNominaisCandidato();
			// 		}
			// 	}
			// 	for(Candidatos c : p.getCandidatosPartido()) {
			// 		if(c.getVotosNominaisCandidato() == candidatoMaisVotado) {
			// 			maisVotadoPartido.add(c);
			// 			//escreverArquivo.print(cont + " - " + p.getSiglaPartido() + " - " + p.getNumeroPartido() + ", " + c.getNomeCandidato() + " (" + c.getNumeroCandidato() + ", " + c.getVotosNominaisCandidato() +" votos)" + " / ");
			// 		}
			// 	}
				
			// 	for(Candidatos c : p.getCandidatosPartido()) {
			// 		if(c.getVotosNominaisCandidato() == candidatoMenosVotado) {						
			// 				menosVotadoPartido.add(c);						
			// 			//escreverArquivo.println(c.getNomeCandidato() + " (" + c.getNumeroCandidato() + ", " + c.getVotosNominaisCandidato() +" votos)");
			// 		}
			// 	}
			// 	candidatoMaisVotado = 0; 
			// 	candidatoMenosVotado = 10000;
			// }
			
			// Collections.sort(maisVotadoPartido, new votosComparator2());
//			Collections.sort(menosVotadoPartido, new votosComparator());
			
			//System.out.println("qtd partidos: " + qtdPartidos);
			// qtdPartidos=cont;
			// aux2 = cont;
			// aux =0;cont=0; 
		
			// while(cont < aux2) {
			// 	for(Candidatos c : maisVotadoPartido) { 
			// 		if(qtdPartidos != aux && cont == 0) {
			// 		qtdPartidos--; 
			// 		}else if(qtdPartidos != aux && cont > 0) {
			// 			qtdPartidos++;
			// 		}
			// 		if(qtdPartidos == aux) { 
			// 			cont++;
			// 			aux = aux2-cont; 
			// 			//System.out.println("Valores de aux:" + aux);
			// 			qtdPartidos = 0;
			// 			Partidos p = vereadores.retornaPartidoPeloNum(c.getNumeroPartidoCandidato());
			// 			escreverArquivo.print(cont + " - " + p.getSiglaPartido() + " - " + p.getNumeroPartido() + ", " + c.getNomeUrnaCandidato() + " (" + c.getNumeroCandidato() + ", " + c.getVotosNominaisCandidato() +" voto" + (c.getVotosNominaisCandidato() > 1 ? "s" : "") + ")" + " / ");
			// 			comparaPartido = c.getNumeroPartidoCandidato();
			// 			ArrayList<Candidatos> menosVotados = new ArrayList<>();
			// 			for(Candidatos x : menosVotadoPartido) {
			// 				if(comparaPartido == x.getNumeroPartidoCandidato()) {								
			// 					menosVotados.add(x);								
			// 				}
			// 			}		
			// 				Collections.sort(menosVotados, new votosComparator());
			// 				escreverArquivo.println(menosVotados.get(0).getNomeUrnaCandidato() + " (" + menosVotados.get(0).getNumeroCandidato() + ", " + menosVotados.get(0).getVotosNominaisCandidato() +" voto" + (menosVotados.get(0).getVotosNominaisCandidato() > 1 ? "s" : "") + ")");						
			// 			if(cont <= aux2) {
			// 				break;
			// 			}
			// 		}
			// 	}
			// 	}
			
			
			// DecimalFormat df = new DecimalFormat("0.00");
			// escreverArquivo.println();
			// escreverArquivo.println("Eleitos, por faixa etária (na data da eleição):");
			// escreverArquivo.println("      Idade < 30: " + idadeAbaixoTrinta + " (" + df.format((idadeAbaixoTrinta/(double)qtdVagas)*100) + "%)");
			// escreverArquivo.println("30 <= Idade < 40: " + idadeAbaixoQuarenta + " (" + df.format((idadeAbaixoQuarenta/(double)qtdVagas)*100) + "%)");
			// escreverArquivo.println("40 <= Idade < 50: " + idadeAbaixoCinquenta + " (" + df.format((idadeAbaixoCinquenta/(double)qtdVagas)*100) + "%)");
			// escreverArquivo.println("50 <= Idade < 60: " + idadeAbaixoSessenta + " (" + df.format((idadeAbaixoSessenta/(double)qtdVagas)*100) + "%)");
			// escreverArquivo.println("60 <= Idade     : " + idadeAcimaSessenta + " (" + df.format((idadeAcimaSessenta/(double)qtdVagas)*100) + "%)");
			// escreverArquivo.println();
			
			
			// porcentagemEleitasF = (qtdMulheresEleitas/(double)qtdVagas)*100;
			// porcentagemEleitosM = (qtdHomensEleitos/(double)qtdVagas)*100; 
			// escreverArquivo.println("Eleitos, por sexo:"); 
			// escreverArquivo.println("Feminino:  " + qtdMulheresEleitas + " (" + df.format(porcentagemEleitasF) + "%)");
			// escreverArquivo.println("Masculino: " + qtdHomensEleitos + " (" + df.format(porcentagemEleitosM) + "%)");
			// escreverArquivo.println();
			// totalVotos = totalVotosLegenda + totalVotosNominais; 
			// escreverArquivo.println("Total de votos válidos:    "+ totalVotos); 
			// porcentagemVnominais = (totalVotosNominais/(double)totalVotos)*100; 
			// porcentagemVlegenda = (totalVotosLegenda/(double)totalVotos)*100; 
			// escreverArquivo.println("Total de votos nominais:   " + totalVotosNominais + " (" + df.format(porcentagemVnominais) + "%)"); 
			// escreverArquivo.println("Total de votos de Legenda: " + totalVotosLegenda + " (" + df.format(porcentagemVlegenda) + "%)\n"); 
			// escreverArquivo.close();
		// 	return true;
			
		// } catch(IOException e) {
		// 	System.out.println(e.getMessage());
		// 	return false;
		// }
		
	// }