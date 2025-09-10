#pragma once
#include <Node.h>
class ArthNode : public Node {
public:
    virtual double evaluate() = 0;
};