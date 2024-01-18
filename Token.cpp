//
// Created by Keitan Nunes on 2024/01/17.
//

#include "Token.h"

#include <utility>
Token::Token(TokenType type, std::string token, std::any literal, int line) {
    _type = type;
    _token = std::move(token);
    _literal = std::move(literal);
    _line = line;

}