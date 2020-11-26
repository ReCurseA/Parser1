#include <iostream>

#include "Parser.h"

int main() {
    Parser parser = Parser();
    parser.DtsiToText("pl.dtsi", "Devices.txt");
    return 0;
}
