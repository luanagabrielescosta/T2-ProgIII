#ifndef lib_h_
#define lib_h_

#include <string>
#include <list>
#include "Date.hpp"
#include "Candidato.hpp"

class Lib{
    public:
    Lib();
    int string_to_int(std::string &old);
    Date string_to_date(std:: string &old);
    char string_to_char(std:: string &old);
    char int_to_char(int old);
    int return_int(list< int, allocator<int> > &list, int one);
    Candidato return_candidato(list< Candidato, allocator<Candidato> > &list, int one);
};


#endif /* lib_h_ */