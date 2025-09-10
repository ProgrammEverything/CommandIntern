#pragma once
#include <Node.h>
class OperatorNode : Node {
private:
    flags::T_Type m_op;
public:
    OperatorNode(flags::T_Type op);
    flags::T_Type evaluate();
    void print(int indents) const override;

};
