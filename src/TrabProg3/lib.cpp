#include "Lib.hpp"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

Lib::Lib(){
}

int Lib::string_to_int(string &old){
    int count;

    for(int i = 0; i < old.size(); i++){
        if(i == 0){
            count = old[i] - 48;
        } else{
            count = count * 10 + (old[i] - 48);
        }
    }
    
    return count;
}

Date Lib::string_to_date(string &old){
    int d, m, y;
    Date a = Date();

    d = (old[0] - 48) * 10 + (old[1] - 48);
    m = (old[3] - 48) * 10 + (old[4] - 48);
    y = (old[6] - 48) * 1000 + (old[7] - 48) * 100 + (old[8] - 48) * 10 + (old[9] - 48);

    a.enter_date(d, m, y);

    return a;
}

char Lib::string_to_char(string &old){
    return old[0];
}

char Lib::int_to_char(int old){
    return (old +'0');
}

int Lib::return_int(list< int, allocator<int> > &lista, int one){
    int count;
    list< int, allocator<int> > :: iterator it;

    for(it = lista.begin(); it != lista.end();it++){
		//printa os numeros pares
		if(count == one){
            return *it;
        }

        count++;
	}

    return 0;
}

Candidato Lib::return_candidato(list< Candidato, allocator<Candidato> > &lista, int one){
    int count;
    Date a = Date();
    a.enter_date(0, 0, 0);
    string b = " ";
    char c = ' ';
    Candidato retorno = Candidato(0, 0, b, b, b, c, a, b, 0);
    list< Candidato, allocator<Candidato> > :: iterator it;

    for(it = lista.begin(); it != lista.end();it++){
		//printa os numeros pares
		if(count == one){
            return *it;
        }

        count++;
	}

    return retorno;
}