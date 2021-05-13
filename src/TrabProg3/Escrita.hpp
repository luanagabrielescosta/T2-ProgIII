/*
// @ Implementação por:
// @   Eduardo Afonso Ribeiro Rodrigues
// @   Luana Gabriele de Sousa Costa
// @ cpp da classe de escrita
*/

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

	// Função que escreve o output no terminal
	// Obs: Serve como gerenciadora
	bool escreveArquivo(Date dataeleicao, Eleicao vereadores);
};

#endif /* escrita_hpp_ */