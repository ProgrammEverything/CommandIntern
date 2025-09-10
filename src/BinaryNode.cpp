#include "BinaryNode.h"
#include <exception>
#include <iostream>
BinaryNode::BinaryNode(
        std::unique_ptr<ArthNode> lhs,
        std::unique_ptr<OperatorNode> ths,
        std::unique_ptr<ArthNode> rhs
) : m_lhs(std::move(lhs)), m_rhs(std::move(rhs)), m_ths(std::move(ths)){}
double BinaryNode::evaluate(){
    std::cout<<"Evaluating BinaryNode\n";
    switch (m_ths->evaluate()){
        case flags::EXPRESSION_PLUS: return m_lhs->evaluate() + m_rhs->evaluate();
        case flags::EXPRESSION_DIV: return m_lhs->evaluate() / m_rhs->evaluate();
        case flags::EXPRESSION_MINUS: return m_lhs->evaluate() - m_rhs->evaluate();
        default:
            throw std::exception();
    }
}
// Add this to BinaryNode.cpp
void BinaryNode::print(int indents) const {
    for (int i = 0; i <= indents * 4; i++){
        std::cout << " ";
    }
    std::cout << "BinaryNode:\n";
    
    m_lhs->print(indents + 1);
    m_ths->print(indents + 1);  
    m_rhs->print(indents + 1);
}
