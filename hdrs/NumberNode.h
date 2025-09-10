#pragma once
#include <ArthNode.h>
class NumberNode : public ArthNode{
private:
    int m_number;
public:
    NumberNode(int number);
    void print(int indents) const override;
    double evaluate() override;
};