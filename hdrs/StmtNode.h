#pragma once
#include <ArthNode.h>
class StmtNode : public Node {
public:
    StmtNode(std::unique_ptr<ArthNode> expr);
    virtual void execute();
    void insert_expr(std::unique_ptr<ArthNode> expr);
private:
    std::unique_ptr<ArthNode> m_expr;
    void print(int indents) const;
};