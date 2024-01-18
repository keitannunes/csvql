//
// Created by Keitan Nunes on 2024/01/17.
//

#ifndef CSVQL_TOKEN_H
#define CSVQL_TOKEN_H
#include <string>
#include <any>
#include <iostream>


enum TokenType {
//    SQL_ADD,
//    SQL_ADD_CONSTRAINT,
//    SQL_ALL,
//    SQL_ALTER,
//    SQL_ALTER_COLUMN,
//    SQL_ALTER_TABLE,
//    SQL_AND,
//    SQL_ANY,
//    SQL_AS,
//    SQL_ASC,
//    SQL_BACKUP_DATABASE,
//    SQL_BETWEEN,
//    SQL_CASE,
//    SQL_CHECK,
//    SQL_COLUMN,
//    SQL_CONSTRAINT,
//    SQL_CREATE,
//    SQL_CREATE_DATABASE,
//    SQL_CREATE_INDEX,
//    SQL_CREATE_OR_REPLACE_VIEW,
//    SQL_CREATE_TABLE,
//    SQL_CREATE_PROCEDURE,
//    SQL_CREATE_UNIQUE_INDEX,
//    SQL_CREATE_VIEW,
//    SQL_DATABASE,
//    SQL_DEFAULT,
//    SQL_DELETE,
//    SQL_DESC,
//    SQL_DISTINCT,
//    SQL_DROP,
//    SQL_DROP_COLUMN,
//    SQL_DROP_CONSTRAINT,
//    SQL_DROP_DATABASE,
//    SQL_DROP_DEFAULT,
//    SQL_DROP_INDEX,
//    SQL_DROP_TABLE,
//    SQL_DROP_VIEW,
//    SQL_EXEC,
//    SQL_EXISTS,
//    SQL_FOREIGN_KEY,
//    SQL_FROM,
//    SQL_FULL_OUTER_JOIN,
//    SQL_GROUP_BY,
//    SQL_HAVING,
//    SQL_IN,
//    SQL_INDEX,
//    SQL_INNER_JOIN,
//    SQL_INSERT_INTO,
//    SQL_INSERT_INTO_SELECT,
//    SQL_IS_NULL,
//    SQL_IS_NOT_NULL,
//    SQL_JOIN,
//    SQL_LEFT_JOIN,
//    SQL_LIKE,
//    SQL_LIMIT,
//    SQL_NOT,
//    SQL_NOT_NULL,
//    SQL_OR,
//    SQL_ORDER_BY,
//    SQL_OUTER_JOIN,
//    SQL_PRIMARY_KEY,
//    SQL_PROCEDURE,
//    SQL_RIGHT_JOIN,
//    SQL_ROWNUM,
//    SQL_SELECT,
//    SQL_SELECT_DISTINCT,
//    SQL_SELECT_INTO,
//    SQL_SELECT_TOP,
//    SQL_SET,
//    SQL_TABLE,
//    SQL_TOP,
//    SQL_TRUNCATE_TABLE,
//    SQL_UNION,
//    SQL_UNION_ALL,
//    SQL_UNIQUE,
//    SQL_UPDATE,
//    SQL_VALUES,
//    SQL_VIEW,
//    SQL_WHERE,

    //Literals
    NUMBER,
    STRING,
    IDENTIFIER,

    //Operators
    OPERATOR_ADD,
    OPERATOR_SUB,
    OPERATOR_MUL,
    OPERATOR_DIV,
    OPERATOR_MOD,
    OPERATOR_EQUAL,
    OPERATOR_GREATER,
    OPERATOR_GREATER_EQUAL,
    OPERATOR_LESS,
    OPERATOR_LESS_EQUAL,
    OPERATOR_NOT_EQUAL,

    //TODO: Add Bitwise?
    //TODO: Add Compound?

    DOT,
    COMMA,
    LEFT_PAREN,
    RIGHT_PAREN,
    SEMICOLON
};

class Token {
public:
    TokenType _type;
    std::string _token; //token
    std::any _literal; //literal if type is a literal
    int _line; //line where token is located
    Token(TokenType type, std::string token, std::any literal, int line);
    friend std::ostream& operator<<(std::ostream& os, const Token &tk);
};


#endif //CSVQL_TOKEN_H
