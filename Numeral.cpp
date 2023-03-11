//
// Created by Truth on 11/03/2023.
//

#include "Numeral.h"

//return the numerical value
int Numeral::getValue(){
    return value;
}
Numeral::Numeral(char character) {
    //set its enum value
    setType(character);
    //set its value
    setValue();
}
void Numeral::setType(char temp) {
    if(temp=='I'){
        type=I;
    }
    else if(temp=='V'){
        type=V;
    }
    else if(temp=='X'){
        type=X;
    }
    else if(temp=='L'){
        type=L;
    }
    else if(temp=='C'){
        type=C;
    }
    else if(temp=='D'){
        type=D;
    }
    else if(temp=='M'){
        type=M;
    }
    else{
        //some error statement
    }

}

void Numeral::setValue() {
    if(type==I){
        value=1;
    }
    else if(type==V){
        value=5;
    }
    else if(type==X){
        value=10;
    }
    else if(type==L){
        value=50;
    }
    else if(type==C){
        value=100;
    }
    else if(type==D){
        value=500;
    }
    else if(type==M){
        value=1000;
    }
}
string Numeral::toString() {
    if(type==I){
        return "I";
    }
    else if(type==V){
        return "V";
    }
    else if(type==X){
        return "X";
    }
    else if(type==L){
        return "L";
    }
    else if(type==C){
        return "C";
    }
    else if(type==D){
        return "D";
    }
    else if(type==M){
        return "M";
    }
}


#include "Numeral.h"
