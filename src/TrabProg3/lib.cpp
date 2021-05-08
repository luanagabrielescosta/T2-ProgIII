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