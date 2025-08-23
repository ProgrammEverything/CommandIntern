#pragma once
namespace flags{
    enum BI_Flags : int {
        BI_NERROR = 0x1,
        BI_DEBUG  = 0x2,
        BI_VERBOSE= 0x4
    };

    enum T_Type : int{
        EXPRESSION_ASSIGN,
        EXPRESSION_EQUAL,
        EXPRESSION_PLUS,
        EXPRESSION_MINUS,
        EXPRESSION_AND,
        EXPRESSION_OR,
        EXPRESSION_NOT,
        EXPRESSION_NUMBER,
        EXPRESSION_NPOS
    };
    struct Token{
        int val;
        T_Type type;
    };
}