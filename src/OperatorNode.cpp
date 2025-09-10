#include "OperatorNode.h"
#include <iostream>
OperatorNode::OperatorNode(flags::T_Type op) : m_op(op) {}

flags::T_Type OperatorNode::evaluate()
{
    std::cout<<"Evaluating OperatorNode: "<<m_op<<"\n";
    return m_op;
}

void OperatorNode::print(int indents) const
{
    
    for (int i = 0; i<=indents*4; i++){
        std::cout<<" ";
    }
    std::cout<<m_op;
    std::cout<<"\n";
}
