#pragma once
#include <string_view>
namespace flags{
    enum BI_Flags : int {
        BI_NERROR = 0x1,
        BI_DEBUG  = 0x2,
        BI_VERBOSE= 0x4
    };

    enum T_Type : int{
        // Assignment operation
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
        EXPRESSION_DDOT,
        // Newline
        EXPRESSION_NEWLINE
    };
    // branch for all calculation stuff
    struct Position{
        long int current_line;
        long int current_char;
    };
    struct Token{
        std::string_view data;
        long int size;
        Position pos;
        T_Type type;
        bool opNumerical(){
            return type == EXPRESSION_PLUS 
            ||     type == EXPRESSION_MINUS 
            ||     type == EXPRESSION_DIV 
            ||     type == EXPRESSION_AND 
            ||     type == EXPRESSION_OR 
            ||     type == EXPRESSION_NOT 
            ||     type == EXPRESSION_EQUAL; 
        }
        bool opEnd(){
            return type == EXPRESSION_END;
        }
        bool opPB(){
            return type >= 13 && type <= 16; // range 13 - 16 is all Paranthesis or Brakcet operations
        }
        bool opNumber(){
            return type == EXPRESSION_NUMBER;
        }
        bool opDot(){
            return type >= 17 && type <= 18; // range 17 - 18 is all Dot and Double Dot operations (DDOT)
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