#pragma once
#include <ArthNode.h>
#include <NumberNode.h>
#include <OperatorNode.h>
class BinaryNode : public ArthNode {
private:
    std::shared_ptr<ArthNode> m_lhs;
    std::shared_ptr<OperatorNode> m_ths;
    std::shared_ptr<ArthNode> m_rhs;
public:
    BinaryNode(
        std::shared_ptr<ArthNode> lhs,
        std::shared_ptr<OperatorNode> ths,
        std::shared_ptr<ArthNode> rhs
    );
    BinaryNode() = default;
    double evaluate() override;
    void print(int indents) const override;

};