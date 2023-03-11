//
// Created by Truth on 11/03/2023.
//

#include "Converter.h"
#include <iostream>

Converter::Converter(string fileName) {
this->fileName=fileName;
}
void Converter::scanInput() {
    ifstream input;
    input.open(fileName);
    stringstream ss;
    ss << input.rdbuf();
    string all=ss.str();
    vector<string> allNumerals;
    string temp;
    for(unsigned int i=0; i<all.size(); i++){
        if(all[i]=='\n'){
            allNumerals.push_back(temp);
            temp.clear();
        }
        else if (isspace(all[i])) {

        }
        else{
            temp.push_back(all.at(i));
        }
    }

    ofstream output;
    output.open("Output.txt");
    int num;
    for(auto& s:allNumerals){
        num= intoNumber(s);
        output << intoNumber(s) << " " << intoNumerals(num) << endl;
    }
}

string Converter::intoNumerals(int bigNum) {
    vector<Numeral> fullString;
    //list of all the values, biggest to smallest
    vector<Numeral> listNumerals;
    listNumerals.push_back(Numeral('M'));
    listNumerals.push_back(Numeral('D'));
    listNumerals.push_back(Numeral('C'));
    listNumerals.push_back(Numeral('L'));
    listNumerals.push_back(Numeral('X'));
    listNumerals.push_back(Numeral('V'));
    listNumerals.push_back(Numeral('I'));

    bool nothing=false;
    //test every value
    //used an iterative loop to gain access to before and after the current element
    for(unsigned int n=0; n<listNumerals.size(); n++) {
        nothing=false;
        if(bigNum==0){
            break;
        }
        //if the number is 1 to stop problems it has its own thing
        else if(listNumerals[n].getValue()==1&&bigNum<4){
            for(int i=bigNum; i>0; i--) {
                bigNum = bigNum - 1;
                fullString.push_back(listNumerals[n]);
                //cout << listNumerals[n].toString() << " " << bigNum << endl;
            }
        }
        else if(listNumerals[n].getValue()==1&&bigNum==4){
            fullString.push_back(listNumerals[n]);
            fullString.push_back(listNumerals[n-1]);
            //cout << listNumerals[n].toString() << " " << listNumerals[n-1].toString() << " " << bigNum << endl;
        }

        //sees if there is anything that can be done, bool nothing sees if no action was taken the previous loop
        while(bigNum>=listNumerals[n+1].getValue()&&listNumerals[n].getValue()!=1&&!nothing){
            //if it is the number finish
            if(bigNum==listNumerals[n].getValue()){
                fullString.push_back(listNumerals[n]);
                bigNum=bigNum-listNumerals[n].getValue();
                //cout << "Final" << listNumerals[n].toString() << " " << bigNum << endl;
            }

            //next three situations go by if a value can be added going from the biggest to the smallest
            //adds the one after and before
            if(n!=0&&bigNum-(listNumerals[n-1].getValue()-listNumerals[n+1].getValue())>=0){
                int temp=listNumerals[n-1].getValue()-listNumerals[n+1].getValue();
                fullString.push_back(listNumerals[n+1]);
                fullString.push_back(listNumerals[n-1]);
                bigNum = bigNum - temp;
                //cout << listNumerals[n+1].toString() << " " << listNumerals[n-1].toString() << " " << bigNum << endl;
            }
            //adds this one and the one before
            else if(n!=0&&bigNum-(listNumerals[n-1].getValue()-listNumerals[n].getValue())>=0&&listNumerals[n-1].getValue()-listNumerals[n].getValue()!=listNumerals[n].getValue()) {
                int temp = listNumerals[n - 1].getValue() - listNumerals[n].getValue();
                fullString.push_back(listNumerals[n]);
                fullString.push_back(listNumerals[n - 1]);
                bigNum = bigNum - temp;
                //cout << listNumerals[n].toString() << " " << listNumerals[n - 1].toString() << " " << bigNum << endl;
            }
            //just adds this one
            else if(bigNum-listNumerals[n].getValue()>=0) {
                fullString.push_back(listNumerals[n]);
                bigNum = bigNum - listNumerals[n].getValue();
                //cout << listNumerals[n].toString() << " " << bigNum << endl;
            }
            else{
                nothing=true;
            }
        }
        //cout << listNumerals[n].toString() << " Nothing" << endl;


    }
    //convert the vector into a string to output
    string temp;
    for(auto& n:fullString){
        char c=n.toString().at(0);
        temp.push_back(c);
    }
    //cout << bigNum << endl;
    return temp;
}
int Converter::intoNumber(string bigNumeral) {
    //place each character into a Numeral and into a vector
    vector<Numeral> fullString;
    vector<int> addition;
    for(auto& c:bigNumeral){
        Numeral n=Numeral(c);
        fullString.push_back(n);
    }

    //The real work begins here
    //for every level excpet the last read in two at a time
    //using a iteration loop here to gain more control of the two spots
    for(unsigned int i=0; i<fullString.size(); i++){
        //last level just add to addition
        if(i+1==fullString.size()){
            addition.push_back(fullString[i].getValue());
        }
        else {
            //if left is greater than or equal to right
            if (fullString[i].getValue()>=fullString[i+1].getValue()) {
                //add left to addition
                addition.push_back(fullString[i].getValue());
            }
            else {
                //if left is less than right
                //add negative left to addition
                addition.push_back(fullString[i].getValue()*-1);
            }
        }
    }

    //sum the addition
    int temp=0;
    for(auto& a:addition){
        temp=temp+a;
    }

    return temp;

}