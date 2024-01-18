//
// Created by Keitan Nunes on 2024/01/17.
//

#include "Scanner.h"

Scanner::Scanner(std::string source) {
    _source = source;
    start = 0;
    current = 0;
    line = 1;
}
bool Scanner::isAtEnd() {
    return current >= _source.length();
}
void Scanner::addToken(TokenType type, std::any literal = std::any()) {
    tokens.emplace_back(type,_source.substr(start,current-start),std::move(literal), line);
}

char Scanner::advance() {
    return _source[current++];
}

char Scanner::peek() {
    if (isAtEnd()) return '\0';
    return _source[current];
}

void Scanner::scanToken() {
    char c = advance();
    switch (c) {
        case ' ':
        case '\r':
        case '\t':
            break;
        case '\n':
            line++;
            break;
        case '(': addToken(LEFT_PAREN); break;
        case ')': addToken(RIGHT_PAREN); break;
        case ',': addToken(COMMA); break;
        case '.': addToken(DOT); break;
        case '-':
            if (peek() == '-') {
                //comment
                while (peek() != '\n' && !isAtEnd()) advance();
            } else {
                addToken(OPERATOR_SUB);
            }
            break;
        case '+': addToken(OPERATOR_ADD); break;
        case ';': addToken(SEMICOLON); break;
        case '*': addToken(OPERATOR_MUL); break;
        case '%': addToken(OPERATOR_MOD); break;
        case '/': addToken(OPERATOR_DIV); break;
        case '=': addToken(OPERATOR_EQUAL); break;
        case '<':
            switch (peek()) {
                case '>':
                    current++;
                    addToken(OPERATOR_NOT_EQUAL);
                    break;
                case '=':
                    current++;
                    addToken(OPERATOR_LESS_EQUAL);
                    break;
                default:
                    addToken(OPERATOR_LESS);
            }
            break;
        case '>':
            if (peek() == '=') {
                current++;
                addToken(OPERATOR_GREATER_EQUAL);
            }
            else addToken(OPERATOR_GREATER);
            break;
        default:
            throw std::invalid_argument("what"); //TODO: Implement custom exception
    }
}

std::vector<Token> Scanner::scanTokens() {
    while (!isAtEnd()) {
        start = current;
        scanToken();
    }
    return tokens;
}


