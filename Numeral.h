//
// Created by Truth on 11/03/2023.
//

#ifndef INTERVIEWCHALLENGE_NUMERAL_H
#define INTERVIEWCHALLENGE_NUMERAL_H
#include <string>

using namespace std;

enum NumeralType{
    I, V, X, L, C, D, M
};

class Numeral {
private:
    int value;
    NumeralType type;

    //these two set the various things
    void setType(char temp);
    void setValue();

public:
    Numeral(char character);
    int getValue();
    string toString();


};


#endif //INTERVIEWCHALLENGE_NUMERAL_H
