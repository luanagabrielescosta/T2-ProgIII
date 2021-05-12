#include "Lib.hpp"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

Lib::Lib(){
}

Lib::~Lib(){
	// TODO Auto-generated destructor stub
}

int Lib::stringToInt(string &old){
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

Date Lib::stringToDate(string &old){
    int d, m, y;
    Date a = Date();

    d = (old[0] - 48) * 10 + (old[1] - 48);
    m = (old[3] - 48) * 10 + (old[4] - 48);
    y = (old[6] - 48) * 1000 + (old[7] - 48) * 100 + (old[8] - 48) * 10 + (old[9] - 48);

    a.enterDate(d, m, y);

    return a;
}

char Lib::stringToChar(string &old){
    return old[0];
}

char Lib::intToChar(int old){
    return (old +'0');
}

int Lib::returnInt(list< int, allocator<int> > &lista, int one){
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

Candidato Lib::returnCandidato(list<Candidato> lista, Candidato &c, int one){
    int count;
    list< Candidato, allocator<Candidato> > :: iterator it;

    for(it = lista.begin(); it != lista.end();it++){
		if(count == one){
            it->printCandidato();
            cout << "ata" << endl;
            c = *it;

            return c;
        }

        count++;
	}

    return c;
}

int Lib::returnPosicao(list<Candidato> lista, string nome){
    int c = 0;
    list< Candidato, allocator<Candidato> > :: iterator it3;

    for(it3 = lista.begin(); it3 != lista.end(); ++it3){
        if(it3->getNomeCandidato().compare(nome) == 0){
            return c;
        }
        c++;
    }
    
    return c;
}