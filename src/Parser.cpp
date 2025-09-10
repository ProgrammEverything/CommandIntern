#include "Parser.h"
#include <string>
#include <NumberNode.h>
#include <BinaryNode.h>
#include <OperatorNode.h>
Parser::Parser(Lexer &lexer) : m_lexer(lexer) {}

StmtNode Parser::parse_statement()
{
    StmtNode stmt(nullptr);
    while (true){
        flags::Token tkn = m_lexer.get_token();
        if (tkn.type == flags::EXPRESSION_END || tkn.type == flags::EXPRESSION_NPOS){
            break;
        }
        // Here we have to make the parser ACTUALLY work. for now we just do the math operations
        if (tkn.type == flags::EXPRESSION_NUMBER){
            
        }
    }
}