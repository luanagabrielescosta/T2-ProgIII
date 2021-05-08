#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "escrita.hpp"

using namespace std;

escrita::escrita(){
}

bool escrita::escreveArquivo(string path, date dataeleicao, eleicao vereadores) {
    try{
        string line;
        ofstream myfile (path); // ifstream = padrão ios:in
        int bit = 0;

        if (myfile.is_open()){
            myfile << "bolinha" << endl;
            myfile.close();

        } else{ 
            cout << "Unable to open file";
        }
    } catch (invalid_argument& e){
        cerr << e.what() << endl;
        return false;
    }

    return true;
}   
