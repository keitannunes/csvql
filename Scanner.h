//
// Created by Keitan Nunes on 2024/01/17.
//

#ifndef CSVQL_SCANNER_H
#define CSVQL_SCANNER_H

#include "Token.h"
#include <vector>
#include <string>

class Scanner {
public:
    Scanner(std::string source);
    std::vector<Token> scanTokens();

private:
    std::vector<Token> tokens;
    std::string _source;
    int current;
    int start;
    int line;

    bool isAtEnd();
    void scanToken();
    void addToken(TokenType type, std::any literal);
    char advance();
    char peek();
};


#endif //CSVQL_SCANNER_H
