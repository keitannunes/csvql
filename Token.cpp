//
// Created by Keitan Nunes on 2024/01/17.
//

#include "Token.h"
#include <utility>
Token::Token(TokenType type, std::string token, std::optional<std::variant<std::string, int, double>> literal, const int line) {
    _type = type;
    _token = std::move(token);
    _literal = std::move(literal);
    _line = line;
}

std::ostream& operator<<(std::ostream &os, const Token &tk) {
    os << "type: " << tk._type << " Token: " << tk._token << " Line: " << tk._line;
    return os;
}