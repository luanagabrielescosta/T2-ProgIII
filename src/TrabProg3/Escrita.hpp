#ifndef escrita_hpp_
#define escrita_hpp_

#include "Eleicao.hpp"

class Escrita{
	public:
	// Constructor
    Escrita();
	// Destructor 
    ~Escrita();

	// Métodos
	bool escreveArquivo(Date dataeleicao, Eleicao vereadores);
};

#endif /* escrita_hpp_ */