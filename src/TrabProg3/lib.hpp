#ifndef lib_h_
#define lib_h_

#include <string>
#include <list>
#include "date.hpp"
#include "candidato.hpp"

class lib{
    public:
    lib();
    int string_to_int(std::string old);
    date string_to_date(std:: string old);
    char string_to_char(std:: string old);
    char int_to_char(int old);
    int return_int(list<int> list, int one);
    candidato return_candidato(list<candidato> list, int one);
};


#endif /* lib_h_ */