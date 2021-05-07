#ifndef escrita_hpp_
#define escrita_hpp_

#include "eleicao.hpp"

class escrita {
	public:
    escrita();

	bool escreveArquivo(string Caminho, date dataeleicao, eleicao vereadores);
};

#endif /* escrita_hpp_ */