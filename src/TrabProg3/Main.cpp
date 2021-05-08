#include <string>
#include "eleicao.hpp"
#include "leitura.hpp"
#include "escrita.hpp"
#include "date.hpp"
#include "lib.hpp"

using namespace std;

int main(int argc, char** argv){

		eleicao vereador = eleicao(); 
		lib help = lib();
		string arquivoCandidatos = argv[1];
		string arquivoPartidos = argv[2];		
		string dataString = argv[3];

		cout << arquivoCandidatos << " |here|"<< endl; // delete
		cout << arquivoPartidos << " |i|" << endl; // delete
		cout << dataString << " |am|" << endl; // delete

		leitura lerPartidos = leitura(); 
		lerPartidos.lePartidos(vereador,arquivoPartidos);
		leitura lerCandidatos = leitura(); 
		lerCandidatos.leCandidatos(vereador,arquivoCandidatos);
		escrita escreveArquivoSaida = escrita();
        date data = help.string_to_date(dataString);
		escreveArquivoSaida.escreveArquivo("out.txt",data,vereador);		
		cout << "aaaa" << endl;
		
		return 0;
}
// g++ *.cpp -o main 
// ./main afonso-cláudio-candidatos.csv afonso-claudio-partidos.csv 03/06/2000