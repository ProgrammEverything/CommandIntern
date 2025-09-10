#include "NumberNode.h"
#include <iostream>
NumberNode::NumberNode(int number) : m_number(number) {}

void NumberNode::print(int indents) const
{

    for (int i = 0; i<=indents*4; i++){
        std::cout<<" ";
    }
    std::cout<<m_number;
    std::cout<<"\n";
}

double NumberNode::evaluate()
{
    std::cout<<"Evaluating NumberNode: "<<m_number<<"\n";
    return m_number;
}
