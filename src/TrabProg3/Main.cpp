/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ arquivo main da eleição
*/

#include <string>
#include "Eleicao.hpp"
#include "Leitura.hpp"
#include "Escrita.hpp"
#include "Date.hpp"
#include "Lib.hpp"

using namespace std;

// Função main
int main(int argc, char** argv){
	Eleicao vereador = Eleicao(); // Eleição inicializada
	Lib help = Lib(); // Lib inicializada
	string arquivoCandidatos = argv[1]; // String path candidatos atribuida
	string arquivoPartidos = argv[2]; // String path partidos atribuida		
	string dataString = argv[3]; // String de data atribuida

	Leitura lerArquivo = Leitura(); // Leitura inicializada
	list<Candidato> c = lerArquivo.leCandidatos(vereador,arquivoCandidatos); // Lê o arquivo de candidatos
	lerArquivo.lePartidos(vereador,arquivoPartidos, c); // Lê o arquivo de partidos

	Escrita escreveArquivoSaida = Escrita(); // Escrita inicializada
	Date data = help.stringToDate(dataString); // Data da eleição inicializada e atribuindo
	escreveArquivoSaida.escreveArquivo(data, vereador); // Chamada da função de escrita
	
	return 0;
}