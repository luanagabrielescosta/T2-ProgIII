#include <string>
#include "eleicao.hpp"
#include "leitura.hpp"
#include "escrita.hpp"
#include "date.hpp"

using namespace std;

int main(int argc, char** argv){

		eleicao vereador = eleicao(); 
		string arquivoCandidatos = argv[1];
		string arquivoPartidos = argv[2];		
		string dataString = argv[3];

		cout << arquivoCandidatos << " |here|"<< endl; // delete
		cout << arquivoPartidos << " |i|" << endl; // delete
		cout << dataString << " |am|" << endl; // delete

		leitura lerPartidos = leitura(); 
		lerPartidos.lePartidos(vereador,arquivoPartidos);
		leitura lerCandidatos = leitura(); 
		// lerCandidatos.leCandidatos(vereador,arquivoCandidatos);
		// escrita escreveArquivoSaida = escrita();
		// SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy");
        // date data = formato.parse(dataString);
		// escreveArquivoSaida.escreveArquivo("out.txt",data,vereador);		
		
		return 0;
}