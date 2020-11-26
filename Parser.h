#ifndef PARSER1_PARSER_H
#define PARSER1_PARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>

class Parser {
public:
    Parser();
    ~Parser();

    void DtsiToText(const std::string &ReadFile, const std::string &WriteFile);

private:
    void ExtractValuesFromLine(std::string line, std::string &nameOfDevice, std::string &address);
};

#endif //PARSER1_PARSER_H
