#include "Lexer.h"
#include <string>
#include <iostream>

flags::Token Lexer::get_token()
{
    while(next_step()){
        if (*current_char == ' '){
            consume_whitespace();
        }
        switch (*current_char){
            case '-':
                return flags::Token{0, flags::EXPRESSION_MINUS};
            case '+':
                return flags::Token{0, flags::EXPRESSION_PLUS};
            case '&':
                return flags::Token{0, flags::EXPRESSION_AND};
            case '|':
                return flags::Token{0, flags::EXPRESSION_OR};
            case '!':
                return flags::Token{0, flags::EXPRESSION_NOT};
            case '=':
                return flags::Token{0, flags::EXPRESSION_EQUAL};
            case '.':
                return flags::Token{0, flags::EXPRESSION_ASSIGN};
            default:
                if (std::isdigit(*current_char)){
                    return flags::Token{(int)*current_char - '0', flags::EXPRESSION_NUMBER};
                } else {
                    throw std::exception();
                }
        }
    }
    return flags::Token{0, flags::EXPRESSION_NPOS};
}

void Lexer::consume_whitespace()
{
    while (next_step() && is_space(current_char)) {}
}

bool Lexer::next_step()
{
    if (pos+1 > m_v.size()){
        return false;
    }
    current_char = &m_v[pos];
    pos++;
    return true;
}

bool Lexer::is_space(const char *x)
{
    if (*x == ' ') { return true; }
    else {return false;}
}
Lexer::Lexer(std::string_view v) : m_v(v) {}
