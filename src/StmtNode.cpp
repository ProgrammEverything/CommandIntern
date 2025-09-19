#include "StmtNode.h"
#include <iostream>
StmtNode::StmtNode(std::shared_ptr<ArthNode> expr) : m_expr(expr) {}
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