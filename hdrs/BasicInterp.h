#pragma once
#include "flags.h"
class BasicInterp {
public:
// Constructors
    BasicInterp() = default;
    BasicInterp(flags::BI_Flags flags);
    BasicInterp(BasicInterp& other);
    BasicInterp(const BasicInterp& other);

//All FLAG Instructions
public:
    bool DoesHaveFlag(flags::BI_Flags r_flag);
    bool SetFlag(flags::BI_Flags r_flag);
    bool RemoveFlag(flags::BI_Flags r_flag);

};