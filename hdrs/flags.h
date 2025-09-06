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
        EXPRESSION_NPOS,
        EXPRESSION_STRING,
        EXPRESSION_NAME,
        EXPRESSION_END,
        EXPRESSION_LBRACK,
        EXPRESSION_RBRACK,
        EXPRESSION_LPAREN,
        EXPRESSION_RPAREN,
        EXPRESSION_DIV,
        EXPRESSION_DOT,
        EXPRESSION_DDOT
    };
    struct Token{
        std::string_view data;
        long int size;
        T_Type type;
        bool is_operation(){
            if (type != EXPRESSION_NUMBER ){
                return true;
            }
            return false;
        }
        bool is_number(){
            if (type == EXPRESSION_NUMBER){
                return true;
            }
            return false;
        }
    };
}