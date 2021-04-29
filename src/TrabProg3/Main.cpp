#include <string>
#include "Eleicao.hpp"
#include "Leitura.hpp"
#include "Escrita.hpp"

using namespace std;

class Main{
	public:
	static int main(string args){

		Eleicao vereador = Eleicao(); 
		string arquivoCandidatos = args[0];
		string arquivoPartidos = args[1];		
		string dataString = args[2];
		Leitura lerPartidos = new Leitura(); 
		lerPartidos.lePartidos(vereador,arquivoPartidos);
		Leitura lerCandidatos = new Leitura(); 
		lerCandidatos.leCandidatos(vereador,arquivoCandidatos);
		Escrita escreveArquivoSaida = new Escrita();
		SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy");
        Date data = formato.parse(dataString);
		escreveArquivoSaida.escreveArquivo("out.txt",data,vereador);		
		
		return 0;
	}
};


