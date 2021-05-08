#ifndef lib_h_
#define lib_h_

#include <string>
#include "date.hpp"

class lib{
    public:
    lib();
    int string_to_int(std::string old);
    date string_to_date(std:: string old);
    char string_to_char(std:: string old);
};


#endif /* lib_h_ */