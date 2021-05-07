#ifndef leitura_hpp_
#define leitura_hpp_

#include <string>
#include "eleicao.hpp"

class leitura {
	
	string nPartido,vLegenda,nomePartido,siglaPartido; 
	string numCandidato,vNominaisCandidato,situCandidato,noCandidato,noUrnaCandidato,sexCandidato,datNascCandidato,destVotoCandidato,nPartidoCandidato;
	string comparaSituacao, comparaSexof, comparaSexom; 
	int qtdVagas, qtdMulheresEleitas, qtdHomensEleitos, totalVotos, totalVotosNominais, totalVotosLegenda; 
	
	public:
    leitura();
	
    void lePartidos(eleicao vereadores, string path);
	
	void leCandidatos(eleicao vereadores, string path);
};

#endif /* leitura_hpp_ */