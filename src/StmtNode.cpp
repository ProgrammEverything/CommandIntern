#include "StmtNode.h"
#include <iostream>
StmtNode::StmtNode(std::unique_ptr<ArthNode> expr) : m_expr(std::move(expr)) {}
void StmtNode::execute()
{
    m_expr->evaluate();
}
void StmtNode::print(int indents) const
{
    for (int i = 0; i <= indents * 4; i++){
        std::cout << " ";
    }
    std::cout << "StmtNode:\n";
    m_expr->print(indents + 1);
}
void StmtNode::insert_expr(std::unique_ptr<ArthNode> expr)
{
    
}