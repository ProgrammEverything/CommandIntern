#include "Parser.h"
#include <string>
#include <NumberNode.h>
#include <BinaryNode.h>
#include <OperatorNode.h>
#include <vector>
Parser::Parser(Lexer &lexer) : m_lexer(lexer) {}

std::shared_ptr<StmtNode> Parser::parse_statement()
{
    if (!m_lexer.can_be_next()){
        return nullptr;
    }
    std::vector<std::shared_ptr<ArthNode>> output;
    std::vector<flags::Token> operators;
    while (true){
        flags::Token tkn = m_lexer.get_token();

        // stop when we hit statement terminator
        if (tkn.type == flags::EXPRESSION_END || 
            tkn.type == flags::EXPRESSION_NPOS){
            break;
        }

        if (tkn.opNumber()){
            output.push_back(std::make_shared<NumberNode>(std::stoi(tkn.data.data())));
            continue;
        }
        if (tkn.opNumerical()){
            operators.push_back(tkn);
            continue;
        }

        // handle/ignore other token kinds (parenthesis, unary, etc.) as needed
    }

    // assemble nodes - always check sizes before popping
    while (!operators.empty()){
        if (output.size() < 2){
            // malformed expression: not enough operands for operator
            return nullptr;
        }
        auto op = operators.back();
        operators.pop_back();

        auto right = output.back();
        output.pop_back();
        auto left = output.back();
        output.pop_back();
   
        output.push_back(std::make_shared<BinaryNode>(left, std::make_shared<OperatorNode>(op.type), right));
    }

    if (output.empty()) return nullptr;
    return std::make_shared<StmtNode>(output.back());
}

std::shared_ptr<BlockNode> Parser::parse_all()
{
    auto block = std::make_shared<BlockNode>();
    while (true){
        auto stmt = parse_statement();
        if (stmt){
            block->add_statement(stmt);
        } else {
            break;
        }
    }
    return block;
}

std::vector<flags::Token> Parser::get_token_until(flags::T_Type t)
{
    std::vector<flags::Token> tokens;
    while (true){
        flags::Token tkn = m_lexer.get_token();
        if (tkn.type == t || tkn.type == flags::EXPRESSION_NPOS){
            break;
        }
        tokens.push_back(tkn);
    }
    return tokens;
}
