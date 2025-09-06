#include <iostream>
#include <Lexer.h>
#include <vector>
int main(){
    Lexer a("aaa\n\n\n\n22");
    std::vector<flags::Token> tkn{};
    while (true){
        flags::Token tkn = a.get_token();
        if (tkn.type == flags::EXPRESSION_NPOS ){
            break;
        }
        if (tkn.data == ""){
            tkn.data = "?";
        }
    }
}