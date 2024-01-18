//
// Created by Keitan Nunes on 2024/01/17.
//

#include "Scanner.h"

Scanner::Scanner(std::string source) {
    _source = std::move(source);
    start = 0;
    current = 0;
    line = 1;
}
bool Scanner::isAtEnd() {
    return current >= _source.length();
}
void Scanner::addToken(TokenType type, std::optional<std::variant<std::string, int, double>> literal = std::nullopt) {
    tokens.emplace_back(type,_source.substr(start,current-start),std::move(literal), line);
}

char Scanner::advance() {
    return _source[current++];
}

char Scanner::peek() {
    if (isAtEnd()) return '\0';
    return _source[current];
}

char Scanner::peekNext() {
    if (current + 1 >= _source.length()) return '\0';
    return _source[current+1];
}

void Scanner::string() {
    while (peek() != '"' && peek() != '\'' && !isAtEnd()) {
        if (peek() == '\n') line++;
        advance();
    }

    if (isAtEnd()) {
        throw std::invalid_argument("raaa"); //TODO: Real error this
    }
    // The closing ".
    advance();
    // Trim the surrounding quotes.
    TokenType t;
    if (_source[start] == '\'') t = STRING;
    else t = IDENTIFIER;
    addToken(t, _source.substr(start + 1, current - start - 2));
}

bool Scanner::isDigit(const char c) {
    return c >= '0' && c <= '9';
}

// bool Scanner::isDigitNotZero(const char c) {
//     return c >= '1' && c <= '9';
// }

void Scanner::number() {
    TokenType t = INT;
    while (isDigit(peek())) advance();
    if (peek() == '.') {
        t = DOUBLE;
        advance();
        while (isDigit(peek())) advance();
    }
    if (t == INT) {
        addToken(t, std::stoi(_source.substr(start, current - start)));
    } else {
        addToken(t, std::stod(_source.substr(start, current - start)));
    }}

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
            } else if (isDigit(peek())) {
                number();
            } else {
                addToken(OPERATOR_SUB);
            }
            break;
        case '+':
            if (isDigit(peek())) {
                number();
            } else {
                addToken(OPERATOR_SUB);
            }
            break;
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
        case '"':
        case '\'':
            string(); break;
        default:
            if (isDigit(c)) number();
            else throw std::invalid_argument("what"); //TODO: Implement custom exception
    }
}

std::vector<Token> Scanner::scanTokens() {
    while (!isAtEnd()) {
        start = current;
        scanToken();
    }
    return tokens;
}


