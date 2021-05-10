#ifndef escrita_hpp_
#define escrita_hpp_

#include "Eleicao.hpp"

class Escrita{
	public:
    Escrita();

	bool escreveArquivo(string Caminho, Date dataeleicao, Eleicao vereadores);
};

#endif /* escrita_hpp_ */