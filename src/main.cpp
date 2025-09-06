#include <iostream>
#include <Lexer.h>
#include <vector>
int main(){
    Lexer a("a31232.2 AUTHORIZATION_KEY=20");
    std::vector<flags::Token> tkn{};
    while (true){
        flags::Token tkn = a.get_token();
        if (tkn.type == flags::EXPRESSION_NPOS ){
            break;
        }
        if (tkn.data == ""){
            tkn.data = "?";
        }
        std::cout<<tkn.data<<"\t"<<tkn.type<<"\t"<<tkn.size<<std::endl;
    }
}