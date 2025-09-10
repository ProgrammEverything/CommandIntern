#pragma once
#include <memory>
#include <flags.h>
class Node{
public:
    virtual void print(int indents) const = 0;
};