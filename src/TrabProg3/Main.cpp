#include <string>
#include "Eleicao.hpp"
#include "Leitura.hpp"
#include "Escrita.hpp"
#include "Date.hpp"
#include "Lib.hpp"

using namespace std;

int main(int argc, char** argv){

		Eleicao vereador = Eleicao(); 
		Lib help = Lib();
		string arquivoCandidatos = argv[1];
		string arquivoPartidos = argv[2];		
		string dataString = argv[3];

		Leitura lerCandidatos = Leitura(); 
		list<Candidato> c = lerCandidatos.leCandidatos(vereador,arquivoCandidatos);
		Leitura lerPartidos = Leitura(); 
		lerPartidos.lePartidos(vereador,arquivoPartidos, c);


		// vereador.printEleicao();

		Escrita escreveArquivoSaida = Escrita();
        Date data = help.stringToDate(dataString);
		escreveArquivoSaida.escreveArquivo("out",data,vereador);		
		
		return 0;
}