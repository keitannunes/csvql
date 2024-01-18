//
// Created by Keitan Nunes on 2024/01/17.
//

#include "Token.h"
#include <utility>
using namespace std;
Token::Token(TokenType type, std::string token, std::any literal, int line) {
    _type = type;
    _token = std::move(token);
    _literal = std::move(literal);
    _line = line;
}

ostream& operator<<(std::ostream &os, const Token &tk) {
    os << "type: " << tk._type << " Token: " << tk._token << " Line: " << tk._line;
    return os;
}
