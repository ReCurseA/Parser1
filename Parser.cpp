#include "Parser.h"

Parser::Parser() {}

Parser::~Parser() {}

void Parser::DtsiToText(const std::string &ReadFile, const std::string &WriteFile)
{
    std::fstream output(WriteFile.c_str(), std::ios::out);
    output.close();

    std::fstream input(ReadFile.c_str(), std::ios::in);

    std::string line;

    if (input.is_open())
    {
        while (!input.eof())
        {
            std::regex findColon(":", std::regex_constants::ECMAScript | std::regex_constants::icase);
            std::regex findAtSign("@", std::regex_constants::ECMAScript | std::regex_constants::icase);
            while (std::getline(input, line)) {
                if (std::regex_search(line, findColon) && std::regex_search(line, findAtSign)) {
                    std::fstream output(WriteFile.c_str(), std::ios::app);
                    if (output.is_open())
                    {
                        std::string nameOfDevice, address;
                        ExtractValuesFromLine(line, nameOfDevice, address);
                        output << nameOfDevice << " " << address << std::endl;
                    }
                    else
                    {
                        std::cout << "WriteFile isn't open" << std::endl;
                    }
                    output.close();
                }
            }
        }
    }
    else
    {
        std::cout << "ReadFile isn't open" << std::endl;
    }
    input.close();
}

void Parser::ExtractValuesFromLine(std::string line, std::string &nameOfDevice, std::string &address) {
    char symbol;
    int i = 0;
    address = "0x";

    while (line[i] != ':') {
        symbol = line[i];
        if ((line[i] >= 97) && (line[i] <= 122)) {
            symbol -= 32;
        }
        nameOfDevice.push_back(symbol);
        i++;
    }

    while (line[i - 1] != '@')
        i++;

    while (line[i] != ' ') {
        address.push_back(line[i]);
        i++;
    }
}