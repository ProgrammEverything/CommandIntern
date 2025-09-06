#pragma once
namespace flags{
    enum BI_Flags : int {
        BI_NERROR = 0x1,
        BI_DEBUG  = 0x2,
        BI_VERBOSE= 0x4
    };

    enum T_Type : int{
        EXPRESSION_ASSIGN,
        // Numerical operations
        EXPRESSION_EQUAL,
        EXPRESSION_PLUS,
        EXPRESSION_MINUS,
        EXPRESSION_DIV,
        EXPRESSION_AND,
        EXPRESSION_OR,
        EXPRESSION_NOT,
        // Number operation
        EXPRESSION_NUMBER,
        // End of buffer operation
        EXPRESSION_NPOS,
        // String operation
        EXPRESSION_STRING,
        // Name operation
        EXPRESSION_NAME,
        // End operation ';'
        EXPRESSION_END,
        // Bracket and Parenthesis operations
        EXPRESSION_LBRACK,
        EXPRESSION_RBRACK,
        EXPRESSION_LPAREN,
        EXPRESSION_RPAREN,
        // dot operations
        EXPRESSION_DOT,
        EXPRESSION_DDOT
    };
    struct Token{
        std::string_view data;
        long int size;
        long int current_line;
        long int current_char;
        T_Type type;
        bool opNumerical(){
            return type >= 1 && type<=7;
        }
        bool opEnd(){
            return type == EXPRESSION_END;
        }
        bool opPB(){
            return type >= 13 && type <= 16;
        }
        bool opNumber(){
            return type == EXPRESSION_NUMBER;
        }
        bool opDot(){
            return type >= 17 && type <= 18;
        }
        bool opNPOS(){
            return type==EXPRESSION_NPOS;
        }
        bool opString(){
            return type==EXPRESSION_STRING;
        }
        bool opName(){
            return type=EXPRESSION_NAME;
        }
        bool opAssign(){
            return type==EXPRESSION_ASSIGN;
        }
    };
}