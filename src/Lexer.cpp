#include "Lexer.h"
#include <string>
#include <iostream>
#include <malloc.h>
flags::Token Lexer::get_token()
{
    auto make_single_char = [this](flags::T_Type type){
        next_step();
        return flags::Token{.size=1, .type=type};
    };
    while (is_space(current_char)) {
        consume_whitespace();
    }
    switch (*current_char){
        case '\"': {
            next_step(); // Move past the opening quote
            const char* tkn_start = current_char; // Start of actual string content

            while (*current_char != '"') {
                if (!next_step()) {
                    throw std::runtime_error("Expected \" at the end of string");
                }
            }

            const char* str_end = current_char; // Points at the closing quote
            next_step(); // Move past the closing quote

            // The string_view should only include the actual string content
            return flags::Token{
                std::string_view(tkn_start, str_end - tkn_start),
                str_end - tkn_start, // total characters read (including quotes)
                flags::T_Type::EXPRESSION_STRING
            };
        }
        case '=': 
            if (can_be_next() && *(current_char+1) == '='){
                next_step(); // Consume next turn for the double = 
                return make_single_char(flags::EXPRESSION_EQUAL);
            } else {
                return make_single_char(flags::EXPRESSION_ASSIGN);
            }

        case ';': return make_single_char(flags::EXPRESSION_END);
        case '|': return make_single_char(flags::EXPRESSION_OR);
        case '+': return make_single_char(flags::EXPRESSION_PLUS);
        case '!': return make_single_char(flags::EXPRESSION_NOT);
        case '-': return make_single_char(flags::EXPRESSION_MINUS);
        case '&': return make_single_char(flags::EXPRESSION_AND);
        case '{': return make_single_char(flags::EXPRESSION_OBRACKET);
        case '}': return make_single_char(flags::EXPRESSION_CBRACKET);
        case '(': return make_single_char(flags::EXPRESSION_LPAREN);
        case ')': return make_single_char(flags::EXPRESSION_RPAREN);
        
        default:
            if (isdigit(*current_char)){
                const char* start_tkn = current_char;
                while (isdigit(*current_char) && next_step()){}
                int size = current_char-start_tkn;
                return flags::Token{std::string_view(start_tkn, size), size, flags::T_Type::EXPRESSION_NUMBER};
            } else if (isalpha(*current_char) || *current_char=='_'){
                const char* start_tkn = current_char;
                while ((isalpha(*current_char) || isdigit(*current_char) || *current_char=='_') && next_step()){}
                int size = current_char-start_tkn;
                return flags::Token{std::string_view(start_tkn, size), size, flags::T_Type::EXPRESSION_NAME};
            }
            else if (!can_be_next()){
                return make_single_char(flags::EXPRESSION_NPOS);
            }
            else {
                throw std::runtime_error("Unkown character");
            }
    }
    
}

void Lexer::consume_whitespace()
{
    while (next_step() && is_space(current_char)) {}
}

bool Lexer::next_step()
{
    if (++pos > m_v.size()){
        return false;
    }
    current_char = &m_v[pos];
    return true;
}



bool Lexer::can_be_next()
{
    if (pos+1 > m_v.size()){
        return false;
    }
    return true;
}

bool Lexer::is_space(const char *x)
{
    if (*x == ' ') { return true; }
    else {return false;}
}
Lexer::Lexer(std::string_view v) : m_v(v) {current_char=&m_v[pos];}
