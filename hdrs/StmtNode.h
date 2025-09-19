#pragma once
#include <ArthNode.h>
class StmtNode : public Node {
public:
    StmtNode(std::shared_ptr<ArthNode> expr);
    virtual void execute();
    void print(int indents) const;
private:
    std::shared_ptr<ArthNode> m_expr;
    
};