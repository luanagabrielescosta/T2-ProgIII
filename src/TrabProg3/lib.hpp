#ifndef lib_h_
#define lib_h_

#include <string>
#include <list>
#include "Date.hpp"
#include "Candidato.hpp"

class Lib{
    public:
    // Constructor
    Lib();
    // Destructor
    ~Lib();

    // Métodos
    int stringToInt(std::string &old);
    Date stringToDate(std:: string &old);
    char stringToChar(std:: string &old);
    char intToChar(int old);
    int returnInt(list< int, allocator<int> > &list, int one);
    Candidato returnCandidato(list<Candidato> lista, Candidato &c, int one);
    int returnPosicao(list<Candidato> lista, string nome);
};


#endif /* lib_h_ */