#include <iostream>
#include <string>
#include "Converter.h"

using namespace std;

int main(int argc, char* argv[]) {
    Converter program=Converter("Input.txt");
    program.scanInput();
}
