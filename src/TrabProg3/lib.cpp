#include "lib.hpp"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

lib::lib(){
}

int lib::string_to_int(string old){
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

date lib::string_to_date(std:: string old){
    int d, m, y;
    date a = date();

    d = (old[0] - 48) * 10 + (old[1] - 48);
    m = (old[3] - 48) * 10 + (old[4] - 48);
    y = (old[6] - 48) * 1000 + (old[7] - 48) * 100 + (old[8] - 48) * 10 + (old[9] - 48);

    a.enter_date(d, m, y);

    return a;
}

char lib::string_to_char(std:: string old){
    return old[0];
}

char lib::int_to_char(int old){
    return (old +'0');
}

int lib::return_int(list<int> lista, int one){
    int count;
    list<int> :: iterator it;

    for(it = lista.begin(); it != lista.end();it++){
		//printa os numeros pares
		if(count == one){
            return *it;
        }

        count++;
	}

    return 0;
}

candidato lib::return_candidato(list<candidato> lista, int one){
    int count;
    date a = date();
    string b = "";
    candidato retorno = candidato(0, 0, b, b, b, '0', a, b, 0);
    list<candidato> :: iterator it;

    for(it = lista.begin(); it != lista.end();it++){
		//printa os numeros pares
		if(count == one){
            return *it;
        }

        count++;
	}

    return retorno;
}