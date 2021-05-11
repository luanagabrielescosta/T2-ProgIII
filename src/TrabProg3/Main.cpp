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

		cout << arquivoCandidatos << " |here|"<< endl; // delete
		cout << arquivoPartidos << " |i|" << endl; // delete
		cout << dataString << " |am|" << endl; // delete

		Leitura lerPartidos = Leitura(); 
		lerPartidos.lePartidos(vereador,arquivoPartidos);
		Leitura lerCandidatos = Leitura(); 
		lerCandidatos.leCandidatos(vereador,arquivoCandidatos);


		cout << "SOCORRO" << endl;
		vereador.printEleicao();

		Escrita escreveArquivoSaida = Escrita();
        Date data = help.string_to_date(dataString);
		escreveArquivoSaida.escreveArquivo("out",data,vereador);		
		cout << "aaaa" << endl;
		
		return 0;
}
// g++ *.cpp -o vereadores 
// ./vereadores afonso-cláudio-candidatos.csv afonso-claudio-partidos.csv 03/06/2000