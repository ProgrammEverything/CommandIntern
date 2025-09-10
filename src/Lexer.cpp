#include "Lexer.h"
#include <string>
#include <iostream>
#include <malloc.h>
flags::Token Lexer::get_token()
{

    if (is_space(m_current_char)) { // If current character is space. skip until the current character is not a space
        consume_whitespace(); // Go until theres no whitespace 
    }
    while (*m_current_char == '\n'){ // If current character is a \n go until theres no \n (newline character)
        next_step();
    }
    switch (*m_current_char){

        case '/':
            if (can_be_next() && *(m_current_char+1) == '/'){
                next_step();
                while (*m_current_char!='\n' && next_step()){}
                if (*m_current_char == '\n' && can_be_next()) {next_step();}
                return get_token();
            } else {
                return make_single_char(flags::EXPRESSION_DIV);
            }
        case '\"': {
            next_step(); // Move past the opening quote to avoid looping
            const char* tkn_start = m_current_char; // Start of actual string content

            while (*m_current_char != '"') {
                if (!next_step()) {
                    throw std::runtime_error("Expected \" at the end of string");
                }
            }

            const char* str_end = m_current_char;
            next_step(); // Move past the closing quote to avoid errors for unmatched string

            return flags::Token{
                std::string_view(tkn_start, str_end - tkn_start),
                str_end - tkn_start,
                flags::Position{m_cchar, m_cchar},
                flags::T_Type::EXPRESSION_STRING
            };
        }
        case '=': 
            if (can_be_next() && *(m_current_char+1) == '='){ // If next character is '=' then return a EXPRESSION_EQUAL
                next_step(); // Consume next turn for the double = 
                return make_single_char(flags::EXPRESSION_EQUAL);
            } else {
                return make_single_char(flags::EXPRESSION_ASSIGN); // If next character isn't '=' or it is at the end of the whole buffer then its a assign operator
            }
        // all one character tokens

        case ';': return make_single_char(flags::EXPRESSION_END);
        case '|': return make_single_char(flags::EXPRESSION_OR);
        case '+': return make_single_char(flags::EXPRESSION_PLUS);
        case '!': return make_single_char(flags::EXPRESSION_NOT);
        case '-': return make_single_char(flags::EXPRESSION_MINUS);
        case '&': return make_single_char(flags::EXPRESSION_AND);
        case '{': return make_single_char(flags::EXPRESSION_LBRACK);
        case '}': return make_single_char(flags::EXPRESSION_RBRACK);
        case '(': return make_single_char(flags::EXPRESSION_LPAREN);
        case ')': return make_single_char(flags::EXPRESSION_RPAREN);
        case '.': return make_single_char(flags::EXPRESSION_DOT);
        case ':': return make_single_char(flags::EXPRESSION_DDOT);
        
        default:
            if (isdigit(*m_current_char)){ // if current character is digit
                const char* start_tkn = m_current_char;
                while (isdigit(*m_current_char) && next_step()){} // read until theres no digit or its at the end of the buffer
                int size = m_current_char-start_tkn;
                return flags::Token{std::string_view(start_tkn, size), size,flags::Position{m_cchar, m_cchar}, flags::T_Type::EXPRESSION_NUMBER}; // make a string_view with data of integer and type number
            } else if (isalpha(*m_current_char) || *m_current_char=='_'){ // If character is a alphabetic character or '_'
                const char* start_tkn = m_current_char;
                while ((isalpha(*m_current_char) || isdigit(*m_current_char) || *m_current_char=='_') && next_step()){} // read until theres no character which is a alphabetic numeral or a '_' or theres no character to read from
                int size = m_current_char-start_tkn;
                return flags::Token{std::string_view(start_tkn, size), size,flags::Position{m_cchar, m_cchar}, flags::T_Type::EXPRESSION_NAME}; // Make a string view with type name and data of the read data
            }
            else if (!can_be_next()){ // If it is at the end of the buffer
                return make_single_char(flags::EXPRESSION_NPOS);
            }
            else { // If theres no character which has been handled
                throw std::runtime_error("Unkown character");
            }
    }
    
}

void Lexer::consume_whitespace()
{
    while (next_step() && is_space(m_current_char)) {}
}

bool Lexer::next_step()
{
    if (++m_pos > m_v.size()){
        return false;
    }
    if (*m_current_char == '\n'){
        m_cline++;
        m_cchar = 0;
    } else {
        m_cchar++;
    }
    m_current_char = &m_v[m_pos];
    return true;
}



bool Lexer::can_be_next()
{
    if (m_pos+1 > m_v.size()){
        return false;
    }
    return true;
}

flags::Token Lexer::make_single_char(flags::T_Type type)
{
    next_step();
    return flags::Token{.size=1, .pos = flags::Position{.current_line = m_cline,.current_char = m_cchar}, .type=type};
}

bool Lexer::is_space(const char *x)
{
    if (*x == ' ') { return true; }
    else {return false;}
}

Lexer::Lexer(std::string_view v) : m_v(v) { m_current_char = &m_v[m_pos]; }
