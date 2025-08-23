#pragma once
#include "flags.h"
// BASE CLASS OF ALL HANDLERS
class Handler {
public:
    Handler(flags::BI_Flags flags);
    Handler(Handler& other);
    Handler(const Handler& other);
    
};