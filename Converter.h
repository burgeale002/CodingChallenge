//
// Created by Truth on 11/03/2023.
//

#ifndef INTERVIEWCHALLENGE_CONVERTER_H
#define INTERVIEWCHALLENGE_CONVERTER_H
#include <string>
#include "Numeral.h"
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;


class Converter {
private:
    stringstream bigNumeral;
    vector<string> allNumerals;
    vector<int> allNumbers;
    string fileName;

public:
    Converter(string fileName);

    string intoNumerals(int bigNum);
    int intoNumber(string bigNumeral);

    //this moves the input into bigNumeral
    void  scanInput();
    //this then reads off individual numbers
    string readline();
};


#endif //INTERVIEWCHALLENGE_CONVERTER_H
