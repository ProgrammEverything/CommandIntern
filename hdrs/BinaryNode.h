#pragma once
#include <ArthNode.h>
#include <NumberNode.h>
#include <OperatorNode.h>
class BinaryNode : public ArthNode {
private:
    std::unique_ptr<ArthNode> m_lhs;
    std::unique_ptr<OperatorNode> m_ths;
    std::unique_ptr<ArthNode> m_rhs;
public:
    BinaryNode(
        std::unique_ptr<ArthNode> lhs,
        std::unique_ptr<OperatorNode> ths,
        std::unique_ptr<ArthNode> rhs
    );
    double evaluate() override;
    void print(int indents) const override;

};